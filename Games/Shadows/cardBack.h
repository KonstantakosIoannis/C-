#pragma once

#pragma once

#include "card.h"
#include <string>

class cardBack : public card
{
private:
	std::string name = "cardBack";

	

public:
	void update();
	void draw();

	

	bool big(float x, float y) { return false; }

	int getHp() { return 0; }
	int getAttack() { return 0; }
	void setHp(int hp) {  }
	void setAttack(int attack) {  }
	std::string getName() { return " "; }

};