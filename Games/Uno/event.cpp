#include "event.h"

Event::Event(float x, float y, float dur, float del):m_pos_x(x),m_pos_y(y),m_duration(dur),m_delay(del){}

void Event::update()
{
	if (!active())return;

	if (waiting() )
	{
		m_elapsed_delay += graphics::getDeltaTime()/1000.0f;
		return;
	}

	m_elapsed_time += graphics::getDeltaTime();

	if (m_elapsed_time > m_duration)m_active = false;
	
		
	
}

bool Event::waiting(){return m_elapsed_delay < m_delay;}




void YesEvent::draw()
{
	graphics::Brush br;
	float s = m_elapsed_time / m_duration;
	
	br.fill_opacity=1.0f - s;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\png\\tik.png";
	graphics::drawRect(m_pos_x,m_pos_y,2,2, br);
	graphics::resetPose();
}

YesEvent::YesEvent(float x, float y):Event(x,y,2.0f,0.0f)
{
	m_orientation = RAND0TO1() * 180.0f - 90.0f;
	m_scale = 0.8f + RAND0TO1() * 0.4f;
}

void YesEvent::update()
{

	if (!active())return;
	

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;
		return;
	}

	m_elapsed_time += graphics::getDeltaTime()/1000.0f;

	if (m_elapsed_time > m_duration)m_active = false;
	
}








void NoEvent::draw()
{
	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	br.fill_opacity = 1.0f - s;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\png\\not.png";
	graphics::drawRect(m_pos_x, m_pos_y, 2, 2, br);
	graphics::resetPose();
}

NoEvent::NoEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_orientation = RAND0TO1() * 180.0f - 90.0f;
	m_scale = 0.8f + RAND0TO1() * 0.4f;
}

void NoEvent::update()
{
	if (!active())return;

	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)m_active = false;
	
}










void GlowEvent::draw()
{
	graphics::Brush br;

	float s = m_elapsed_time / m_duration;
	graphics::setScale(m_scale+s, m_scale+s);
	graphics::setOrientation(m_orientation + s * 20.0f);
	br.fill_opacity = 1.0f - s;
	br.outline_opacity = 0.0f;
	br.texture = "assets\\png\\glow.png";
	graphics::drawRect(m_pos_x, m_pos_y, 2, 2, br);
	graphics::resetPose();
}

GlowEvent::GlowEvent(float x, float y) :Event(x, y, 2.0f, 0.0f)
{
	m_orientation = RAND0TO1() * 180.0f - 90.0f;
	m_scale = 0.8f + RAND0TO1() * 0.4f;
}

void GlowEvent::update()
{
	if (!active())return;
	
	if (waiting())
	{
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;//metatropi ms->s
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;

	if (m_elapsed_time > m_duration)m_active = false;

}