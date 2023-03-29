#include "knight.h"

void knight::update()
{

}

void knight::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\knight.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

