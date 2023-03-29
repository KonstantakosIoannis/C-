#include "dragon.h"

void dragon::update()
{

}

void dragon::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\dragon.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

