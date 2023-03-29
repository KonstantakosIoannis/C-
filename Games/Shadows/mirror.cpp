#include "mirror.h"

void mirror::update()
{

}

void mirror::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\mirror.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

