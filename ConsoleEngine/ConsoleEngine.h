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

		Point mousePosition;

	protected:
		Window* window;

		virtual void setup() = 0;
		virtual void update(double deltaTime) = 0;

		CONSOLEENGINE_API bool isKeyDown(KEY key);
		CONSOLEENGINE_API bool isKeyPressed(KEY key);
		CONSOLEENGINE_API bool isKeyReleased(KEY key);

		CONSOLEENGINE_API Point getMousePosition() { return Point(mousePosition.x, mousePosition.y); }

	public:
		CONSOLEENGINE_API Engine(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight);
		CONSOLEENGINE_API ~Engine();

		CONSOLEENGINE_API void start();
		CONSOLEENGINE_API void stop() { run = false; }
	};
}