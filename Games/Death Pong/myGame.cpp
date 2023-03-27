#pragma once

#include "myGame.h"

using namespace std;

//collisions
bool myGame::collision_fire_Orc()  // an iparxei collision epistrefei true
{ 
    float xx = firePTR->pxGet() - orcPTR->pxGet();
    float yy = firePTR->pyGet() - orcPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - firePTR->getRadious() - orcPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_fireball_Orc()
{
    float xx = fireballPTR->pxGet() - orcPTR->pxGet();
    float yy = fireballPTR->pyGet() - orcPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - fireballPTR->getRadious() - orcPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_fire_Sorceror()
{
    float xx = firePTR->pxGet() - sorcerorPTR->pxGet();
    float yy = firePTR->pyGet() - sorcerorPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - firePTR->getRadious() - sorcerorPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_fireball_Sorceror()
{
    float xx = fireballPTR->pxGet() - sorcerorPTR->pxGet();
    float yy = fireballPTR->pyGet() - sorcerorPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - fireballPTR->getRadious() - sorcerorPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Tree_Dragon()
{
    float xx = treePTR->pxGet() - dragonPTR->pxGet();
    float yy = treePTR->pyGet() - dragonPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - treePTR->getRadious() - dragonPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Stone_Dragon()
{
    float xx = stonePTR->pxGet() - dragonPTR->pxGet();
    float yy = stonePTR->pyGet() - dragonPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - stonePTR->getRadious() - dragonPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Magic2_Dragon()
{
    float xx = magic2PTR->pxGet() - dragonPTR->pxGet();
    float yy = magic2PTR->pyGet() - dragonPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - magic2PTR->getRadious() - dragonPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Magic_Dragon()
{
    float xx = magicPTR->pxGet() - dragonPTR->pxGet();
    float yy = magicPTR->pyGet() - dragonPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - magicPTR->getRadious() - dragonPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_tree_Archer()
{
    float xx = treePTR->pxGet() - archerPTR->pxGet();
    float yy = treePTR->pyGet() - archerPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - treePTR->getRadious() - archerPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Arrow_Orc()
{
    float xx = arrowPTR->pxGet() - orcPTR->pxGet();
    float yy = arrowPTR->pyGet() - orcPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - arrowPTR->getRadious() - orcPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_flameArrow_Orc()
{
    float xx = flameArrowPTR->pxGet() - orcPTR->pxGet();
    float yy = flameArrowPTR->pyGet() - orcPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - flameArrowPTR->getRadious() - orcPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_stone_Archer()
{
    float xx = stonePTR->pxGet() - archerPTR->pxGet();
    float yy = stonePTR->pyGet() - archerPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - stonePTR->getRadious() - archerPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_flameArrow_Sorceror()
{
    float xx = flameArrowPTR->pxGet() - sorcerorPTR->pxGet();
    float yy = flameArrowPTR->pyGet() - sorcerorPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - flameArrowPTR->getRadious() - sorcerorPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}

bool myGame::collision_Arrow_Sorceror()
{
    float xx = arrowPTR->pxGet() - sorcerorPTR->pxGet();
    float yy = arrowPTR->pyGet() - sorcerorPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - arrowPTR->getRadious() - sorcerorPTR->getRadious() < 0)
    {
        return true;

    }
    else return false;
}


bool  myGame::collision_Magic_Archer()
{
    float xx = magicPTR->pxGet() - archerPTR->pxGet();
    float yy = magicPTR->pyGet() - archerPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - magicPTR->getRadious() - archerPTR->getRadious() < 0)
    {
        return true;
        
    }
    else return false;
    
}

bool myGame::collision_Magic2_Archer()
{
    float xx = magic2PTR->pxGet() - archerPTR->pxGet();
    float yy = magic2PTR->pyGet() - archerPTR->pyGet();

    if (sqrt(xx * xx + yy * yy) - magic2PTR->getRadious() - archerPTR->getRadious() < 0)
    {
        return true;
    }
    else return false;
}
//collision END


void myGame::arenaScreenUpdate()
{   //chosen player
    if (myPlayerOn == sorcerorXX)
    {
        if (!sorcerorPTR && !sorcerorOnline)
        {
            sorcerorPTR = new sorceror;
            sorcerorOnline = true; // to bazw true oste na min dimiourgei sinexeia new sorceror
            objects.insert({ 1,sorcerorPTR });
            
        }
        if (sorcerorPTR) sorcerorPTR->update();
    }
    else if (myPlayerOn == orcXX)
    {
        if (!orcPTR && !orcOnline)
        {
            orcPTR = new orc;
            orcOnline = true; // to bazw true oste na min dimiourgei sinexeia new orc
            objects.insert({ 2,orcPTR });
        }

        if (orcPTR) orcPTR->update();
    }




    //prota tha bgainei o archer ki otan pethainei o dragon
    if (archerDead && (!orcDead || !sorcerorDead))
    {
        delete archerPTR;
        delete arrowPTR;
        delete flameArrowPTR;
        archerPTR = nullptr;
        arrowPTR = nullptr;
        flameArrowPTR = nullptr;


        if (dragonComingOut)
        {
            temp = graphics::getGlobalTime();
            dragonComingOut = false;
        }

        if (!dragonPTR && !dragonOnline && (graphics::getGlobalTime() - temp > 1500))
        {
            dragonPTR = new dragon;
            dragonOnline = true;
            objects.insert({ 3,dragonPTR });
        }
        if (dragonPTR) dragonPTR->update();
    }

    //arhcer
    if (!archerPTR && !archerOnline)
    {
        archerPTR = new archer;
        archerOnline = true; 
        objects.insert({ 4,archerPTR });
    }
    if (archerPTR) archerPTR->update();


    //sorceror attacks: 
    if (!magicPTR && !magicOnline && sorcerorOnline)
    {
        magicPTR = new magic;
        magicOnline = true;
        objects.insert({ 5,magicPTR });
    }

    if (magicPTR)
    {
        magicPTR->setSorcerorXY(sorcerorPTR->pxGet() + 45, sorcerorPTR->pyGet() - 60);// dino tis sintetagmenes tou magou stin magic gia na kserei apo pou na ksekinisei na feygei apo to rabdi tou kathe fora
        magicPTR->update();
    }

    if (!magic2PTR && !magic2Online && sorcerorOnline)
    {
        magic2PTR = new magic2;
        magic2Online = true;
        objects.insert({ 6,magic2PTR });
    }

    if (magic2PTR)
    {
        magic2PTR->setSorcerorXY(sorcerorPTR->pxGet() + 45, sorcerorPTR->pyGet() - 60);
        magic2PTR->update();
    }

    //dragon attacks:
    if (!firePTR && !fireOnline && dragonOnline)
    {
        firePTR = new fire;
        fireOnline = true; 
        objects.insert({ 7,firePTR });
    }

    if (firePTR)
    {
        firePTR->setDragonXY(dragonPTR->pxGet() + 45, dragonPTR->pyGet() - 60);
        firePTR->update();
    }
    if (!fireballPTR && !fireballOnline && dragonOnline)
    {
        fireballPTR = new fireball;
        fireballOnline = true; 
        objects.insert({ 8,fireballPTR });
    }

    if (fireballPTR)
    {
        fireballPTR->setDragonXY(dragonPTR->pxGet() + 45, dragonPTR->pyGet() - 60);
        fireballPTR->update();
    }



    //archer attacks: 
    if (!arrowPTR && !arrowOnline && archerOnline)
    {
        arrowPTR = new arrow;
        arrowOnline = true; 
        objects.insert({ 9,arrowPTR });
    }

    if (arrowPTR)
    {
        arrowPTR->setArcherXY(archerPTR->pxGet() + 45, archerPTR->pyGet() - 60);
        arrowPTR->update();
    }
    if (!flameArrowPTR && !flameArrowOnline && archerOnline)
    {
        flameArrowPTR = new flameArrow;
        flameArrowOnline = true; 
        objects.insert({ 10,flameArrowPTR });
    }

    if (arrowPTR)
    {
        flameArrowPTR->setArcherXY(archerPTR->pxGet() + 45, archerPTR->pyGet() - 60);
        flameArrowPTR->update();
    }


    //orc attacks: 
    if (!stonePTR && !stoneOnline && orcOnline)
    {
        stonePTR = new stone;
        stoneOnline = true; 
        objects.insert({ 11,stonePTR });
    }
    if (stonePTR)
    {
        stonePTR->setOrcXY(orcPTR->pxGet() + 45, orcPTR->pyGet() - 60);
        stonePTR->update();
    }
    if (!treePTR && !treeOnline && orcOnline)
    {
        treePTR = new tree;
        treeOnline = true; 
        objects.insert({ 12,treePTR });
    }
    if (treePTR)
    {
        treePTR->setOrcXY(orcPTR->pxGet() + 45, orcPTR->pyGet() - 60);
        treePTR->update();
    }

    //  damages
    if (magicPTR && archerPTR)
    {
        if (collision_Magic_Archer()) archerPTR->setHp(2);  
    }
    if (magic2PTR && archerPTR)
    {
        if (collision_Magic2_Archer())
        {
            archerPTR->setHp(1);  
            sorcerorPTR->setHp(-1);  // blood drain
        }
    }
    if (arrowPTR && sorcerorPTR)
    {
        if (collision_Arrow_Sorceror()) sorcerorPTR->setHp(1.5);  
    }
    if (flameArrowPTR && sorcerorPTR)
    {
        if (collision_flameArrow_Sorceror()) sorcerorPTR->setHp(2.5);  
    }
    if (stonePTR && archerPTR)
    {
        if (collision_stone_Archer()) archerPTR->setHp(1.5);  
    }

    if (arrowPTR && orcPTR)
    {
        if (collision_Arrow_Orc()) orcPTR->setHp(1.5);  
    }
    if (flameArrowPTR && orcPTR)
    {
        if (collision_flameArrow_Orc()) orcPTR->setHp(2.5);  
    }
    if (treePTR && archerPTR)
    {
        if (collision_tree_Archer()) archerPTR->setHp(1.5);  
    }
    if (magicPTR && dragonPTR)
    {
        if (collision_Magic_Dragon()) dragonPTR->setHp(2);
    }
    if (magic2PTR && dragonPTR)
    {
        if (collision_Magic2_Dragon())
        {
            dragonPTR->setHp(1);
            sorcerorPTR->setHp(-1);  // blood drain
        }
    }
    if (stonePTR && dragonPTR)
    {
        if (collision_Stone_Dragon()) dragonPTR->setHp(1.5);
    }
    if (treePTR && dragonPTR)
    {
        if (collision_Tree_Dragon()) dragonPTR->setHp(1.5);
    }
    if (fireballPTR && sorcerorPTR)
    {
        if (collision_fireball_Sorceror()) sorcerorPTR->setHp(0.5);
    }
    if (firePTR && sorcerorPTR)
    {
        if (collision_fire_Sorceror()) sorcerorPTR->setHp(0.75);
    }
    if (fireballPTR && orcPTR)
    {
        if (collision_fireball_Orc()) orcPTR->setHp(0.5);
    }
    if (firePTR && orcPTR)
    {
        if (collision_fire_Orc()) orcPTR->setHp(0.75);
    }




    // otan ftanei to hp sto 0 na psofane
    if (archerPTR->getHp() == 0)archerDead = true;
    if (sorcerorPTR->getHp() == 0)sorcerorDead = true;
    if (orcPTR->getHp() == 0) orcDead = true;
    if (dragonPTR->getHp() == 0)dragonDead = true;

    if (orcDead && !archerDead)
    {
        delete orcPTR;
        delete stonePTR;
        delete treePTR;
        orcPTR = nullptr;
        stonePTR = nullptr;
        treePTR = nullptr;
        objects.erase(2);
        objects.erase(11);
        objects.erase(12);
        

        graphics::playSound("assets//mySongs//youlose.mp3", 1.0f, false);

        //play again
        graphics::MouseState myMouse;
        graphics::getMouseState(myMouse);
        graphics::setFont("assets//myFonts//prince.ttf");

        if (myMouse.cur_pos_x > 484 && myMouse.cur_pos_x < 740 && myMouse.cur_pos_y>495 && myMouse.cur_pos_y < 540 && myMouse.button_left_released)
        {
            screenOn = start;

            orcDead = false;
            orcOnline = false;
            treeOnline = false;
            stoneOnline = false;
            
            archerDead = false;
            archerOnline = false;
            arrowOnline = false;
            flameArrowOnline = false;
            

            delete archerPTR;
            delete arrowPTR;
            delete flameArrowPTR;
            arrowPTR = nullptr;
            flameArrowPTR = nullptr;
            archerPTR = nullptr;

            objects.erase(4);
            objects.erase(9);
            objects.erase(10);

            dragonDead = false;
            dragonOnline = false;

            
        }
        // play again END
    }

    if (sorcerorDead && !archerDead)
    {
        delete sorcerorPTR;
        delete magicPTR;
        delete magic2PTR;
        sorcerorPTR = nullptr;
        magicPTR = nullptr;
        magic2PTR = nullptr;
        objects.erase(1);
        objects.erase(5);
        objects.erase(6);



        graphics::playSound("assets//mySongs//youlose.mp3", 1.0f, false);
        //play again
        graphics::MouseState myMouse;
        graphics::getMouseState(myMouse);
        graphics::setFont("assets//myFonts//prince.ttf");

        if (myMouse.cur_pos_x > 484 && myMouse.cur_pos_x < 740 && myMouse.cur_pos_y>495 && myMouse.cur_pos_y < 540 && myMouse.button_left_released)
        {
            screenOn = start;

            sorcerorDead = false;
            sorcerorOnline = false;
            magicOnline = false;
            magic2Online = false;

            archerDead = false;
            archerOnline = false;
            arrowOnline = false;
            flameArrowOnline = false;


            delete archerPTR;
            delete arrowPTR;
            delete flameArrowPTR;
            arrowPTR = nullptr;
            flameArrowPTR = nullptr;
            archerPTR = nullptr;

            objects.erase(4);
            objects.erase(9);
            objects.erase(10);

            dragonDead = false;
            dragonOnline = false;
        }
        // play again END
    }

    
    if ((sorcerorDead&&orcDead) && !dragonDead)
    {
        delete sorcerorPTR;
        delete magicPTR;
        delete magic2PTR;
        sorcerorPTR = nullptr;
        magicPTR = nullptr;
        magic2PTR = nullptr;
        objects.erase(1);
        objects.erase(5);
        objects.erase(6);
        

        graphics::playSound("assets//mySongs//youlose.mp3", 1.0f, false);
        //play again
        graphics::MouseState myMouse;
        graphics::getMouseState(myMouse);
        graphics::setFont("assets//myFonts//prince.ttf");

        if (myMouse.cur_pos_x > 484 && myMouse.cur_pos_x < 740 && myMouse.cur_pos_y>495 && myMouse.cur_pos_y < 540 && myMouse.button_left_released)
        {
            screenOn = start;

            sorcerorDead = false;
            sorcerorOnline = false;
            magicOnline = false;
            magic2Online = false;

            dragonDead = false;
            dragonOnline = false;
            fireOnline = false;
            fireballOnline = false;


            delete dragonPTR;
            delete firePTR;
            delete fireballPTR;
            firePTR = nullptr;
            fireballPTR = nullptr;
            dragonPTR = nullptr;

            objects.erase(3);
            objects.erase(7);
            objects.erase(8);

            archerDead = false;
            archerOnline = false;
            arrowOnline = false;
            flameArrowOnline = false;


            delete archerPTR;
            delete arrowPTR;
            delete flameArrowPTR;
            arrowPTR = nullptr;
            flameArrowPTR = nullptr;
            archerPTR = nullptr;

            objects.erase(4);
            objects.erase(9);
            objects.erase(10);
        }
        // play again END
    }

    if (orcDead && !dragonDead)
    {
        
        delete orcPTR;
        delete treePTR;
        delete stonePTR;
        stonePTR = nullptr;
        treePTR = nullptr;
        orcPTR = nullptr;
        objects.erase(2);
        objects.erase(11);
        objects.erase(12);

        graphics::playSound("assets//mySongs//youlose.mp3", 1.0f, false);
        //play again
        graphics::MouseState myMouse;
        graphics::getMouseState(myMouse);
        graphics::setFont("assets//myFonts//prince.ttf");

        if (myMouse.cur_pos_x > 484 && myMouse.cur_pos_x < 740 && myMouse.cur_pos_y>495 && myMouse.cur_pos_y < 540 && myMouse.button_left_released)
        {
            screenOn = start;

            orcDead = false;
            orcOnline = false;
            stoneOnline = false;
            treeOnline = false;

            dragonDead = false;
            dragonOnline = false;
            fireOnline = false;
            fireballOnline = false;


            delete dragonPTR;
            delete firePTR;
            delete fireballPTR;
            firePTR = nullptr;
            fireballPTR = nullptr;
            dragonPTR = nullptr;

            objects.erase(3);
            objects.erase(7);
            objects.erase(8);

            archerDead = false;
            archerOnline = false;
            arrowOnline = false;
            flameArrowOnline = false;


            delete archerPTR;
            delete arrowPTR;
            delete flameArrowPTR;
            arrowPTR = nullptr;
            flameArrowPTR = nullptr;
            archerPTR = nullptr;

            objects.erase(4);
            objects.erase(9);
            objects.erase(10);
        }
        // play again END
    }


    //you win
    if ((dragonDead&&archerDead) && (!sorcerorDead || !orcDead))
    {
        delete dragonPTR;
        delete firePTR;
        delete fireballPTR;
        dragonPTR = nullptr;
        firePTR = nullptr;
        fireballPTR = nullptr;
        objects.erase(3);
        objects.erase(7);
        objects.erase(8);
        

        if (!youwin)
        {
            graphics::playSound("assets//mySongs//youwin.mp3", 1.0f, true);
            youwin = true;
        }
       
    }

}

void myGame::arenaScreenDraw()
{
    graphics::Brush Background;

    Background.texture = "assets//myPics//arena.png";

    graphics::drawRect(500, 250, 1000, 500, Background);
    
    

    // my players
    if (myPlayerOn == sorcerorXX)
    {
        if (sorcerorPTR) sorcerorPTR->draw();
    }
    else if (myPlayerOn == orcXX)
    {
        if (orcPTR) orcPTR->draw();
    }
    
    // my enemies
    if (dragonPTR) dragonPTR->draw();
    if (archerPTR) archerPTR->draw();

    //my attacks
    if (magicPTR)magicPTR->draw();
    if (magic2PTR)magic2PTR->draw();
    if (arrowPTR)arrowPTR->draw();
    if (flameArrowPTR)flameArrowPTR->draw();
    if (stonePTR)stonePTR->draw();
    if (treePTR)treePTR->draw();
    if (firePTR)firePTR->draw();
    if (fireballPTR)fireballPTR->draw();

    //you lose
    if ((sorcerorDead||orcDead) && !archerDead)
    {
        Background.fill_color[0] = 0.0f;
        Background.fill_color[1] = 0.45f;
        Background.fill_color[2] = 0.0f;
        Background.fill_opacity = 0.7;
        Background.fill_secondary_color[0] = 0.0f;
        Background.fill_secondary_color[1] = 0.0f;
        Background.fill_secondary_color[2] = 0.0f;
        Background.fill_secondary_opacity = 1.0f;
        Background.gradient = true;
        Background.gradient_dir_u = 0.04;
        Background.gradient_dir_v = 1.04;

        graphics::drawText(100, 250, 90, "You  Lose", Background);
        graphics::drawText(400, 450, 50, "Play Again ", Background);
        graphics::setFont("assets//myFonts//prince.ttf");
    }

    if ((sorcerorDead&&orcDead)&& !dragonDead)
    {
        Background.fill_color[0] = 0.0f;
        Background.fill_color[1] = 0.45f;
        Background.fill_color[2] = 0.0f;
        Background.fill_opacity = 0.7;
        Background.fill_secondary_color[0] = 0.0f;
        Background.fill_secondary_color[1] = 0.0f;
        Background.fill_secondary_color[2] = 0.0f;
        Background.fill_secondary_opacity = 1.0f;
        Background.gradient = true;
        Background.gradient_dir_u = 0.04;
        Background.gradient_dir_v = 1.04;

        graphics::drawText(100, 250, 90, "You  Lose", Background);
        graphics::drawText(400, 450, 50, "Play Again ", Background);
        graphics::setFont("assets//myFonts//prince.ttf");
    }
    

    //you win
    if ((dragonDead&&archerDead) && (!orcDead||!sorcerorDead))
    {
        Background.fill_color[0] = 0.0f;
        Background.fill_color[1] = 0.45f;
        Background.fill_color[2] = 0.0f;
        Background.fill_opacity = 0.7;
        Background.fill_secondary_color[0] = 0.0f;
        Background.fill_secondary_color[1] = 0.0f;
        Background.fill_secondary_color[2] = 0.0f;
        Background.fill_secondary_opacity = 1.0f;
        Background.gradient = true;
        Background.gradient_dir_u = 0.04;
        Background.gradient_dir_v = 1.04;

        graphics::drawText(550, 250, 90, "You  Win", Background);
        graphics::setFont("assets//myFonts//prince.ttf");
    }
    
}











void myGame::playersScreenUpdate()
{
    graphics::MouseState myMouse;
    graphics::getMouseState(myMouse);
    //sorceror size up
    if (myMouse.cur_pos_x > 110 && myMouse.cur_pos_x < 290 && myMouse.cur_pos_y>65 && myMouse.cur_pos_y < 470&&myMouse.button_left_released)
    {
        playerSizeXs = playerSizeXs + 40;
        playerSizeYs = playerSizeYs + 40; 
        myPlayerOn = sorcerorXX;
        graphics::playSound("assets\\mySongs\\sorcerorLaugh.mp3", 0.9f, false);
        

        playerSizeXo = 200;
        playerSizeYo = 350;
    }
    
    if (playerSizeXs > 240)playerSizeXs = 240;
    if (playerSizeYs > 390)playerSizeYs = 390;



    //orc size up
    if (myMouse.cur_pos_x > 885 && myMouse.cur_pos_x < 1065 && myMouse.cur_pos_y>65 && myMouse.cur_pos_y < 470&&myMouse.button_left_released)
    {
        playerSizeXo = playerSizeXo + 40;
        playerSizeYo = playerSizeYo + 40;
        myPlayerOn = orcXX;
        graphics::playSound("assets\\mySongs\\orcRoar.mp3", 0.9f, false);

        playerSizeXs = 200;
        playerSizeYs = 350;

    }
   
    if (playerSizeXo > 240)playerSizeXo = 240;
    if (playerSizeYo > 390)playerSizeYo = 390;

   



    //back bottom  size up
    if (myMouse.cur_pos_x > 528 && myMouse.cur_pos_x < 640 && myMouse.cur_pos_y>253 && myMouse.cur_pos_y < 300)
    {
        backSize = backSize + 20;
    }
    else
    {
        backSize = 50;
    }
    if (backSize > 71)backSize = 70;
    
    if (myMouse.cur_pos_x > 528 && myMouse.cur_pos_x < 640 && myMouse.cur_pos_y>253 && myMouse.cur_pos_y < 300 && myMouse.button_left_released)
    {
        screenOn = start;
    }


    //play bottom  size up
    if (myMouse.cur_pos_x > 504 && myMouse.cur_pos_x < 654 && myMouse.cur_pos_y>468 && myMouse.cur_pos_y < 540)
    {
        playSize = playSize + 20;
    }
    else
    {
        playSize= 50;
    }
    if (playSize > 71)playSize = 70;

    if (myMouse.cur_pos_x > 504 && myMouse.cur_pos_x < 654 && myMouse.cur_pos_y>468 && myMouse.cur_pos_y < 540 && myMouse.button_left_released)
    {
        screenOn = arena;
    }
}


void myGame::playersScreenDraw()
{
    graphics::Brush Background;

    Background.texture = "assets//myPics//players.png";

    graphics::drawRect(500, 250, 1000, 500, Background);

    Background.texture= "assets//myPics//sorceror.png";
    Background.outline_opacity = 0.0f;
    graphics::drawRect(180, 220, playerSizeXs, playerSizeYs, Background);

    Background.texture = "assets//myPics//orc.png";
    Background.outline_opacity = 0.0f;
    graphics::drawRect(800, 220, playerSizeXo, playerSizeYo, Background);

    

    Background.fill_color[0] = 1.0f;
    Background.fill_color[1] = 0.7f;
    Background.fill_color[2] = 0.0f;
    Background.fill_opacity = 0.7;
    Background.fill_secondary_color[0] = 0.0f;
    Background.fill_secondary_color[1] = 0.0f;
    Background.fill_secondary_color[2] = 0.0f;
    Background.fill_secondary_opacity = 1.0f;
    Background.gradient = true;
    Background.gradient_dir_u = 0.04;
    Background.gradient_dir_v = 1.04;

    graphics::drawText(440, 250, backSize, "Back", Background);
    graphics::drawText(440, 450, playSize, "Play", Background);

    graphics::setFont("assets//myFonts//prince.ttf");


}











void myGame::controlsScreenDraw()
{
    
    graphics::Brush Background;

    Background.texture = "assets//myPics//controls.png";

    graphics::drawRect(500, 250, 1000, 500, Background);

    Background.fill_color[0] = 1.0f;
    Background.fill_color[1] = 0.7f;
    Background.fill_color[2] = 0.0f;
    Background.fill_opacity = 0.7;
    Background.fill_secondary_color[0] = 0.0f;
    Background.fill_secondary_color[1] = 0.0f;
    Background.fill_secondary_color[2] = 0.0f;
    Background.fill_secondary_opacity = 1.0f;
    Background.gradient = true;
    Background.gradient_dir_u = 0.04;
    Background.gradient_dir_v = 1.04;

    graphics::drawText(850, 450, backSize, "Back", Background);

    Background.fill_color[0] = 0.75f;
    Background.fill_color[1] = 0.0f;
    Background.fill_color[2] = 0.0f;
    Background.fill_opacity = 0.7;
    Background.fill_secondary_color[0] = 0.0f;
    Background.fill_secondary_color[1] = 0.0f;
    Background.fill_secondary_color[2] = 0.0f;
    Background.fill_secondary_opacity = 1.0f;
    //Background.gradient = true;   einai idi true
    Background.gradient_dir_u = 0.04;
    Background.gradient_dir_v = 1.04;

    graphics::drawText(35, 50, 25, "To  play  this  game  you  need  a  keyboard . ", Background);
    graphics::drawText(35, 80, 25, "To  move  your  player  you  could  use  the  cross  or  the  'AWSD'   keys. ", Background);
    graphics::drawText(35, 110, 25, "Every  player  has  two  different  attacks  and  one  special  ability.",Background);
    graphics::drawText(35, 150, 25, "Attack  1  :  'z'   or   1", Background);
    graphics::drawText(35, 180, 25, "Attack  2  :  'c'   or   3", Background);
    graphics::drawText(35, 210, 25, "Special    :  'x'   or   2", Background);
    graphics::drawText(35, 250, 25, "Every attack needs some time to recharge.", Background);


    graphics::drawText(35, 350, 25, "Status : ", Background);
    graphics::drawText(35, 380, 25, "Orc  has  350 HP  and  40  Attack Points. ", Background);
    graphics::drawText(35, 410, 25, "Sorceror  has  200 HP  and  80 Attack  Points.", Background);


    graphics::setFont("assets//myFonts//prince.ttf");

    




   
}

void myGame::controlsScreenUpdate()
{
    graphics::MouseState myMouse;
    graphics::getMouseState(myMouse);

    if (myMouse.cur_pos_x > 1020 && myMouse.cur_pos_x < 1134 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535) backSize = backSize + 20;
    else backSize = 50;
    if (backSize > 71)backSize = 71;

    if (myMouse.cur_pos_x > 1020 && myMouse.cur_pos_x < 1134 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535 && myMouse.button_left_released) screenOn = start;


}









void myGame::startScreenDraw()
{
    
    graphics::Brush Background;

    Background.texture = "assets//myPics//start.png";

    graphics::drawRect(500, 250, 1000, 500, Background);

    

    Background.fill_color[0] = 1.0f;
    Background.fill_color[1] = 0.7f;
    Background.fill_color[2] = 0.0f;
    Background.fill_opacity = 0.7;
    Background.fill_secondary_color[0] = 0.0f;
    Background.fill_secondary_color[1] = 0.0f;
    Background.fill_secondary_color[2] = 0.0f;
    Background.fill_secondary_opacity = 1.0f;
    Background.gradient = true;
    Background.gradient_dir_u = 0.04;
    Background.gradient_dir_v = 1.04;



    graphics::drawText(340, 100, 70, "Death  Pong", Background);


   
    graphics::drawText(50, 450, controlsSize, "Controls", Background);
    graphics::drawText(850, 450, playSize, "Play", Background);

    graphics::setFont("assets//myFonts//prince.ttf");


}

void myGame::startScreenUpdate()
{   
    
    graphics::MouseState myMouse;
    graphics::getMouseState(myMouse);
    
    //controls button size up
    if (myMouse.cur_pos_x > 61 && myMouse.cur_pos_x < 300 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535) controlsSize = controlsSize + 20;
    else controlsSize = 50;
    if (controlsSize > 71)controlsSize = 71;

    if (myMouse.cur_pos_x > 61 && myMouse.cur_pos_x < 300 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535 && myMouse.button_left_released) screenOn = controls;
    
    // play button size up
    if (myMouse.cur_pos_x > 1020 && myMouse.cur_pos_x < 1134 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535) playSize = playSize + 20;
    else playSize = 50;
    if (playSize > 71)playSize = 71;

    if (myMouse.cur_pos_x > 1020 && myMouse.cur_pos_x < 1134 && myMouse.cur_pos_y>487 && myMouse.cur_pos_y < 535 && myMouse.button_left_released) screenOn = players;
    
    
}






myGame::~myGame()
{
   // delete the whole map(every game object - players and attacks)
    objects.clear();
}

myGame::myGame()
{

}

void myGame::update()
{
    
    if (screenOn == start)startScreenUpdate();
    else if (screenOn == controls) controlsScreenUpdate();
    else if (screenOn == players)playersScreenUpdate();
    else arenaScreenUpdate();
    
}

void myGame::draw()
{
    if (screenOn == start) startScreenDraw();
    else if (screenOn == controls) controlsScreenDraw();
    else if (screenOn == players) playersScreenDraw();
    else arenaScreenDraw();


    


}
