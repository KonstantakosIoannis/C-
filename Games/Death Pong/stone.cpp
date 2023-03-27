#include "stone.h"

void stone::setOrcXY(const float px, const float py)
{
	this->px = px;
	this->py = py;
}

void stone::update()
{
	// epithesi 1

	if ((graphics::getKeyState(graphics::SCANCODE_Z) || graphics::getKeyState(graphics::SCANCODE_KP_1)) && (graphics::getGlobalTime() - tempTime > rechargeTime))
	{
		graphics::playSound("assets\\mySongs\\stone.mp3", 1.0f, false);
		stoneOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx + 4;


}

void stone::draw()
{
	if (stoneOn)
	{
		graphics::Brush myStone;

		myStone.texture = "assets//myPics//stone.png";
		myStone.outline_opacity = 0.0f;

		graphics::drawRect(spx, spy, sizeX, sizeY, myStone);

		// diskos gia SIGROUSI  
		myStone.texture = " ";
		//myStone.outline_opacity = 1.0f;
		//myStone.fill_opacity = 0.0f;
		//graphics::drawDisk(spx, spy, radious, myStone);
		// otan teliosei i ergasia  na ginei aorato
	}

}