#pragma once

#include "ConsoleEngine.h"

#include <vector>

class Game : public ce::ConsoleEngine
{
private:
	std::vector<ce::Vector2> gameObjects;
	ce::Vector2 playerPosition;

protected:
	virtual void update(const double deltaTime) override;

public:
	Game(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight);
	~Game();
};