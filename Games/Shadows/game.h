#pragma once

#include <thread>
#include <chrono>

#include "graphics.h" 

#include "card.h"
#include "cardBack.h"

#include "event.h"

#include "witch.h"
#include "elf.h"
#include "skeleton.h"
#include "clocko.h"
#include "dragon.h"
#include "green.h"
#include "jinzo.h"
#include "knight.h"
#include "kuriboh.h"
#include "magician.h"
#include "ninja.h"
#include "penguin.h"
#include "reddragon.h"
#include "robot.h"
#include "squirrel.h"
#include "worm.h"
#include "snake.h"
#include "fly.h"
#include "dark.h"
#include "bull.h"
#include "orc.h"
#include "raider.h"
#include "fairy.h"
#include "seahorse.h"
#include "mirror.h"
#include "clown.h"
#include "captain.h"
#include "egg.h"
#include "flower.h"
#include "deathking.h"
#include "mech.h"
#include "spell.h"
#include "spell2.h"
#include "spell3.h"
#include "spell4.h"


#include <map>
#include <list>
//#include <iostream>  DEBUGGING

class game
{	
	public :
		enum State { boot , loading , newGame , instructions , playMe , playOp , fire , battle  , win , lose };


	private:

		std::list<Event*> myEvents;  //efe

		bool playerReady = false;
		bool opReady = false;
	
		int mylifepoints ; 
		int oplifepoints ; 

		

		static game* myInstance;
		game() {}

		
		std::map<int,card*> myDeck;
		std::map<int,card*> opDeck;

		card* myHand[3] = { nullptr,nullptr , nullptr };
		card* opHand[3] = { nullptr,nullptr , nullptr };

		int burnedCards[35];
		int burnedCardsPos ;

		int opBurnedCards[35];
		int opBurnedCardPos;
		

		bool pickCard = false;
		
		bool oneTime=false;
		
		
		card* myBattleCard = nullptr;  
		card* opBattleCard = nullptr;

		State myState = boot;

		//kathisterisi maxis
		bool wait = false;
		float myTime = 500000000 ;

		
		

	public:
		
		void prossEvents();
		void addEvent(Event* evt);

		void draw();
		void update();

		void init(); 
	
		static game* getInsance();
		static void release();

		~game();

};