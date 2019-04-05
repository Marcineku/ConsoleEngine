#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

namespace ce
{
	class Timer
	{
	private:
		double time;
		double count;

		bool run;

	public:
		CONSOLEENGINE_API Timer(const double time);

		CONSOLEENGINE_API auto start()                        -> void;
		CONSOLEENGINE_API auto stop()                         -> void;
		CONSOLEENGINE_API auto update(const double deltaTime) -> void;
		CONSOLEENGINE_API auto reset()                          -> void;

		CONSOLEENGINE_API auto hasFinished()                  -> bool;
		CONSOLEENGINE_API auto getCount() const               -> double;

		CONSOLEENGINE_API auto getTime() const                -> double;
		CONSOLEENGINE_API auto setTime(const double time)     -> void;
	};
}