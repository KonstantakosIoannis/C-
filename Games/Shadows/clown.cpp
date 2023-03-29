#include "clown.h"

void clown::update()
{

}

void clown::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\clown.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

