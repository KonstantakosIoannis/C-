#include "captain.h"

void captain::update()
{

}

void captain::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\captain.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

