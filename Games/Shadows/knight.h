#pragma once

#include "card.h"
#include <string>

class knight : public card
{
private:
	std::string name = "knight";

	int hp = 4;
	int attack = 4;

public:
	void update();
	void draw();

	int getHp() { return this->hp; }
	int getAttack() { return this->attack; }
	void setHp(int hp) { this->hp = this->hp - hp; }
	void setAttack(int attack) { this->attack = this->attack + attack; }
	std::string getName() { return this->name; }
};
