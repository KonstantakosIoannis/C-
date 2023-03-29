#include "reddragon.h"

void reddragon::update()
{

}

void reddragon::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\reddragon.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

