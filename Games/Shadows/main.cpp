
#include "game.h"




// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    //graphics::MouseState mouse;
    //graphics::getMouseState(mouse);
    // 
    //if (mouse.button_left_released)
    //{
    //    graphics::playSound("assets\\hit1.wav", 1.0f, false);
    //}



    //1os tropos ilopoihshs
    //game* myGame = (game*)graphics::getUserData();



    //2os tropos ilopoihshs:
    game* myGame = game::getInsance();

    myGame->update();

}


void draw()
{
    //1os tropos ilopoihshs
    //game* myGame = (game*)graphics::getUserData();



    //2os tropos ilopoihshs:
    game* myGame = game::getInsance();

    myGame->draw();
}



int main()
{
    graphics::createWindow(1200, 800, "Soldiers Vs Frogs");




    //1os tropos ilopoihshs :
    // 
    // game* myGame = new game();
    //graphics::setUserData(myGame);

    //2os tropos chech game.h gia minstance
    //game* myGame = game::getInsance();
    //ston deutero tropo exw ena kai monadiko stigmiotipo opote den xreiasomai 
    // kan sti main ton pointer

    graphics::setCanvasSize(28, 16);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);




    // graphics::Brush br;
    //br.fill_color[0] = 0.5f;
    //br.fill_color[1] = 0.7f;
    //br.fill_color[2] = 0.9f;
    // graphics::setWindowBackground(br);

    //graphics::setFont("assets\\orange juice 2.0.ttf");








    graphics::startMessageLoop();

    game::release();
    //mporw epishs na kanw apla delete game

    return 0;
}