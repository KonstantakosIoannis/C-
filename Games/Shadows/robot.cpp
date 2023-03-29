#include "robot.h"

void robot::update()
{

}

void robot::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\robot.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

