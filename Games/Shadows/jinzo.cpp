#include "jinzo.h"

void jinzo::update()
{

}

void jinzo::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\jinzo.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

