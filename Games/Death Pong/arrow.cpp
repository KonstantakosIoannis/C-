#include "arrow.h"


void arrow::setArcherXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void arrow::update()
{


	if (graphics::getGlobalTime() - tempTime > rechargeTime)// tin proth fora tha mpainei panta mesa sto if
	{
		graphics::playSound("assets\\mySongs\\arrow.mp3", 1.0f, false);
		arrowOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx - 6.5;


}

void arrow::draw()
{
	if (arrowOn)
	{
		graphics::Brush myArrow;

		myArrow.texture = "assets//myPics//arrow.png";
		myArrow.outline_opacity = 0.0f;
		graphics::setOrientation(-47);
		graphics::drawRect(spx-70, spy+30, sizeX, sizeY, myArrow);
		graphics::resetPose();

		// diskos gia SIGROUSI  
		myArrow.texture = " ";
		//myArrow.outline_opacity = 1.0f;
		//myArrow.fill_opacity = 0.0f;
		//graphics::drawDisk(spx-70, spy+30, radious, myArrow);
		// otan teliosei i ergasia  na ginei aorato
	}

}