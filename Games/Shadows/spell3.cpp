#include "spell3.h"

void spell3::update()
{

}

void spell3::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\spell\\life2.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

