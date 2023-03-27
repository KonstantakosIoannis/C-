#pragma once

#include "GameObject.h"

// kai oi paiktes mou kai oi antipaloi tha nai tipou monster
class monster : public  GameObject
{
private:
    float px;
    float py;

    float sixeX;
    float sizeY;

    float radious;
    

    float hp;

public:
    virtual void draw() = 0;
    virtual void update() = 0;

};