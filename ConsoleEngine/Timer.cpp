#include "Timer.h"

Timer::Timer(const double time)
	:
	time(time),
	count(0.0),
	run(true)
{}

auto Timer::start() -> void
{
	run = true;
}

auto Timer::stop() -> void
{
	run = false;
}

auto Timer::update(double deltaTime) -> void
{
	if (run)
	{
		count += deltaTime;
	}
}

auto Timer::reset() -> void
{
	count = 0.0;
}

auto Timer::hasFinished() -> bool
{
	if (count >= time)
	{
		reset();
		return true;
	}

	return false;
}

auto Timer::getCount() const -> double
{
	return count;
}