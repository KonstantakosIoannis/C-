#include "kuriboh.h"

void kuriboh::update()
{

}

void kuriboh::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\kuriboh.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

