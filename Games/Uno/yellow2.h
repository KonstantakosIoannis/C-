#pragma once

#include "gameobject.h"

class yellow2 : public GameObject
{
private:
	char colour = 'y';  // y r g 
	unsigned int number = 2;

public:
	void draw()
	{
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		br.texture = "assets\\png\\twoyellow.png";
		graphics::drawRect(get_x(), get_y(), get_size_x(), get_size_y(), br);
	}

	void update() {}


	unsigned int getNumber() { return this->number; }
	char getColour() { return this->colour; }
};