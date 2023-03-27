#include "flameArrow.h"


void flameArrow::setArcherXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void flameArrow::update()
{


	if (graphics::getGlobalTime() - tempTime > rechargeTime)
	{
		graphics::playSound("assets\\mySongs\\flame_arrow.mp3", 1.0f, false);
		flameArrowOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx - 2.5;


}

void flameArrow::draw()
{
	if (flameArrowOn)
	{
		graphics::Brush myflameArrow;

		myflameArrow.texture = "assets//myPics//flameArrow.png";
		myflameArrow.outline_opacity = 0.0f;
		graphics::setOrientation(-40);
		graphics::drawRect(spx - 70, spy + 30, sizeX, sizeY, myflameArrow);
		graphics::resetPose();

		// diskos gia SIGROUSI  
		myflameArrow.texture = " ";
		//myflameArrow.outline_opacity = 1.0f;
		//myflameArrow.fill_opacity = 0.0f;
		//graphics::drawDisk(spx - 70, spy + 30, radious, myflameArrow);
		// otan teliosei i ergasia  na ginei aorato
	}

}