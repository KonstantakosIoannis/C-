#include "fire.h"


void fire::setDragonXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void fire::update()
{


	if (graphics::getGlobalTime() - tempTime > rechargeTime)
	{
		graphics::playSound("assets\\mySongs\\fire.mp3", 1.0f, false);
		fireOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx - 3;


}

void fire::draw()
{
	if (fireOn)
	{
		graphics::Brush myFire;

		myFire.texture = "assets//myPics//fire.png";
		myFire.outline_opacity = 0.0f;
		graphics::setOrientation(-47);
		graphics::drawRect(spx - 130, spy + 80, sizeX, sizeY, myFire);
		graphics::resetPose();

		// diskos gia SIGROUSI  
		myFire.texture = " ";
		//myFire.outline_opacity = 1.0f;
		//myFire.fill_opacity = 0.0f;
		//graphics::drawDisk(spx -155, spy + 80, radious, myFire);
		// otan teliosei i ergasia  na ginei aorato
	}

}