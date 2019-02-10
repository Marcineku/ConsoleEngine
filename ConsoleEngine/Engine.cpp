#include "Engine.h"

ConsoleEngine::Engine::Engine(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight)
{
	run = true;

	window = new Window(consoleWidth, consoleHeight, fontWidth, fontHeight);

	isKeyDownNew = new bool[256];
	isKeyDownOld = new bool[256];
	std::memset(isKeyDownNew, 0, 256 * sizeof(bool));
	std::memset(isKeyDownOld, 0, 256 * sizeof(bool));
}

ConsoleEngine::Engine::~Engine()
{
	delete window;

	delete[] isKeyDownNew;
	delete[] isKeyDownOld;
}

void ConsoleEngine::Engine::start()
{
	auto timePoint1 = std::chrono::system_clock::now();
	auto timePoint2 = std::chrono::system_clock::now();

	setup();

	while (run)
	{
		timePoint2 = std::chrono::system_clock::now();
		std::chrono::duration<double> duration = timePoint2 - timePoint1;
		timePoint1 = timePoint2;
		double deltaTime = duration.count();

		for (int i = 0; i < 256; ++i)
		{
			isKeyDownNew[i] = window->isKeyDown(i);
			isKeyDownOld[i] = isKeyDownNew[i];
		}

		window->clear();
		update(deltaTime);
		window->draw();

		window->updateFPS(deltaTime);
	}
}

bool ConsoleEngine::Engine::isKeyDown(KEY key)
{
	return isKeyDownNew[key];
}