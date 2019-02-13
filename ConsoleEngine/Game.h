#pragma once

#include "Engine.h"

#include <vector>

struct Block
{
	double x, y;
	Block()
	{
		x = 0.0;
		y = 0.0;
	}
	Block(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

class Game : public ConsoleEngine::Engine
{
private:
	std::vector<Block> gameObjects;

	double playerPositionX = 0.0;
	double playerPositionY = 0.0;

protected:
	virtual void setup() override;
	virtual void update(double deltaTime) override;

public:
	Game(int consoleWidth, int consoleHeight, int fontWidth = 8, int fontHeight = 8);
	~Game();
};