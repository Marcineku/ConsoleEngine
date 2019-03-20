#include "Timer.h"

ce::Timer::Timer(const double time)
	:
	time(time),
	count(0.0),
	run(true)
{}

auto ce::Timer::start() -> void
{
	run = true;
}

auto ce::Timer::stop() -> void
{
	run = false;
}

auto ce::Timer::update(double deltaTime) -> void
{
	if (run)
	{
		count += deltaTime;
	}
}

auto ce::Timer::reset() -> void
{
	count = 0.0;
}

auto ce::Timer::hasFinished() -> bool
{
	if (count >= time)
	{
		reset();
		return true;
	}

	return false;
}

auto ce::Timer::getCount() const -> double
{
	return count;
}

auto ce::Timer::getTime() const -> double
{
	return time;
}

auto ce::Timer::setTime(const double time) -> void
{
	this->time = time;
}