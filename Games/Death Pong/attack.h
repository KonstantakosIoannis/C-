#pragma once

#include "GameObject.h"

// oles oi epitheseis (kai twn players kai ton antipalwn)
class attack : public  GameObject
{
private:
    float px;
    float py;

    float sixeX;
    float sizeY;

    float radious;

public:
    virtual void draw() = 0;
    virtual void update() = 0;



};