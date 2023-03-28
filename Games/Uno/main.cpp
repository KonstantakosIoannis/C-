#include "game.h"

void update(float ms)
{
    Game* game = Game::getInstance();
    game->update();
}

void draw()
{
   Game* game = Game::getInstance();
   game->draw();
}

int main()
{
    graphics::createWindow(1200, 800, "U  N  O");
    Game* game = Game::getInstance();
    graphics::playMusic("assets\\music\\mysong.mp3", 0.5f, true);
    graphics::setCanvasSize(28, 16); 
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); 
    graphics::setDrawFunction(draw);  
    graphics::setUpdateFunction(update);
    graphics::startMessageLoop();
    Game::releaseInstance();
    return 0;
}