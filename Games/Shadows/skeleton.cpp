#include "skeleton.h"

void skeleton::update()
{

}

void skeleton::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\skeleton.png";


    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

