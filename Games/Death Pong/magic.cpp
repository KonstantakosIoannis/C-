#include "magic.h"


void magic::setSorcerorXY(const float px, const  float py)
{
	this->px = px;
	this->py = py;
}

void magic::update()
{
	// epithesi 1
	
	if ((graphics::getKeyState(graphics::SCANCODE_Z) || graphics::getKeyState(graphics::SCANCODE_KP_1)) && (graphics::getGlobalTime() - tempTime > rechargeTime))
	{
		graphics::playSound("assets\\mySongs\\magic.mp3", 1.0f, false);
		magicOn = true; 
		
		spx = px;
		spy = py;
		
		tempTime = graphics::getGlobalTime();
	}
	
	spx = spx + 4;
	

}

void magic::draw()
{
	if (magicOn)
	{
		graphics::Brush myMagic;

		myMagic.texture = "assets//myPics//magic.png";
		myMagic.outline_opacity = 0.0f;

		graphics::drawRect(spx, spy,sizeX, sizeY, myMagic);

		// diskos gia SIGROUSI  
		myMagic.texture = " ";
		//myMagic.outline_opacity = 1.0f;
		//myMagic.fill_opacity = 0.0f;
		//graphics::drawDisk(spx, spy, radious, myMagic);
		// otan teliosei i ergasia  na ginei aorato
	}
	
}