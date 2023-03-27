#include "magic2.h"


void magic2::setSorcerorXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void magic2::update()
{
	// epithesi 2
	// tha mou auksanei to hp ligo kai tha ti balw na kinitai san imitono

	if ((graphics::getKeyState(graphics::SCANCODE_C) || graphics::getKeyState(graphics::SCANCODE_KP_3)) && (graphics::getGlobalTime() - tempTime > rechargeTime))
	{
		graphics::playSound("assets\\mySongs\\magic2.mp3", 1.0f, false);
		magicOn2 = true;

		spx = px;
		spy = py;
		pyTemp = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx + 4;// na to kanw se imitono na kounietai
	spy = spy + fy;
	if (spy < sizeX) fy = 1.5;
	if (spy > 500 - sizeX) fy = -1.5;
	if (spy > pyTemp + 80) fy = -1.5;
	if (spy < pyTemp - 80) fy = 1.5;

}

void magic2::draw()
{
	if (magicOn2)
	{
		graphics::Brush myMagic2;

		myMagic2.texture = "assets//myPics//magic2.png";
		myMagic2.outline_opacity = 0.0f;

		graphics::drawRect(spx, spy, sizeX, sizeY, myMagic2);

		// diskos gia SIGROUSI  
		myMagic2.texture = " ";
		//myMagic2.outline_opacity = 1.0f;
		//myMagic2.fill_opacity = 0.0f;
		//graphics::drawDisk(spx, spy, radious, myMagic2);
		// otan teliosei i ergasia  na ginei aorato
	}

}