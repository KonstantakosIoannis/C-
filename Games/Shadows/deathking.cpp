#include "deathking.h"

void deathking::update()
{

}

void deathking::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\deathking.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

