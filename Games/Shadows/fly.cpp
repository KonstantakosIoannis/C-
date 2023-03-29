#include "fly.h"

void fly::update()
{

}

void fly::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\fly.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

