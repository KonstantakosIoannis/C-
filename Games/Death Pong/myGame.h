#pragma once

#include <stdlib.h>
#include <time.h>
#include <map>

#include "graphics.h"
#include "sorceror.h"
#include "orc.h"
#include "dragon.h"
#include "archer.h"
#include "magic.h"
#include "magic2.h"
#include "arrow.h"
#include "flameArrow.h"
#include "stone.h"
#include "tree.h"
#include "fire.h"
#include "fireball.h"





using namespace std;





class myGame
{
private:

    map <int , GameObject*> objects;

    // collisions 
    bool collision_Magic_Archer();
    bool collision_Magic2_Archer();
    bool collision_Arrow_Sorceror();
    bool collision_flameArrow_Sorceror();
    bool collision_stone_Archer();
    bool collision_Arrow_Orc();
    bool collision_flameArrow_Orc();
    bool collision_tree_Archer();
    bool collision_Magic_Dragon();
    bool collision_Magic2_Dragon();
    bool collision_Stone_Dragon();
    bool collision_Tree_Dragon();

    bool collision_fire_Orc();
    bool collision_fireball_Orc();
    bool collision_fire_Sorceror();
    bool collision_fireball_Sorceror();


    // players and enemies
    sorceror * sorcerorPTR = nullptr;
    orc* orcPTR = nullptr;
    dragon* dragonPTR = nullptr;
    archer* archerPTR = nullptr;
    bool orcOnline = false;
    bool sorcerorOnline = false;
    bool dragonOnline = false;
    bool archerOnline = false;

    // attacks
    magic* magicPTR = nullptr;
    magic2* magic2PTR = nullptr;
    arrow* arrowPTR = nullptr;
    flameArrow* flameArrowPTR = nullptr;
    stone* stonePTR = nullptr;
    tree* treePTR = nullptr;
    fire* firePTR = nullptr;
    fireball* fireballPTR = nullptr;

    bool fireballOnline = false;
    bool treeOnline = false;
    bool arrowOnline = false;
    bool flameArrowOnline = false;
    bool magicOnline = false;
    bool magic2Online = false;
    bool stoneOnline = false;
    bool fireOnline = false;
    
    // monster DEAD
    bool archerDead = false;
    bool sorcerorDead = false;
    bool orcDead = false;
    bool dragonDead = false;

    typedef enum { start, controls, players, arena } screen; // oi 4 othones mou
    typedef enum {orcXX , sorcerorXX} myPlayer; // oi paiktes mou
    typedef enum {archerXX , dragonXX} myEnemy; // oi antipaloi mou

    //sizes buttons
    float controlsSize = 50;
    float playSize = 50;
    float backSize = 50;

    //size sorceror
    float playerSizeXs = 200;
    float playerSizeYs = 350;

    //size orc
    float playerSizeXo = 200;
    float playerSizeYo = 350;
    
    //arxiki othoni
    screen screenOn = start;
    myPlayer myPlayerOn;
    myEnemy myEnemyOn;

    void startScreenDraw();
    void controlsScreenDraw();
    void playersScreenDraw();
    void arenaScreenDraw();
    void startScreenUpdate();
    void controlsScreenUpdate();
    void playersScreenUpdate();
    void arenaScreenUpdate();

    // boithitikes metablites
    bool dragonComingOut = true; // gia na iparxei mia mikri kathisterisi sthn emfanish tou drakou
    float temp; // gia na iparxei mia mikri kathisterisi sthn emfanish tou drakou epishs
    bool youwin = false; // gia na akougete kalitera to sound you win


public:

    myGame();
    ~myGame();

    void draw();
    void update();




};
