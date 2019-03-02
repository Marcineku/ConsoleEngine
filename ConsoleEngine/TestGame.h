#pragma once

#include "ConsoleEngine.h"

#include <vector>

class TestGame : public ce::Engine
{
private:
	std::vector<ce::Vector2> gameObjects;
	ce::Vector2 playerPosition;

protected:
	virtual void update(const double deltaTime) override;

public:
	TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight);
};