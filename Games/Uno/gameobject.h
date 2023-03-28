#pragma once
#include "graphics.h"
#include "defines.h"

class GameObject
{
	protected :
		float x=3;   
		float y=13.8;
		float size_x = SIZE_X;
		float size_y = SIZE_Y;

		

	public :
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual unsigned int getNumber() = 0;
		virtual char getColour() = 0;

		void set_x(float x) { this->x = x; }
		void set_y(float y) { this->y = y; }
		float get_x() { return this->x; }
		float get_y() { return this->y; }
		float get_size_x() { return this->size_x; }
		float get_size_y() { return this->size_y; }
		
		bool contains(float x, float y) { return distance(x, y, this->x, this->y)<1.5; }//  1 i ligotero ? i perissotero?
};
