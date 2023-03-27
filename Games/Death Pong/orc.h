#pragma once

#include "monster.h"

using namespace std;


class orc : public  monster
{
private:
    
    float px = 100;
    float py = 250;

    float sizeX = 130;
    float sizeY = 205;

    float hp = 350;

    float radious = 95;

    bool healOn = false;

    
    float tempTime = 0;
    float rechargeTime = 0.0f;

public:
    void draw() override;
    void update() override;

    inline float pxGet() const { if (this)return px; }
    inline float pyGet() const { if (this)return py; }
    inline float getRadious() const { if (this) return radious; }
    inline float getHp()  const { if (this)return hp; }

   
    void setHp(const float damage)
    { if (this) hp = hp - damage;
    if (hp < 0)hp = 0;
    }

};

