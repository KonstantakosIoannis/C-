#include "game.h"

Game* Game::m_instance = nullptr;

Game* Game::getInstance()
{
    if (!m_instance) m_instance = new Game();
    return m_instance;
}

void Game::prossEvents()
{
    for (auto e : m_events)  e->update();
     
    m_events.remove_if([](Event* ev) {return !ev->active(); });
}

void Game::addEvent(Event* evt)
{
    m_events.push_front(evt);
}


void Game::draw()
{
    graphics::Brush br;

    if (m_state == STATE_INIT)
    {
        br.outline_opacity = 0.0f;
        br.texture = "assets\\png\\unoPre.png";
        graphics::drawRect(CAN_WID / 2, CAN_HEI / 2, CAN_WID, CAN_HEI, br);
        graphics::setFont("assets\\orange juice 2.0.ttf");
        graphics::drawText(1 , 2 , 1.5f, "Preload Bitmaps . . . ",br);
        
        m_state = STATE_LOADING;
        return; 
    }

    if (m_state == STATE_HOWTO)//odigies
    {
        br.outline_opacity = 0.0f;
        br.texture = "assets\\png\\howTo.png";
        graphics::drawRect(CAN_WID / 2, CAN_HEI / 2, CAN_WID, CAN_HEI, br);
        graphics::setFont("assets\\orange juice 2.0.ttf");
        br.fill_color[0] = 0.0;
        br.fill_color[1] = 0.0;
        br.fill_color[2] = 0.0;

        graphics::drawText(1, 2, 0.5f, "If you want to fold you have to press ", br);
        graphics::drawText(1, 3, 0.5f, "left click at the UNO face down card ", br);
        graphics::drawText(1, 4, 0.5f, "and the press space  ever evee evev", br);
        graphics::drawText(1, 5, 0.5f, "every time you do it   . .. .  .  j.", br);
        graphics::drawText(1, 6, 0.5f, "every time you do it   . .. .. . . ,  ", br);
        return;
    }


    if (m_state == STATE_FIREWORKS)
    {
        br.outline_opacity = 0.0f;
        br.texture = "assets\\png\\firework.png";
        graphics::drawRect(CAN_WID / 2, CAN_HEI / 2, CAN_WID, CAN_HEI, br);
        graphics::setFont("assets\\orange juice 2.0.ttf");
        br.fill_color[0] = 1.0;
        br.fill_color[1] = 0.5;
        br.fill_color[2] = 0.0;
        graphics::drawText(5, 5, 2.0f, "Press SPACE to play again ", br);
        return;
    }


    br.outline_opacity = 0.0f;
    br.texture = "assets\\png\\unoBackGround.png";
    graphics::drawRect(CAN_WID/2, CAN_HEI/2, CAN_WID, CAN_HEI, br);
    
    if (m_center_card)m_center_card->draw();
    
    for (auto karta : trapoulaUno) if (karta)karta->draw();
    for (auto karta : trapoulaDuo) if (karta)karta->draw();

    for (auto e : m_events) e->draw();
   
    if (wall)
    {
        br.outline_opacity = 0.0f;
        br.texture = "assets\\png\\wood.png";
        graphics::drawRect(3, 3, 50, 5, br);
    }
    else 
    {
        br.outline_opacity = 0.0f;
        br.texture = "assets\\png\\wood.png";
        graphics::drawRect(3, 13, 50, 5, br);
    }
    
    br.fill_color[0] = 0.7;
    br.fill_color[1] = 0.9;
    br.fill_color[2] = 0.4;
    char wins[40];
    sprintf_s(wins, "%d", WINS1);
    graphics::drawText(3, 8, 1.5, wins, br);
    br.fill_color[0] = 0.1;
    br.fill_color[1] = 0.8;
    br.fill_color[2] = 0.7;
    char wins2[40];
    sprintf_s(wins2, "%d", WINS2);
    graphics::drawText(25, 8, 1.5, wins2, br);

    if (Cpaso)Cpaso->draw();

}


