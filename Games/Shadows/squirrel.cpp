#include "squirrel.h"

void squirrel::update()
{

}

void squirrel::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\squirrel.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

