#include "snake.h"

void snake::update()
{

}

void snake::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\snake.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

