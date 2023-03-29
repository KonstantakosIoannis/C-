#include "spell4.h"

void spell4::update()
{

}

void spell4::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\spell\\life3.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

