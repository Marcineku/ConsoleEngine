#pragma once

class Timer
{
private:
	double time;
	double count;

	bool run;

public:
	Timer(const double time);

	auto start ()                       -> void;
	auto stop  ()                       -> void;
	auto update(const double deltaTime) -> void;
	auto reset ()                       -> void;

	auto hasFinished()                  -> bool;
	auto getCount() const               -> double;
};