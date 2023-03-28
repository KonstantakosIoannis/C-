#pragma once

#include "gameobject.h"

class blue5 : public GameObject
{
private:
	char colour = 'b';  // y r g 
	unsigned int number = 5;

public:
	void draw()
	{
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		br.texture = "assets\\png\\fiveblue.png";
		graphics::drawRect(get_x(), get_y(), get_size_x(), get_size_y(), br);
	}

	void update() {}

	unsigned int getNumber() { return this->number; }
	char getColour() { return this->colour; }
};