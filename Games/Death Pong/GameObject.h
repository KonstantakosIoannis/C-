#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "graphics.h"



class GameObject   // !!ABSTRACT CLASS
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

    virtual ~GameObject() {};


};

