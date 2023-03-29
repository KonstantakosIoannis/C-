#include "worm.h"

void worm::update()
{

}

void worm::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\worm.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

