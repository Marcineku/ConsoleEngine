#pragma once

#include "Window.h"

#include <chrono>

namespace ConsoleEngine
{
	class Engine
	{
	private:
		bool run;

		bool* isKeyDownNew;
		bool* isKeyDownOld;

	protected:
		Window* window;

		virtual void setup() = 0;
		virtual void update(double deltaTime) = 0;

		bool isKeyDown(KEY key);

	public:
		Engine(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight);
		~Engine();

		void start();
	};
}