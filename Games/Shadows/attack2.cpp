#include "attack2.h"

void attack2::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\spell\\attack2.png";

    graphics::drawRect(getx(), gety(), getWidth(), getHeight(), br);
}

void attack2::update()
{
}
