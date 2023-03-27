#pragma once

#include "attack.h"

using namespace std;

class fire : public  attack
{
private:
    float px;
    float py;

    float spx;
    float spy;

    float sizeX = 140;
    float sizeY = 140;

    float radious = 55;

    float tempTime = 0.0f; 
    float rechargeTime = 5500.0f;

    bool fireOn = false; 


public:
    void draw();
    void update();


    void setDragonXY(const float, const float);

    inline float pxGet() const { if (this)return spx-155; }
    inline float pyGet()  const { if (this)return spy+80; }
    inline float getRadious()  const { if (this)return radious; }


};


