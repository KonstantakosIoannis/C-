#include "dark.h"

void dark::update()
{

}

void dark::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\dark.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

