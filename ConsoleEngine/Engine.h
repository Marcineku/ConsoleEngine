#pragma once

#include "Window.h"

#include <chrono>

namespace ConsoleEngine
{
	class Engine
	{
	protected:
		Window* window;

		virtual void setup() = 0;
		virtual void update(double deltaTime) = 0;

	public:
		Engine(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight);
		~Engine();

		void run();
	};
}