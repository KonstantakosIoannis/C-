#include "fireball.h"


void fireball::setDragonXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void fireball::update()
{


	if (graphics::getGlobalTime() - tempTime > rechargeTime)
	{
		graphics::playSound("assets\\mySongs\\fire.mp3", 1.0f, false);
		fireballOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx + fx;
	spy = spy + fy;

	if (spx < 160)fx = 2.5;
	if (spx > 1075)fx = -2.5;
	if (spy <-50)fy = 1.5;
	if (spy > 400)fy = -1.5;


}

void fireball::draw()
{
	if (fireballOn)
	{
		graphics::Brush myFireball;

		myFireball.texture = "assets//myPics//fireball.png";
		myFireball.outline_opacity = 0.0f;
		graphics::setOrientation(-47);
		graphics::drawRect(spx - 130, spy + 80, sizeX, sizeY, myFireball);
		graphics::resetPose();

		// diskos gia SIGROUSI  
		myFireball.texture = " ";
		//myFireball.outline_opacity = 1.0f;
		//myFireball.fill_opacity = 0.0f;
		//graphics::drawDisk(spx - 130, spy + 80, radious, myFireball);
		// otan teliosei i ergasia  na ginei aorato
	}

}