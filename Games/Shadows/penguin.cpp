#include "penguin.h"

void penguin::update()
{

}

void penguin::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\penguin.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

