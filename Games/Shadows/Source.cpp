#include "game.h"

                //   THEORIA  //



// set orientation gia na kanoun peristrofes
// reset pose() h setorientation 0 wste na min paroun tin peristrofi kai ta epomena sximata

//std::this_thread::sleep_for(std::chrono::milliseconds(2000));



void update(float ms)
{
    game* myGame = game::getInsance();
    myGame->update();

    
    
}


void draw()
{
    game* myGame = game::getInsance();
    myGame->draw();
}

int main()
{
    
    graphics::createWindow(1200, 600, "Kostas");

    graphics::setCanvasSize(28, 16);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    //graphics::setFullScreen(true); // to bazw panta fulll screen gia na fainontai
    // kalitera oi kartes



    // poia mpainei prwth
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    

    graphics::startMessageLoop();

    game::release();

    return 0;
}


// i magia tha paizetai mono an iparxei idi teras mou katw ara
// an exw nikisei ton proigoumeno giro

