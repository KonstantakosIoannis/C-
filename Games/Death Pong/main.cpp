#include "myGame.h"
#include <thread>

using namespace std::chrono;




void GameMusic()
{
    int song = rand() % 3 + 1;
    if (song == 1)graphics::playMusic("assets\\mySongs\\theme1.mp3", 0.8, true, 5000);
    else if (song == 2)graphics::playMusic("assets\\mySongs\\theme2.mp3", 0.8, true, 5000);
    else graphics::playMusic("assets\\mySongs\\theme3.mp3", 0.8, true, 5000);
}



void update(float ms)
{

    myGame* DeathPongPTR = reinterpret_cast<myGame*>(graphics::getUserData());
    DeathPongPTR->update();


    

   

}


void draw()
{

    myGame* DeathPongPTR = reinterpret_cast<myGame*>(graphics::getUserData());
    DeathPongPTR->draw();
}





int main()
{
    srand(time(NULL)); // arxikopoihsh gia thn sinartisi rand()

    myGame DeathPong;
    


    graphics::createWindow(1200, 600, "DeathPong");   //diastaseis tou parathirou( Diladi 1 pros 2 )
   
    graphics::setCanvasSize(1000, 500); // diastaseis tou kamva
  
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    
    graphics::setUserData(&DeathPong);

    
    thread* tid = new thread (GameMusic); // ksexoristo thread mono gia ti mousiki

    

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    graphics::startMessageLoop();

    // gamemusic thread(gia na trexei oti exei na kanei me ti mousiki se ksexoristo thread)
    tid->join();  
    delete tid;

    return 0;
}

