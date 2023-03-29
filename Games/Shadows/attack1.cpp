#include "attack1.h"

void attack1::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\spell\\attack1.png";

    graphics::drawRect(getx(), gety(), getWidth(), getHeight(), br);
}

void attack1::update()
{
}
