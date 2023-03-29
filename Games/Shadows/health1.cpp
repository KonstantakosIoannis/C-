#include "health1.h"

void health1::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\spell\\health1.png";

    graphics::drawRect(getx(), gety(), getWidth(), getHeight(), br);
}

void health1::update()
{
}
