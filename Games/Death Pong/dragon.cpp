#pragma once

#include "dragon.h"

void dragon::draw()
{
	graphics::Brush myDragon;
	myDragon.texture = "assets//myPics//dragon.png";
	myDragon.outline_opacity = 0.0f;
	graphics::drawRect(px, py, sizeX, sizeY, myDragon);

	// diskos gia SIGROUSI  
	myDragon.texture = " ";
	//myDragon.outline_opacity = 1.0f;
	//myDragon.fill_opacity = 0.0f;
	//graphics::drawDisk(px, py, radious, myDragon);
	// otan teliosei i ergasia  na ginei aorato


	//hp me arithmous
	//char infoDragonHp[40];
	//sprintf_s(infoDragonHp, "(%4.1f)", hp);
	//myDragon.fill_color[0] = 0.350f;
	//myDragon.fill_color[1] = 0.0f;
	//myDragon.fill_color[2] = 0.0f;
	//myDragon.fill_opacity = 1.0f;
	//graphics::drawText(800, 50, 50, infoDragonHp, myDragon);
	//graphics::setFont("assets//myFonts//prince.ttf");
	//


	// hp mpara 1os tropos
	myDragon.fill_opacity = 0.5f;
	myDragon.fill_color[0] = 1.0f;
	myDragon.fill_color[1] = 0.0f;
	myDragon.fill_color[2] = 0.0f;
	myDragon.outline_opacity = 0.0f;
	graphics::drawRect(px, py - 130, 120, 30, myDragon);

	myDragon.fill_color[0] = 0.0f;
	myDragon.fill_color[1] = 1.0f;
	myDragon.fill_color[2] = 0.0f;
	graphics::drawRect(px - (120 - hp / 4.1666) / 2, py - 130, (hp / 4.1666), 30, myDragon);
	//prosarmouzoume tous hp=500 sto 120 . gi auto kai i diairesi me to  4.1666
	//

}

void dragon::update()
{
	py = py + fy;
	if (py > 500 - sizeY / 2)fy = -0.5;
	if (py < sizeY / 2)fy = 0.5;
	px = px + fx;
	if (px > 1000 - sizeX / 2) fx = -0.5;
	if (px < 800) fx = 0.5;
}