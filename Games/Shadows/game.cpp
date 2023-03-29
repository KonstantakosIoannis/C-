#include "game.h"

game* game::myInstance = nullptr;


void game::prossEvents()
{
    for (auto e : myEvents)
    {
        e->update();

    }

    myEvents.remove_if([](Event* ev) {return !ev->active(); });
}

void game::addEvent(Event* evt)
{
    myEvents.push_front(evt);
}

void game::draw()
{
    if (myState == boot)
    {
        graphics::Brush br;
        br.outline_opacity = 0.0;
        

        br.texture = "assets\\images\\backgrounds\\loading.png";
        graphics::drawRect(14, 8, 24, 16, br);

        br.fill_color[0] = 1.0;
        br.fill_color[1] = 1.0;
        br.fill_color[2] = 0.5;

        graphics::setFont("assets\\ttfs\\celtic.ttf"); 
        graphics::drawText(8.5, 13.5, 2.2, "Loading . . .",br);
        myState = loading;
        return;
    }


    if (myState == newGame)
    {
        graphics::Brush br;
        br.outline_opacity = 0.0;


        br.texture = "assets\\images\\backgrounds\\main.png";
        graphics::drawRect(14, 8, 24, 16, br);

        
        br.fill_color[0] = 1.0;
        br.fill_color[1] = 1.0;
        br.fill_color[2] = 0.5;

        graphics::setFont("assets\\ttfs\\celtic.ttf");


        graphics::drawText(8.5, 5.5, 1.2, " To  play  press  A", br);
        graphics::drawText(6.5, 15.5, 1.2, "For  instructions  press   B " , br);
        
        return;  
        
    }

    //odigies
    if (myState == instructions)
    {
        graphics::Brush br;
        br.outline_opacity = 0.0;


        br.texture = "assets\\images\\backgrounds\\instru.png";
        graphics::drawRect(14, 8, 24, 16, br);


        br.fill_color[0] = 1.0;//r
        br.fill_color[1] = 1.0;//g
        br.fill_color[2] = 1.;//b

        //graphics::setFont("assets\\ttfs\\cc.ttf");
        graphics::setFont("assets\\ttfs\\tt.ttf");

        // oso pio megalo toso pio deksia - oso pio megalo pio katw - megethos
        graphics::drawText(8.5, 15.5, 1.2, " Press  space  to  go  back", br);
        //graphics::drawText(6.5, 15.5, 1.2, "For  instructions  press   B ", br);


        //odhgies
        graphics::drawText(2.4, 1, 1, "The right number at each card is the Life points  ", br);
        graphics::drawText(2.4, 2, 1, "The left number at each card is the Life points go tot dkjadljfd  ", br);
        return;

    }




    if (myState == win)
    {


        graphics::Brush br;
        br.outline_opacity = 0.0;


        br.texture = "assets\\images\\backgrounds\\win.png";
        graphics::drawRect(14, 8, 24, 16, br);


        br.fill_color[0] = 1.0;
        br.fill_color[1] = 1.0;
        br.fill_color[2] = 0.5;

        graphics::setFont("assets\\ttfs\\celtic.ttf");


        graphics::drawText(6.5, 15.5, 1.2, " Press  space  to  play  again", br);
        

        return;

    }




    if (myState == lose)
    {

        graphics::Brush br;
        br.outline_opacity = 0.0;

        br.texture = "assets\\images\\backgrounds\\lose.png";
        graphics::drawRect(14, 8, 24, 16, br);

        br.fill_color[0] = 1.0;
        br.fill_color[1] = 1.0;
        br.fill_color[2] = 0.5;

        graphics::setFont("assets\\ttfs\\celtic.ttf");

        graphics::drawText(6.5, 15.5, 1.2, " Press  space  to  play  again", br);
        
        return;

    }


        graphics::Brush br;
        br.outline_opacity = 0.0f;
        br.texture = "assets\\images\\backgrounds\\battle.png";
        graphics::drawRect(14, 8, 24, 16, br);


        for (int i = 0; i < 3; i++)
        {
            if (myHand[i])myHand[i]->draw();
            if (myHand[i])myHand[i]->setX(7.5 + i * 6.5);

        }

        for (int i = 0; i < 3; i++)if (opHand[i])opHand[i]->draw();
        

        if (opBattleCard)opBattleCard->draw();
        if (myBattleCard)myBattleCard->draw();


        br.fill_color[0] = 0.95;
        br.fill_color[1] = 0.0;
        br.fill_color[2] = 0.0;

        graphics::setFont("assets\\ttfs\\celtic.ttf");

        
        char stats[20];
        sprintf_s(stats, "%d", oplifepoints);
        graphics::drawText(3, 2, 1.5, stats, br);


        br.fill_color[0] = 0.0;
        br.fill_color[1] = 1.0;
        br.fill_color[2] = 0.0;

        char stats2[20];
        sprintf_s(stats2, "%d", mylifepoints);
        graphics::drawText(3, 14.5, 1.5, stats2, br);
   
    
        for (auto e : myEvents)
        {
            e->draw();
        }
}



















