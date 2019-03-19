#pragma once

#include "ConsoleEngine.h"

#include <vector>
#include <string>

class TestGame : public ce::Engine
{
private:
	ce::Vector2 playerPosition;

	std::pair<ce::Vector2Int, ce::Vector2Int> line;

	ce::Rect rect;
	bool isRectSelected;

	Timer lineTransitionTimer;

	ce::Vector2Int clickPoint;

	auto preUpdate(const double deltaTime)  -> void;
	auto postUpdate(const double deltaTime) -> void;

protected:
	virtual void update(const double deltaTime) override;

public:
	TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight);
};