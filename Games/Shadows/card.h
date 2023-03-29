#pragma once

#include "graphics.h"
//#include <string>

#include <iostream>

class card
{	
	private :
		float  x = 7.5;
		float  y = 13;

		float width = 4;
		float length = 4.5;
	
	public :
		virtual void draw() = 0;
		virtual void update() = 0;

		
		float getX() { return this->x; }
		float getY() { return this->y; }
		void  setX(float x) { this->x = x; }
		void  setY(float y) { this->y = y; }

		float getWidth() { return this->width; }
		float getLength() { return this->length; }
		void  setWidth(float x) { this->width = x; }
		void  setLength(float y) { this->length = y; }


		virtual bool big(float x, float y);

		virtual int getHp() = 0;
		virtual int getAttack() = 0;
		virtual void setHp(int hp) = 0;
		virtual void setAttack(int attack) = 0;
		virtual std::string getName() = 0;
		


		inline float distance(float x1, float y1, float x2, float y2)
		{
			float dx = x1 - x2;
			float dy = y1 - y2;
			return sqrtf(dx * dx + dy * dy);
		}

};