void game::update()
{
    if (myState == boot)
    {
        return;
    }

    if (myState == loading)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        init();
        myState = newGame;
        graphics::playMusic("assets\\sounds\\lobby.wav", 1.0f, true);
        return;
    }

    prossEvents(); 

    if (myState == newGame)
    {
        
        if (graphics::getKeyState(graphics::SCANCODE_A))
        {
            myState = playMe;
            graphics::stopMusic();
            graphics::playSound("assets\\sounds\\duel.wav", 1.0f, false);
           
            graphics::playMusic("assets\\sounds\\lose.wav", 1.0f, true);
        }
        if (graphics::getKeyState(graphics::SCANCODE_B))myState=instructions;
    
    }

    if (myState == instructions)
    {
        if (graphics::getKeyState(graphics::SCANCODE_SPACE))myState = newGame;
    }

    
    if (myState == win)
    {
        
        graphics::playMusic("assets\\sounds\\win.wav", 1.0f, true);
        
        
        
        if (graphics::getKeyState(graphics::SCANCODE_SPACE))myState = loading;
        

        

        for (auto temp : myDeck)
        {
            if (temp.second)delete temp.second;
            temp.second = nullptr;
        }
        myDeck.clear();

        for (auto temp : opDeck)
        {
            if (temp.second)delete temp.second;
            temp.second = nullptr;
        }
        opDeck.clear();

        for (int i = 0; i < 3; i++)
        {
            if (myHand[i])
            {
                delete myHand[i];
                myHand[i] = nullptr;
            }

            if (opHand[i])
            {
                delete  opHand[i];
                opHand[i] = nullptr;
            }
        }

        if (myBattleCard)
        {
            delete myBattleCard;
            myBattleCard = nullptr;
        }

        if (opBattleCard)
        {
            delete opBattleCard;
            opBattleCard = nullptr;
        }
       
        return;
    }

    if (myState == lose)
    {
       
        graphics::playMusic("assets\\sounds\\win.wav", 1.0f, true);
     
        if (graphics::getKeyState(graphics::SCANCODE_SPACE))myState = loading;
        

        

        for (auto temp : myDeck)
        {
            if (temp.second)delete temp.second;
            temp.second = nullptr;
        }
        myDeck.clear();

        for (auto temp : opDeck)
        {
            if (temp.second)delete temp.second;
            temp.second = nullptr;
        }
        opDeck.clear();

        for (int i = 0; i < 3; i++)
        {
            if (myHand[i])
            {
                delete myHand[i];
                myHand[i] = nullptr;
            }

            if (opHand[i])
            {
                delete  opHand[i];
                opHand[i] = nullptr;
            }
        }

        if (myBattleCard)
        {
            delete myBattleCard;
            myBattleCard = nullptr;
        }

        if (opBattleCard)
        {
            delete opBattleCard;
            opBattleCard = nullptr;
        }
    
        return;
    }



    graphics::MouseState myMouse;
    graphics::getMouseState(myMouse);

    float mx = graphics::windowToCanvasX(myMouse.cur_pos_x);
    float my = graphics::windowToCanvasY(myMouse.cur_pos_y);



    if (myState == playMe)
    {
        if (pickCard)
        {
            for (int i = 0; i < 3; i++)
            {
                if (myHand[i] == nullptr)
                {
                    bool y;
                    int x;
                    do {
                        x = rand() % 35;
                        y = false;
                        for (int i = 0; i < burnedCardsPos; i++)
                        {
                            if (burnedCards[i] == x)y = true;

                        }

                    } while (y);

                    myHand[i] = myDeck[x];
                    myDeck[x] = nullptr;
                    burnedCards[burnedCardsPos] = x;
                    burnedCardsPos++;



                    pickCard = false;

                }
            }
        }




        



        for (int i = 0; i < 3; i++)
        {
            if (myHand[i])
            {
                if (myHand[i]->big(mx, my) && myMouse.button_left_released)
                {
                    if (myBattleCard == nullptr)
                    {
                        myBattleCard = myHand[i];
                        myBattleCard->setX(8);
                        myBattleCard->setY(8);
                        myHand[i] = nullptr;
                        graphics::playSound("assets\\sounds\\click.wav", 1.0f, false);
                    }
                    else//mageies
                    {
                        if (myHand[i]->getName() == "spell")
                        {
                            myBattleCard->setHp(myHand[i]->getHp() * (-1));
                            myBattleCard->setAttack(myHand[i]->getAttack());
                        }
                        else myBattleCard->setHp(-1);
                        
                        delete myHand[i];
                        myHand[i] = nullptr;
                        graphics::playSound("assets\\sounds\\click.wav", 1.0f, false);
                    }

                   
                    myState = playOp;
                    playerReady = true;
                    oneTime = true;


                    pickCard = true;


                }
            }
        }


        myTime = graphics::getGlobalTime();

    }

   

    







    if (myState == playOp)
    {
        
        
        if (opBattleCard)
        {
           

            opBattleCard->setHp(-2); 
            addEvent(new HealEvent(opBattleCard->getX(), opBattleCard->getY()));

        }
        else
        {
           
            opBattleCard = opDeck[opBurnedCards[opBurnedCardPos]];
            opDeck[opBurnedCards[opBurnedCardPos]] = nullptr;

            if(opBattleCard)opBattleCard->setX(19.15);
            if(opBattleCard)opBattleCard->setY(8);

            
            bool y;
            int x;
            do {
                x = rand() % 35;
                y = false;
                for (int i = 0; i <(opBurnedCardPos+1); i++)
                {
                    if (opBurnedCards[i] == x)y = true;

                }

            } while (y);
            opBurnedCards[opBurnedCardPos+1] = x;
            opBurnedCardPos++;

        }


       
        
        myState = fire;     
        opReady = true;
        oneTime = true;
        
        myTime = graphics::getGlobalTime(); 
        

    }






    if (myBattleCard)myBattleCard->big(mx, my);
    if (opBattleCard)opBattleCard->big(mx, my);

    
    if (graphics::getGlobalTime() - myTime > 6000)//millsecond
    {
        wait = true;
     
    }

    if (opReady && playerReady&&wait)myState = battle;
    
    
    if (opReady && playerReady&&oneTime)
    {
        
        addEvent(new BattleEvent(13.5, 8));
        oneTime = false;
        
    }






    if (myState == battle)
    {
        
        
        
        

        if (myBattleCard->getAttack() > opBattleCard->getHp())
        {
           
            

            oplifepoints = oplifepoints - (myBattleCard->getAttack() - opBattleCard->getHp());

            if (opBattleCard->getAttack() < myBattleCard->getHp())myBattleCard->setHp(opBattleCard->getAttack());
            else
            {
                addEvent(new FireEvent(myBattleCard->getX(), myBattleCard->getY()));

                mylifepoints = mylifepoints - (opBattleCard->getAttack() - myBattleCard->getHp());
                
                delete myBattleCard;
                myBattleCard = nullptr;

                
            }

            addEvent(new FireEvent(opBattleCard->getX(), opBattleCard->getY()));
            
            delete opBattleCard;
            opBattleCard = nullptr;

            

            

            opReady = false;
            playerReady = false;

            myState = playMe;

        }
        else if (opBattleCard->getAttack() > myBattleCard->getHp())
        {
            

            mylifepoints = mylifepoints - (opBattleCard->getAttack() - myBattleCard->getHp());

            if (myBattleCard->getAttack() < opBattleCard->getHp())opBattleCard->setHp(myBattleCard->getAttack());
            else
            {
                oplifepoints = oplifepoints - (myBattleCard->getAttack() - opBattleCard->getHp());
                
                addEvent(new FireEvent(opBattleCard->getX(), opBattleCard->getY()));
                
                delete opBattleCard;
                opBattleCard = nullptr;

                
            }

            
            addEvent(new FireEvent(myBattleCard->getX(), myBattleCard->getY()));

            delete myBattleCard;
            myBattleCard = nullptr;

            

            opReady = false;
            playerReady = false;

            myState = playMe;

        }
        else if (myBattleCard->getAttack() == opBattleCard->getHp())
        {
            

            if (opBattleCard->getAttack() == myBattleCard->getHp())
            {
                
                addEvent(new FireEvent(myBattleCard->getX(), myBattleCard->getY()));

                delete myBattleCard;
                myBattleCard = nullptr;

                
            }
            else myBattleCard->setHp(opBattleCard->getAttack());

            addEvent(new FireEvent(opBattleCard->getX(), opBattleCard->getY()));
            

            delete opBattleCard;
            opBattleCard = nullptr;

            

            opReady = false;
            playerReady = false;

            myState = playMe;
        }
        else if (opBattleCard->getAttack() == myBattleCard->getHp())
        {
            

            opBattleCard->setHp(myBattleCard->getAttack());


           
            addEvent(new FireEvent(myBattleCard->getX(), myBattleCard->getY()));

            delete myBattleCard;
            myBattleCard = nullptr;

            

            opReady = false;
            playerReady = false;

            myState = playMe;
        }
        else
        {
            if (myBattleCard && opBattleCard)
            {
                
                myBattleCard->setHp(opBattleCard->getAttack());
                opBattleCard->setHp(myBattleCard->getAttack());
            }
        }

        
        wait = false;

       
        if (mylifepoints <= 0 || burnedCardsPos==34)
        {
           
            myState = lose;
            
        }
        
        if (oplifepoints <= 0) 
        {
            graphics::playMusic("assets\\sounds\\win.wav", 1.0f, true);
            myState = win;
            
        }

        
    }



}













