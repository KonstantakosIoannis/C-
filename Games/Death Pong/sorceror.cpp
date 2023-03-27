#pragma once

#include "sorceror.h"

void sorceror::draw()
{
	graphics::Brush mySorceror;
	mySorceror.texture = "assets//myPics//sorceror.png";
	mySorceror.outline_opacity = 0.0f;
	graphics::drawRect(px, py, sizeX , sizeY, mySorceror);

	// diskos gia SIGROUSI  
	mySorceror.texture = " ";
	//mySorceror.outline_opacity = 1.0f;
	//mySorceror.fill_opacity = 0.0f;
	//graphics::drawDisk(px, py, radious, mySorceror);
	// otan teliosei i ergasia  na ginei aorato


	//hp me arithmous
	//char infoSorcerorHp[40];
	//sprintf_s(infoSorcerorHp, "(%4.1f)", hp);
	//mySorceror.fill_color[0] = 0.350f;  
	//mySorceror.fill_color[1] = 0.0f;
	//mySorceror.fill_color[2] = 0.0f;
	//mySorceror.fill_opacity = 1.0f;
	//graphics::drawText(100, 50, 50, infoSorcerorHp, mySorceror);
	//graphics::setFont("assets//myFonts//prince.ttf");
	//


	// hp mpara 1os tropos
	mySorceror.fill_opacity = 0.5f;
	mySorceror.fill_color[0] = 1.0f;
	mySorceror.fill_color[1] = 0.0f;
	mySorceror.fill_color[2] = 0.0f;
	mySorceror.outline_opacity = 0.0f;
	graphics::drawRect(px, py - 130, 120, 30, mySorceror);  

	mySorceror.fill_color[0] = 0.0f;
	mySorceror.fill_color[1] = 1.0f;
	mySorceror.fill_color[2] = 0.0f;
	graphics::drawRect(px-(120-hp/1.667)/2 , py-130 , (hp/1.6667), 30, mySorceror);
	//prosarmouzoume tous hp=200 sto 120 . gi auto kai i diairesi me to  1.6667
	//

}

void sorceror::update()
{
	//movement
	if (graphics::getKeyState(graphics::SCANCODE_A)|| graphics::getKeyState(graphics::SCANCODE_LEFT))  
	{
		px = px - graphics::getDeltaTime() / 3.0f; // SOS   oso pio megalo to /x  toso pio argo . px /100 ine pio argo apo to /50
	}
	
	if (graphics::getKeyState(graphics::SCANCODE_D)|| graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		px = px + graphics::getDeltaTime() / 3.0f;
	}
	
	if (graphics::getKeyState(graphics::SCANCODE_W)|| graphics::getKeyState(graphics::SCANCODE_UP))
	{
		py = py - graphics::getDeltaTime() / 3.0f;
	}
	
	if (graphics::getKeyState(graphics::SCANCODE_S)|| graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		py = py + graphics::getDeltaTime() / 3.0f;
	}
	//end

	//oria kinisis
	if (px < sizeX/2) px = sizeX/2;    
	if (py < sizeY/2) py = sizeY/2;    
	if (px > 180) px = 180; 
	if (py > 500-sizeY/2) py = 500-sizeY/2; 
	//end


	//minimize - kathe 15seconds
	rechargeTime = graphics::getGlobalTime() - tempTime;
	if ((graphics::getKeyState(graphics::SCANCODE_X) || graphics::getKeyState(graphics::SCANCODE_KP_2)) && rechargeTime > 15000)
	{
		tempTime = graphics::getGlobalTime();
		sizeX = sizeX - 100;
		sizeY = sizeY - 175;
		radious = radious - 60;
		
		graphics::playSound("assets\\mySongs\\mini.mp3", 0.9f, false);  

	}
	
	if (sizeX < 30)sizeX = 30;
	if (sizeY < 30)sizeY = 30;
	if (graphics::getGlobalTime() - tempTime > 3000)
	{
		sizeX = 130;
		sizeY = 205;
		radious = 80;
	}
	//end

	
}