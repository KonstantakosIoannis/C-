#include "magician.h"

void magician::update()
{

}

void magician::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\magician.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

