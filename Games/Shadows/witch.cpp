#include "witch.h"

void witch::update()
{
    
}

void witch::draw()
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\witch.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);
    

}

