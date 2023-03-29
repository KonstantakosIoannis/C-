#include "cardBack.h"

void cardBack::update()
{

}

void cardBack::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	
	br.texture = "assets\\\\images\\cards\\backCard.png";

	graphics::drawRect(getX(), getY(), getWidth(), getLength(), br);
	


}



