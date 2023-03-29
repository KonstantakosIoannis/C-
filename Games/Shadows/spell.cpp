#include "spell.h"

void spell::update()
{

}

void spell::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\spell\\damage1.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