void game::init()
{   
    
    
    mylifepoints = 15;
    oplifepoints = 15;

    card * cardWitch = new witch();
    card * cardElf = new elf();
    card * cardSkeleton = new skeleton();
    card * cardClocko = new clocko();
    card * cardDragon = new dragon();
    card * cardGreen = new green();
    card * cardJinzo = new jinzo();
    card * cardKnight = new knight();
    card * cardKuriboh = new kuriboh();
    card * cardMagician = new magician();
    card * cardPenguin = new penguin();
    card * cardNinja = new ninja();
    card * cardReddragon = new reddragon();
    card * cardRobot = new robot();
    card * cardSquirrel = new squirrel();
    card * cardWorm = new worm();
    card * cardSnake = new snake();
    card * cardFly = new fly();
    card * cardDark = new dark();
    card * cardBull = new bull();
    card * cardOrc = new orc();
    card * cardRaider = new raider();
    card * cardFairy = new fairy();
    card * cardSeahorse = new seahorse();
    card * cardMirror = new mirror();
    card * cardClown = new clown();
    card * cardCaptain = new captain();
    card * cardEgg = new egg();
    card * cardFlower = new flower();
    card * cardDeathking = new deathking();
    card * cardMech = new mech();
    card * cardSpell = new spell();
    card * cardSpell2 = new spell2();
    card * cardSpell3 = new spell3();
    card * cardSpell4 = new spell4();


    
    
    myDeck[0] = cardElf;
    myDeck[1] = cardWitch;
    myDeck[2] = cardSkeleton;
    myDeck[3] = cardClocko;
    myDeck[4] = cardDragon;
    myDeck[5] = cardGreen;
    myDeck[6] = cardJinzo;
    myDeck[7] = cardKnight;
    myDeck[8] = cardKuriboh;
    myDeck[9] = cardMagician;
    myDeck[10] = cardPenguin;
    myDeck[11] = cardNinja;
    myDeck[12] = cardReddragon;
    myDeck[13] = cardRobot;
    myDeck[14] = cardSquirrel;
    myDeck[15] = cardWorm;
    myDeck[16] = cardSnake;
    myDeck[17] = cardFly;
    myDeck[18] = cardDark;
    myDeck[19] = cardBull;
    myDeck[20] = cardOrc;
    myDeck[21] = cardRaider;
    myDeck[22] = cardFairy;
    myDeck[23] = cardSeahorse;
    myDeck[24] = cardMirror;
    myDeck[25] = cardClown;
    myDeck[26] = cardCaptain;
    myDeck[27] = cardEgg;
    myDeck[28] = cardFlower;
    myDeck[29] = cardDeathking;
    myDeck[30] = cardMech;
    myDeck[31] = cardSpell;
    myDeck[32] = cardSpell2;
    myDeck[33] = cardSpell3;
    myDeck[34] = cardSpell4;


    //op deck
    card* cardWitch2 = new witch();
    card* cardElf2 = new elf();
    card* cardSkeleton2 = new skeleton();
    card* cardClocko2 = new clocko();
    card* cardDragon2 = new dragon();
    card* cardGreen2 = new green();
    card* cardJinzo2 = new jinzo();
    card* cardKnight2 = new knight();
    card* cardKuriboh2 = new kuriboh();
    card* cardMagician2 = new magician();
    card* cardPenguin2 = new penguin();
    card* cardNinja2 = new ninja();
    card* cardReddragon2 = new reddragon();
    card* cardRobot2 = new robot();
    card* cardSquirrel2 = new squirrel();
    card* cardWorm2 = new worm();
    card* cardSnake2 = new snake();
    card* cardFly2 = new fly();
    card* cardDark2 = new dark();
    card* cardBull2 = new bull();
    card* cardOrc2 = new orc();
    card* cardRaider2 = new raider();
    card* cardFairy2 = new fairy();
    card* cardSeahorse2 = new seahorse();
    card* cardMirror2 = new mirror();
    card* cardClown2 = new clown();
    card* cardCaptain2 = new captain();
    card* cardEgg2 = new egg();
    card* cardFlower2 = new flower();
    card* cardDeathking2 = new deathking();
    card* cardMech2 = new mech();

    card* cardDark2x = new dark();
    card* cardBull2x = new bull();
    card* cardOrc2x= new orc();
    card* cardRaider2x = new raider();

    /*
    card* cardSpellx = new spell();
    card* cardSpell2x = new spell2();
    card* cardSpell3x = new spell3();
    card* cardSpell4x= new spell4();
    */
    opDeck[0] = cardElf2;
    opDeck[1] = cardWitch2;
    opDeck[2] = cardSkeleton2;
    opDeck[3] = cardClocko2;
    opDeck[4] = cardDragon2;
    opDeck[5] = cardGreen2;
    opDeck[6] = cardJinzo2;
    opDeck[7] = cardKnight2;
    opDeck[8] = cardKuriboh2;
    opDeck[9] = cardMagician2;
    opDeck[10] = cardPenguin2;
    opDeck[11] = cardNinja2;
    opDeck[12] = cardReddragon2;
    opDeck[13] = cardRobot2;
    opDeck[14] = cardSquirrel2;
    opDeck[15] = cardWorm2;
    opDeck[16] = cardSnake2;
    opDeck[17] = cardFly2;
    opDeck[18] = cardDark2;
    opDeck[19] = cardBull2;
    opDeck[20] = cardOrc2;
    opDeck[21] = cardRaider2;
    opDeck[22] = cardFairy2;
    opDeck[23] = cardSeahorse2;
    opDeck[24] = cardMirror2;
    opDeck[25] = cardClown2;
    opDeck[26] = cardCaptain2;
    opDeck[27] = cardEgg2;
    opDeck[28] = cardFlower2;
    opDeck[29] = cardDeathking2;
    opDeck[30] = cardMech2;
    opDeck[31] = cardDark2x;
    opDeck[32] = cardBull2x;
    opDeck[33] = cardOrc2x;
    opDeck[34] = cardRaider2x;

    /*
    opDeck[31] = cardSpellx;
    opDeck[32] = cardSpell2x;
    opDeck[33] = cardSpell3x;
    opDeck[34] = cardSpell4x;//35 op (xoris mageies=31) 
    */


    srand(time(NULL));

    for (int i = 0; i < 35; i++)
    {
        burnedCards[i] = -1;
        opBurnedCards[i] = -1;
    }

   
    burnedCards[0] = rand() % 35;  
    do { burnedCards[1] = rand() % 35; } while (burnedCards[1] == burnedCards[0]);
    do { burnedCards[2] = rand() % 35; } while (burnedCards[2] == burnedCards[0] || burnedCards[2] == burnedCards[1]);

    opBurnedCards[0] = rand() % 35;
    opBurnedCardPos =0;
    

    burnedCardsPos = 3;
    
    myHand[0] = myDeck[burnedCards[0]];
    myHand[1] = myDeck[burnedCards[1]];
    myHand[2] = myDeck[burnedCards[2]];
  

    

    
    myDeck[burnedCards[0]] = nullptr;
    myDeck[burnedCards[1]] = nullptr;
    myDeck[burnedCards[2]] = nullptr;

    
    for (int i = 0; i < 3; i++)
    {
        myHand[i]->setX(7.5 + i * 6.5);
    }

    

    
    
    for (int i = 0; i < 3; i++)
    {
        card* cardX = new cardBack();
        opHand[i] = cardX;
        opHand[i]->setX(7.5 + i * 6.5);
        opHand[i]->setY(2.4);
    }



    graphics::preloadBitmaps("assets\\images\\backgrounds");
    graphics::preloadBitmaps("assets\\images\\cards\\monster");
    graphics::preloadBitmaps("assets\\images\\cards\\spell");
   

}


game* game::getInsance()
{
    if (!myInstance) myInstance = new game();
    return myInstance;
}

void game::release()
{
    if (myInstance)
    {
        delete myInstance;
        myInstance = nullptr;
    }
}

game::~game()
{
    for (auto temp : myDeck)
    {
        if (temp.second)delete temp.second;
        temp.second = nullptr;
    }
    myDeck.clear();

    for (auto temp : opDeck)
    {
        if (temp.second)delete temp.second;
        temp.second = nullptr;
    }
    opDeck.clear();

    for (int i = 0; i < 3; i++)
    {
        if (myHand[i])
        {
            delete myHand[i];
            myHand[i] = nullptr;
        }

        if (opHand[i])
        {
            delete  opHand[i];
            opHand[i] = nullptr;
        }
    }

    if (myBattleCard)
    {
        delete myBattleCard;
        myBattleCard = nullptr;
    }

    if (opBattleCard)
    {
        delete opBattleCard;
        opBattleCard = nullptr;
    }
   
}
