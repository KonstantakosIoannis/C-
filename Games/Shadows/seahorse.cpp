#include "seahorse.h"

void seahorse::update()
{

}

void seahorse::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\seahorse.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

