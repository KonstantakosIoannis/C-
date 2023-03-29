#include "event.h"

Event::Event(float x, float y, float dur, float del)
	:m_pos_x(x),m_pos_y(y),m_duration(dur),m_delay(del)
{

}

void Event::update()
{
	if (!active())
	{
		return;
	}

	if (waiting() )
	{
		m_elapsed_delay += graphics::getDeltaTime()/1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime();

	if (m_elapsed_time > m_duration)
	{
		m_active = false;
	}
}

bool Event::waiting()
{
	return m_elapsed_delay < m_delay;
	
}





void BattleEvent::draw()
{

	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\images\\animations\\fire.png";// fonto preload bitmaps
	graphics::drawRect(m_pos_x, m_pos_y, 4, 4, br);
}

BattleEvent::BattleEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_duration =5.5f;
}

void BattleEvent::update()
{
	
	if (oneTime)
	{
		graphics::playSound("assets\\sounds\\ex.wav", 1.0f, false);
		oneTime = false;
	}
	
	if (!active())
	{
		return;
	}

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)
	{
		m_active = false;
	}
}









void HealEvent::draw()
{

	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\images\\animations\\heal.png";// fonto preload bitmaps
	graphics::drawRect(m_pos_x, m_pos_y, 4, 4, br);
}

HealEvent::HealEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_duration = 2.0f;
}

void HealEvent::update()
{
	
	if (oneTime)
	{
		//graphics::playSound("assets\\sounds\\ex.wav", 1.0f, false);
		oneTime = false;
	}

	if (!active())
	{
		return;
	}

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)
	{
		m_active = false;
	}
}







//kalo setting alla OXI - Scale-Orientation
/*
void BattleEvent::draw()
{

	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	graphics::setScale(m_scale + s, m_scale + s);
	graphics::setOrientation(m_orientation + s * 20.0f);
	br.fill_opacity = 1.0f - s;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\images\\animations\\fire.png";// fonto preload bitmaps

	graphics::drawRect(m_pos_x, m_pos_y, 4, 4, br);


	graphics::resetPose();	
}

BattleEvent::BattleEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_orientation = (rand() / (float)RAND_MAX) * 180.0f - 90.0f;
	m_scale = 0.8f + (rand() / (float)RAND_MAX) * 0.4f;
}

void BattleEvent::update()
{
	//graphics::playSound("assets\\music\\moirasma.mp3", 1.0f, false);
	graphics::playSound("assets\\sounds\\ex.wav", 1.0f, false);
	if (!active())
	{
		return;
	}

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)
	{
		m_active = false;
	}
}
*/






void FireEvent::draw()
{
	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	graphics::setScale(m_scale + s, m_scale + s);
	br.fill_opacity = 1.0f - s;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\images\\animations\\flame.png";// fonto preload bitmaps
	
	graphics::drawRect(m_pos_x, m_pos_y, 4, 4, br);
	graphics::resetPose();
}

FireEvent::FireEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_scale = 0.8f + (rand()/(float)RAND_MAX) * 0.4f;
	m_duration = 3.0f;
}

void FireEvent::update()
{
	if (oneTime)
	{
		graphics::playSound("assets\\sounds\\dead.wav", 1.0f, false);

		oneTime = false;
	}
	graphics::playSound("assets\\sounds\\dead.wav", 1.0f, false);

	if (!active())
	{
		return;
	}

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)
	{
		m_active = false;
	}
}