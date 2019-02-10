#include "Engine.h"

ConsoleEngine::Engine::Engine(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight)
{
	window = new Window(consoleWidth, consoleHeight, fontWidth, fontHeight);
}

ConsoleEngine::Engine::~Engine()
{
	delete window;
}

void ConsoleEngine::Engine::run()
{
	auto timePoint1 = std::chrono::system_clock::now();
	auto timePoint2 = std::chrono::system_clock::now();

	setup();

	while (true)
	{
		timePoint2 = std::chrono::system_clock::now();
		std::chrono::duration<double> duration = timePoint2 - timePoint1;
		timePoint1 = timePoint2;
		double deltaTime = duration.count();

		window->clear();

		update(deltaTime);

		window->draw();

		window->updateFPS(deltaTime);
	}
}