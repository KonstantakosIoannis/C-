#pragma once

#include "defines.h" // statheres times (kefalaia)
#include "graphics.h" 

#include <random>
#include <thread>
#include <vector> 
#include <list>

#include "event.h"
#include "paso.h"
#include "blue1.h"
#include "green1.h"
#include "yellow1.h"
#include "red1.h"
#include "blue2.h"
#include "green2.h"
#include "yellow2.h"
#include "red2.h"
#include "blue3.h"
#include "green3.h"
#include "yellow3.h"
#include "red3.h"
#include "blue4.h"
#include "yellow4.h"
#include "green4.h"
#include "red4.h"
#include "yellow5.h"
#include "red5.h"
#include "green5.h"
#include "blue5.h"
#include "blue6.h"
#include "red6.h"
#include "yellow6.h"
#include  "green6.h"
#include  "green7.h"
#include "blue7.h"
#include "yellow7.h"
#include "red7.h"
#include  "green8.h"
#include "blue8.h"
#include "yellow8.h"
#include "red8.h"
#include  "green9.h"
#include "blue9.h"
#include "yellow9.h"
#include "red9.h"
#include "special.h"


class Game
{	
	public :
		enum game_state_t { STATE_INIT ,STATE_LOADING ,STATE_HOWTO, STATE_IDLE ,STATE_MOVING , STATE_PASO , STATE_FIREWORKS  };
	

	protected:
		//singleton : 
		static Game* m_instance; //private
		Game(){} // private 

		GameObject* Cpaso = nullptr;

		std::vector <GameObject*> trapoula;
		std::vector <GameObject*> trapoulaUno;
		std::vector <GameObject*> trapoulaDuo;
		std::list<Event*> m_events;

		GameObject* m_active_card = nullptr;
		GameObject* m_center_card = nullptr;

		float init_pos_x;
		float init_pos_y;
		bool m_uno = false;
		bool m_duo = false;
		bool wall=true;
		bool uno;
		unsigned int WINS1 = 0;
		unsigned int WINS2 = 0;
		int epomeno = 23;

		game_state_t m_state = STATE_INIT;

	public : 
		static Game* getInstance();
		static void releaseInstance()
		{
			if (m_instance)
			{
				delete m_instance;
				m_instance =nullptr;
			}
		}

		void prossEvents();
		void addEvent(Event * evt);
		void draw();
		void update();
		void init();

		~Game()
		{
			for (auto karta : trapoulaDuo)
			{
				if (karta)delete karta;
			}
			for (auto karta : trapoulaUno)
			{
				if (karta)delete karta;
			}
			for (auto karta : trapoula)
			{
				if (karta)delete karta;
			}
			delete m_center_card;
			m_center_card = nullptr;

			trapoulaUno.clear();
			trapoulaDuo.clear();
			trapoula.clear();
		}		
};