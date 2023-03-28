#pragma once
#include "graphics.h"
#include "defines.h"

class Event
{
protected:
	float m_pos_x;
	float m_pos_y;
	float m_duration = 2.0f;
	float m_delay = 0.0f;
	float m_elapsed_time=0.0f;
	float m_elapsed_delay=0.0f;
	bool m_active = true;

public:
	Event(float x = 0.0f, float y = 0.0f, float dur = 2.0f, float del = 0.0f);

	virtual void draw() {};
	virtual void update() ;
	virtual ~Event(){}
	bool waiting();
	bool active() { return m_active; }
	void disable() { m_active = false; }
};

class YesEvent : public Event
{
	float m_orientation;
	float m_scale;

public:
	void draw()override;
	YesEvent(float x, float y);
	void update();
};

class NoEvent : public Event
{
	float m_orientation;
	float m_scale;

public:
	void draw()override;
	NoEvent(float x, float y);
	void update();
};


class GlowEvent : public Event
{
	float m_orientation;
	float m_scale;

public:
	void draw()override;
	GlowEvent(float x, float y);
	void update();
};