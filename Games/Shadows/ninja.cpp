#include "ninja.h"

void ninja::update()
{

}

void ninja::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\ninja.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

