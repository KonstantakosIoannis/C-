#pragma once

#include "card.h"
#include <string>

class exodia : public card
{
private:
	std::string name = "exodia";

	int hp = 9;
	int attack = 9;

public:
	void update();
	void draw();

	int getHp() { return this->hp; }
	int getAttack() { return this->attack; }
	void setHp(int hp) { this->hp = this->hp - hp; }
	void setAttack(int attack) { this->attack = this->attack + attack; }
	std::string getName() { return this->name; }
};
