#include "health2.h"

void health2::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\spell\\health2.png";

    graphics::drawRect(getx(), gety(), getWidth(), getHeight(), br);
}

void health2::update()
{
}
