#include "raider.h"

void raider::update()
{

}

void raider::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\raider.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

