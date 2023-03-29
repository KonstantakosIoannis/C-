#include "elf.h"

void elf::draw()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    br.texture = "assets\\images\\cards\\monster\\elf.png";

    graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);
}

void elf::update()
{
	
}