void Game::update()
{
 
    m_uno = false;
    m_duo = false;

    if (m_state == STATE_INIT)return;
    
    if (m_state == STATE_LOADING)
    { 
        init();
        m_state = STATE_HOWTO;
        return;
    }

    if (m_state == STATE_HOWTO)
    {
        if (graphics::getKeyState(graphics::SCANCODE_SPACE))
        {
            graphics::playSound("assets\\music\\moirasma.mp3", 1.0f, false);
            m_state = STATE_IDLE;
            

        }
    }

    prossEvents();
    
    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasY(ms.cur_pos_y);
    
    GameObject* cur_card = nullptr;
    for (auto karta : trapoulaUno)
    {
        
        if (karta->contains(mx, my))
        {
            cur_card = karta;

            m_uno = true;
            m_duo = false;    
        }    
    }

    for (auto karta : trapoulaDuo)
    {

        if (karta->contains(mx, my))
        {
            cur_card = karta;

            m_uno = false;
            m_duo = true;
        }
    }

    if (ms.button_left_pressed && cur_card)
    {
        if (m_uno)uno = true;
        else uno = false;

        init_pos_x = mx;
        init_pos_y = my;
        m_active_card = cur_card;

        if (m_active_card->getColour() == m_center_card->getColour() ||
            m_active_card->getNumber() == m_center_card->getNumber() ||
            m_active_card->getColour() == 'x' || m_center_card->getColour() == 'x')
        {
            addEvent(new YesEvent(mx, my));
        }
        else addEvent(new NoEvent(mx, my));
    }

    if (ms.dragging && m_active_card)
    {
        m_state = STATE_MOVING;
        m_active_card->set_x(mx);
        m_active_card->set_y(my);   
    }

    if (ms.button_left_released && m_active_card)
    {
        if (distance(mx, my, m_center_card->get_x(), m_center_card->get_y()) > 0.35)
        {
            m_active_card->set_x(init_pos_x);
            m_active_card->set_y(init_pos_y);
        }
        else
        {  
            if (m_active_card->getColour() == m_center_card->getColour() ||
                m_active_card->getNumber() == m_center_card->getNumber() ||
                m_active_card->getColour() == 'x' || m_center_card->getColour() == 'x')
            {
                if (wall)wall = false;
                else wall = true;
                
                delete m_center_card;
                m_center_card = m_active_card;

                if (uno) trapoulaUno.erase(std::find(trapoulaUno.begin(), trapoulaUno.end(), m_active_card));
                else trapoulaDuo.erase(std::find(trapoulaDuo.begin(), trapoulaDuo.end(), m_active_card));
                
                addEvent(new GlowEvent(m_center_card->get_x(), m_center_card->get_y()));
            }
            else
            {
                m_active_card->set_x(init_pos_x);
                m_active_card->set_y(init_pos_y);
            }
            
        }
        m_state = STATE_IDLE;
        m_active_card = nullptr;
        
        if(m_center_card)m_center_card->set_x(CAN_WID/2);
        if(m_center_card)m_center_card->set_y(CAN_HEI/2);
    }

    if (trapoulaUno.empty()) WINS1++;
    if (trapoulaDuo.empty())WINS2++;

   
    if (epomeno == 1)
    {
        for (auto karta : trapoulaDuo)
        {
            if (karta)delete karta;
        }
        for (auto karta : trapoulaUno)
        {
            if (karta)delete karta;
        }
        for (auto karta : trapoula)
        {
            if (karta)delete karta;
        }
        delete m_center_card;
        m_center_card = nullptr;

        trapoulaUno.clear();
        trapoulaDuo.clear();
        trapoula.clear();

        m_state = STATE_INIT;
    }

    if (trapoulaUno.empty()||trapoulaDuo.empty())
    {
        for (auto karta : trapoulaDuo)
        {
            if(karta)delete karta;
        }
        for (auto karta : trapoulaUno)
        {
            if (karta)delete karta;
        }
        for (auto karta : trapoula)
        {
            if (karta)delete karta;
        }
        delete m_center_card;
        m_center_card = nullptr;

        trapoulaUno.clear();
        trapoulaDuo.clear();
        trapoula.clear();

        m_state = STATE_INIT;  
    }
    
    if (distance(mx, my, Cpaso->get_x(), Cpaso->get_y()) < 1 && ms.button_left_pressed)
    {
        graphics::playSound("assets\\music\\paso.mp3", 1.0f, false);
        m_state = STATE_PASO;
    }

    
   
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)&&m_state==STATE_PASO)
    {
        if (wall)wall = false;
        else wall = true;
        
        if (m_center_card)delete m_center_card;
        m_center_card = trapoula[epomeno];
        trapoula.erase(std::find(trapoula.begin(), trapoula.end(), m_center_card));
        epomeno--;
        m_center_card->set_x(CAN_WID / 2);
        m_center_card->set_y(CAN_HEI / 2);
        m_state = STATE_MOVING;
    }
}

