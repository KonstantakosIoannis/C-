#include "fairy.h"

void fairy::update()
{

}

void fairy::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\fairy.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

