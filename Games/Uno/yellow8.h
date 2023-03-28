#pragma once
#include "gameobject.h"

class yellow8 : public GameObject
{
private:
	char colour = 'y';  // y r g 
	unsigned int number = 8;




public:
	void draw()
	{
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		br.texture = "assets\\png\\eightyellow.png";
		graphics::drawRect(get_x(), get_y(), get_size_x(), get_size_y(), br);
	}

	void update() {}

	unsigned int getNumber() { return this->number; }
	char getColour() { return this->colour; }
};