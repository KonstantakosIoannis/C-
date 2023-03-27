#pragma once

#include "orc.h"

void orc::draw()
{
	graphics::Brush myOrc;
	myOrc.texture = "assets//myPics//orc.png";
	myOrc.outline_opacity = 0.0f;
	graphics::drawRect(px, py, sizeX, sizeY, myOrc);

	if (healOn)
	{
		myOrc.texture = "assets//myPics//heal.png";
		myOrc.outline_opacity = 0.0f;
		graphics::drawRect(px, py, sizeX-40, sizeY-40, myOrc);
	}

	// diskos gia SIGROUSI  
	myOrc.texture = " ";
	//myOrc.outline_opacity = 1.0f;
	//myOrc.fill_opacity = 0.0f;
	//graphics::drawDisk(px, py, radious, myOrc);
	// otan teliosei i ergasia  na ginei aorato


	//hp me arithmous
	//char infoSorcerorHp[40];
	//sprintf_s(infoSorcerorHp, "(%4.1f)", hp);
	//myOrc.fill_color[0] = 0.350f;
	//myOrc.fill_color[1] = 0.0f;
	//myOrc.fill_color[2] = 0.0f;
	//myOrc.fill_opacity = 1.0f;
	//graphics::drawText(100, 50, 50, infoSorcerorHp, myOrc);
	//graphics::setFont("assets//myFonts//prince.ttf");
	//


	// hp mpara 1os tropos
	myOrc.fill_opacity = 0.5f;
	myOrc.fill_color[0] = 1.0f;
	myOrc.fill_color[1] = 0.0f;
	myOrc.fill_color[2] = 0.0f;
	myOrc.outline_opacity = 0.0f;
	graphics::drawRect(px, py - 130, 120, 30, myOrc);

	myOrc.fill_color[0] = 0.0f;
	myOrc.fill_color[1] = 1.0f;
	myOrc.fill_color[2] = 0.0f;
	graphics::drawRect(px - (120 - hp / 2.916) / 2, py - 130, (hp / 2.916), 30, myOrc);
	//prosarmouzoume tous hp=200 sto 120 . gi auto kai i diairesi me to  1.6667
	//
}

void orc::update()
{
	//movement
	if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		px = px - graphics::getDeltaTime() / 3.0f; // SOS   oso pio megalo to /x  toso pio argo . px /100 ine pio argo apo to /50
	}

	if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		px = px + graphics::getDeltaTime() / 3.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
	{
		py = py - graphics::getDeltaTime() / 3.0f;
	}

	if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		py = py + graphics::getDeltaTime() / 3.0f;
	}
	//end

	//oria kinisis
	if (px < sizeX / 2) px = sizeX / 2;
	if (py < sizeY / 2) py = sizeY / 2;
	if (px > 180) px = 180;
	if (py > 500 - sizeY / 2) py = 500 - sizeY / 2;
	//end

	//heal - kathe 15seconds
	rechargeTime = graphics::getGlobalTime() - tempTime;
	if ((graphics::getKeyState(graphics::SCANCODE_X) || graphics::getKeyState(graphics::SCANCODE_KP_2)) && rechargeTime > 15000)
	{
		tempTime = graphics::getGlobalTime();
		hp = hp + 50;
		graphics::playSound("assets\\mySongs\\heal.mp3", 0.9f, false);
		healOn = true;

	}
	if (graphics::getGlobalTime() - tempTime > 1500) healOn = false;
	if (hp > 350)hp = 350;
	
	//end

	

}