#pragma once
#include <chrono>
class Time
{
	private:
		static std::chrono::time_point<std::chrono::high_resolution_clock> start;
		static double deltaTime;
	public:
		static void init(std::chrono::time_point<std::chrono::high_resolution_clock> time);
		static void setNewTime(std::chrono::time_point<std::chrono::high_resolution_clock> time);
		static double getDeltaTime();
};

