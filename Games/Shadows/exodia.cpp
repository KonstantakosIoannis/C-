#include "exodia.h"

void exodia::update()
{

}

void exodia::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\exodia.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

