#pragma once

#include "card.h"

class elf :public card
{


	private:
		std::string name = "elf"; //onoma idio me tis klassis idio me to arxeio
		// den einai anagkastiko oute allazei kati alla mas boitha stin 
		//kaliteri katanohsh tou kwdika

		int hp = 5; // se auta ta dio bazeis oti thes
		int attack = 2;

	
	

	public:// ola ta public functions ws exoun copy paste
		void update();
		void draw();

		int getHp() { return this->hp; }
		int getAttack() { return this->attack; }
		void setHp(int hp) { this->hp = this->hp-hp; }
		void setAttack(int attack) { this->attack = this->attack + attack; }//auto kyriws gia magies
		std::string getName() { return this->name; }
};