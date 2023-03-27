#include "tree.h"

void tree::setOrcXY(const float px, const  float py)
{
	this->px = px;
	this->py = py;
}

void tree::update()
{
	// epithesi 2

	if ((graphics::getKeyState(graphics::SCANCODE_C) || graphics::getKeyState(graphics::SCANCODE_KP_3)) && (graphics::getGlobalTime() - tempTime > rechargeTime))
	{
		graphics::playSound("assets\\mySongs\\tree.mp3", 1.0f, false);
		treeOn = true;

		spx = px;
		spy = py;

		tempTime = graphics::getGlobalTime();
	}

	spx = spx + 4;
	turn = turn + 1;


}

void tree::draw()
{
	if (treeOn)
	{
		graphics::Brush myTree;

		myTree.texture = "assets//myPics//tree.png";
		myTree.outline_opacity = 0.0f;
		//graphics::setOrientation(turn);
		graphics::setOrientation(graphics::getGlobalTime()/2);
		graphics::drawRect(spx, spy, sizeX, sizeY, myTree);
		graphics::resetPose();

		// diskos gia SIGROUSI  
		myTree.texture = " ";
		
		//myTree.outline_opacity = 1.0f;
		//myTree.fill_opacity = 0.0f;
		//graphics::drawDisk(spx, spy, radious, myTree);
		// otan teliosei i ergasia  na ginei aorato
	}

}