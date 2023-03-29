#include "bull.h"

void bull::update()
{

}

void bull::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\bull.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

