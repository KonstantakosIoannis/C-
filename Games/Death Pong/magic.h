#pragma once

#include "attack.h"

using namespace std;

class magic : public  attack
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
    float rechargeTime = 5000.0f; 

    bool magicOn = false; 
    

public:
    void draw() ;
    void update() ;


    void setSorcerorXY(const float , const  float );

    inline float pxGet()  const { if (this)return spx; }
    inline float pyGet() const { if (this)return spy; }
    inline float getRadious() const { if (this)return radious; }

   
};
