#pragma once

#include "monster.h"

using namespace std;

class archer : public  monster
{
private:
    
    float px = 800;
    float py = 250;

    float sizeX = 250;
    float sizeY = 205;

    float hp = 300;

    float radious = 70;

    
    float tempTime = 0;  
    float rechargeTime = 0.0f;

    // taxitita kai arxiki kateuthinsi tixaias kinisis
    int fy = 1;

public:
    void draw() override;
    void update() override;

    inline float pxGet() const { if (this)return px; }
    inline float pyGet() const  { if (this)return py; }
    inline float getRadious() const { if (this) return radious; }
    inline float getHp()const { if (this)return hp; }

    
    void setHp(const int damage)
    {
        if (this) hp = hp - damage;
        if (hp < 0)hp = 0;
    }
};
