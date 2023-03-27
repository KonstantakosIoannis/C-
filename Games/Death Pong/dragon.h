#pragma once

#include "monster.h"

using namespace std;


class dragon : public  monster
{
private:
    
    float px = 800;
    float py = 250;

    float fy = 0.5;
    float fx = 0.5;

    float sizeX = 300;
    float sizeY = 205;

    float hp = 500;   

    float radious = 80;

    // special attack
    float tempTime = 0;  
    float rechargeTime = 0.0f; 

    

public:
    void draw() override;
    void update() override;

    inline float pxGet() const { if (this)return px; }
    inline float pyGet() const { if (this)return py; }
    inline float getRadious() const { if (this) return radious; }
    inline float getHp()  const { if (this)return hp; }

    
    void setHp(const int damage) 
    { 
        if (this) hp = hp - damage;
        if (hp < 0)hp = 0;
    }
    

};