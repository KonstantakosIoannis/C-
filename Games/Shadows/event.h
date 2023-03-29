#pragma once
#include "graphics.h"
#include <algorithm>

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

	virtual void draw() = 0;
	virtual void update() =0;
	virtual ~Event(){}

	bool active() { return m_active; }

	void disable() { m_active = false; }

	bool waiting();

	
};



class BattleEvent : public Event
{
	float m_orientation;
	float m_scale;

	bool oneTime = true;

public:
	void draw()override;
	BattleEvent(float x, float y);
	void update();
};


class FireEvent : public Event
{
	float m_orientation;
	float m_scale;

	bool oneTime = true;

public:
	void draw()override;
	FireEvent(float x, float y);
	void update();
};


class HealEvent : public Event
{
	float m_orientation;
	float m_scale;

	bool oneTime = true;

public:
	void draw()override;
	HealEvent(float x, float y);
	void update();
};