void Game::init()
{
    sleep(1000);
    
    GameObject* Cblue1 = new blue1();
    trapoula.push_back(Cblue1);

    GameObject* Cgreen1 = new green1();
    trapoula.push_back(Cgreen1);

    GameObject* Cyellow1 = new yellow1();
    trapoula.push_back(Cyellow1);

    GameObject* Cred1 = new red1();
    trapoula.push_back(Cred1);

    GameObject* Cblue2 = new blue2();
    trapoula.push_back(Cblue2);

    GameObject* Cyellow2 = new yellow2();
    trapoula.push_back(Cyellow2);

    GameObject* Cgreen2 = new green2();
    trapoula.push_back(Cgreen2);

    GameObject* Cred2 = new red2();
    trapoula.push_back(Cred2);

    GameObject* Cgreen3 = new green3();
    trapoula.push_back(Cgreen3);

    GameObject* Cyellow3 = new yellow3();
    trapoula.push_back(Cyellow3);

    GameObject* Cblue3 = new blue3();
    trapoula.push_back(Cblue3);

    GameObject* Cred3 = new red3();
    trapoula.push_back(Cred3);

    GameObject* Cyellow4 = new yellow4();
    trapoula.push_back(Cyellow4);

    GameObject* Cgreen4 = new green4();
    trapoula.push_back(Cgreen4);

    GameObject* Cblue4 = new blue4();
    trapoula.push_back(Cblue4);

    GameObject* Cred4 = new red4();
    trapoula.push_back(Cred4);

    GameObject* Cgreen5 = new green5();
    trapoula.push_back(Cgreen5);

    GameObject* Cblue5 = new blue5();
    trapoula.push_back(Cblue5);

    GameObject* Cred5 = new red5();
    trapoula.push_back(Cred5);

    GameObject* Cyellow5 = new yellow5();
    trapoula.push_back(Cyellow5);

    GameObject* Cgreen6 = new green6();
    trapoula.push_back(Cgreen6);

    GameObject* Cyellow6 = new yellow6();
    trapoula.push_back(Cyellow6);

    GameObject* Cblue6 = new blue6();
    trapoula.push_back(Cblue6);

    GameObject* Cred6 = new red6();
    trapoula.push_back(Cred6);

    GameObject* Cgreen7 = new green7();
    trapoula.push_back(Cgreen7);
    
    GameObject* Cyellow7 = new yellow7();
    trapoula.push_back(Cyellow7);

    GameObject* Cblue7 = new blue7();
    trapoula.push_back(Cblue7);

    GameObject* Cred7 = new red7();
    trapoula.push_back(Cred7);

    GameObject* Cgreen8 = new green8();
    trapoula.push_back(Cgreen8);

    GameObject* Cyellow8 = new yellow8();
    trapoula.push_back(Cyellow8);

    GameObject* Cblue8 = new blue8();
    trapoula.push_back(Cblue8);

    GameObject* Cred8 = new red8();
    trapoula.push_back(Cred8);

    GameObject* Cgreen9 = new green9();
    trapoula.push_back(Cgreen9);

    GameObject* Cyellow9 = new yellow9();
    trapoula.push_back(Cyellow9);

    GameObject* Cblue9 = new blue9();
    trapoula.push_back(Cblue9);

    GameObject* Cred9 = new red9();
    trapoula.push_back(Cred9);

    GameObject* Cspecial = new special();
    trapoula.push_back(Cspecial);

    Cpaso = new paso();
    Cpaso->set_x(CAN_WID / 2 + 5);
    Cpaso->set_y(CAN_HEI / 2);
    
   
    //trapoula ANAKATEMA
    srand(time(0));
    std::random_shuffle(trapoula.begin(), trapoula.end());

    m_center_card = trapoula[36];
    trapoula.pop_back();

    m_center_card->set_x(CAN_WID/2);
    m_center_card->set_y(CAN_HEI/2);
      
    trapoulaUno.push_back(trapoula[35]);
    trapoulaUno.push_back(trapoula[34]);
    trapoulaUno.push_back(trapoula[33]);
    trapoulaUno.push_back(trapoula[32]);
    trapoulaUno.push_back(trapoula[31]);
    trapoulaUno.push_back(trapoula[30]);

    trapoulaDuo.push_back(trapoula[29]);
    trapoulaDuo.push_back(trapoula[28]);
    trapoulaDuo.push_back(trapoula[27]);
    trapoulaDuo.push_back(trapoula[26]);
    trapoulaDuo.push_back(trapoula[25]);
    trapoulaDuo.push_back(trapoula[24]);
    
    epomeno = 23;

    for (int i = 0; i < 12; i++)trapoula.pop_back();

    for (int i = 0; i < 6; i++)
    {
        trapoulaUno[i]->set_x(i * 4 + 4);
        trapoulaDuo[i]->set_y(2.5);
        trapoulaDuo[i]->set_x(i * 4 + 4);
    }

    graphics::preloadBitmaps("assets\\png\\");
}
