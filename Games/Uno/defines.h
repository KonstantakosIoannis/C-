#pragma once

#include <algorithm>
#include <thread>

#define RAND0TO1() (rand()/(float)RAND_MAX) 
#define CAN_WID 28.0f
#define CAN_HEI 16.0f
#define SIZE_X 3.0f
#define SIZE_Y 3.0f


inline void sleep(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx - dy * dy);
}