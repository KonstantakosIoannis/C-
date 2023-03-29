#include "card.h"

//edw thelei poli doulia
bool card::big(float x, float y)
{
	if (distance(x, y, this->x, this->y) < 1)
	{
		setWidth(5); 
		setLength(5);

		graphics::Brush br;

		br.fill_color[0] = 0.0;
		br.fill_color[1] = 0.0;
		br.fill_color[2] = 0.0;

		graphics::setFont("assets\\ttfs\\celtic.ttf");


		char stats[40];
		sprintf_s(stats, "%d                          %d", (getHp()), (getAttack()));
		graphics::drawText(this->x - 3.75, this->y -1, 1.5, stats, br);
		
		

		return true;
	}
	else
	{
		setWidth(4);
		setLength(4.5);
		return false;
	}
}
