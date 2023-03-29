#include "mech.h"

void mech::update()
{

}

void mech::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\mech.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

