#pragma once

#include "attack.h"

using namespace std;

class fireball : public  attack
{
private:
    float px;
    float py;

    float spx;
    float spy;

    float sizeX = 80;
    float sizeY = 80;

    float radious = 40;

    float tempTime = 0.0f; 
    float rechargeTime = 10000.0f; 

    bool fireballOn = false; 

    // tha pigainei san balaki tou ping pong
    int fx = -2.5;
    int fy = 1.5;

public:
    void draw();
    void update();


    void setDragonXY(const float, const float);

    inline float pxGet() const { if (this)return spx-130; }
    inline float pyGet()  const { if (this)return spy+80; }
    inline float getRadious()  const { if (this)return radious; }


};



