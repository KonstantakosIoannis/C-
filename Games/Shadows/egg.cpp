#include "egg.h"

void egg::update()
{

}

void egg::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\egg.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

