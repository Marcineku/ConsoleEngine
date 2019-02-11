#pragma once

#include "Engine.h"

class Game : public ConsoleEngine::Engine
{
private:
	double playerPositionX = 0.0;
	double playerPositionY = 0.0;

protected:
	virtual void setup() override;
	virtual void update(double deltaTime) override;

public:
	Game(int consoleWidth, int consoleHeight, int fontWidth = 8, int fontHeight = 8);
	~Game();
};