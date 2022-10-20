#include "Time.h"

std::chrono::time_point<std::chrono::high_resolution_clock> Time::start;
double Time::deltaTime = 0.0f;

void Time::init(std::chrono::time_point<std::chrono::high_resolution_clock> time)
{
	start = time;
}

void Time::setNewTime(std::chrono::time_point<std::chrono::high_resolution_clock> end)
{
	auto diff = end - start;
	deltaTime = diff / std::chrono::microseconds(1) / 1000000.0f;
	start = end;
}

double Time::getDeltaTime()
{
	return deltaTime;
}
