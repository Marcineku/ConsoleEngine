#pragma once

#include "ConsoleEngine.h"

#include <vector>

class TestGame : public ce::Engine
{
private:
	std::vector<ce::Vector2> spawnedObjects;
	ce::Vector2 playerPosition;

	std::pair<ce::Vector2Int, ce::Vector2Int> line;

	Timer lineTransitionTimer;

	auto preUpdate(const double deltaTime)  -> void;
	auto postUpdate(const double deltaTime) -> void;

protected:
	virtual void update(const double deltaTime) override;

public:
	TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight);
};