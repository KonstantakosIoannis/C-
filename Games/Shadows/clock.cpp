#include "clock.h"

void clock::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\monster\\clock.png";

    graphics::drawRect(getx(), gety(), getWidth(), getHeight(), br);
}

void clock::update()
{
}
