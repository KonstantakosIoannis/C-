#include "clocko.h"

void clocko::update()
{

}

void clocko::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\clocko.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

