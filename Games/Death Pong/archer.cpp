#pragma once

#include "archer.h"

void archer::draw()
{
	graphics::Brush myArcher;
	myArcher.texture = "assets//myPics//archer.png";
	myArcher.outline_opacity = 0.0f;
	graphics::drawRect(px, py, sizeX, sizeY, myArcher);

	// diskos gia SIGROUSI  
	myArcher.texture = " ";
	//myArcher.outline_opacity = 1.0f;
	//myArcher.fill_opacity = 0.0f;
	//graphics::drawDisk(px, py, radious, myArcher);
	// otan teliosei i ergasia  na ginei aorato


	//hp me arithmous  // na sbistei kai na meinei mono h mpara
	//char infoArcherHp[40];
	//sprintf_s(infoArcherHp, "(%4.1f)", hp);
	//myArcher.fill_color[0] = 0.350f;  
	//myArcher.fill_color[1] = 0.0f;
	///myArcher.fill_color[2] = 0.0f;
	//myArcher.fill_opacity = 1.0f;
	//graphics::drawText(800, 50, 50, infoArcherHp, myArcher);
	//graphics::setFont("assets//myFonts//prince.ttf");
	//


	//graphics::Brush myMonsterHp;
	//myMonsterHp.fill_opacity = 0.0f;
	//myMonsterHp.outline_opacity = 0.0f;
	//graphics::drawRect(px, py - 105, 150, 30, myMonsterHp);

	myArcher.fill_opacity = 1.0f;
	myArcher.outline_opacity = 0.0f;
	myArcher.fill_color[0] = 0.350f;  
	myArcher.fill_color[1] = 0.0f;
	myArcher.fill_color[2] = 0.0f;
	myArcher.fill_secondary_color[0] = 0.0f;
	myArcher.fill_secondary_color[1] = 0.350f;
	myArcher.fill_secondary_color[2] = 0.0f;
	myArcher.gradient = true;
	myArcher.gradient_dir_u = 1.0f;
	myArcher.gradient_dir_v = 0.0f;

	graphics::drawRect(px - (150 - hp/1.75) / 2, py - 125, hp/1.75, 30, myArcher);

	
}

void archer::update()
{
	py = py + fy;
	if (py > 500 - sizeY / 2)fy = -1;
	if (py < sizeY / 2)fy = 1;
}