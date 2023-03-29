#include "flower.h"

void flower::update()
{

}

void flower::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\flower.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

