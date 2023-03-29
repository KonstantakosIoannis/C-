#include "spell2.h"

void spell2::update()
{

}

void spell2::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\spell\\damage2.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);


}

