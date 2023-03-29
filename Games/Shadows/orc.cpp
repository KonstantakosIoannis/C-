#include "orc.h"

void orc::update()
{

}

void orc::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\orc.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

