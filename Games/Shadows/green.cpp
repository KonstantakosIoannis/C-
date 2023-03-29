#include "green.h"

void green::update()
{

}

void green::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\green.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

