#include "Game.h"

Game::Game(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight)
	: Engine(consoleWidth, consoleHeight, fontWidth, fontHeight)
{
	timer = 0;
	interval = 0.01;
}

Game::~Game()
{

}

void Game::setup()
{

}

void Game::update(double deltaTime)
{
	timer += deltaTime;

	window->point(playerPositionX, playerPositionY);

	if (timer >= interval)
	{
		GetAsyncKeyState(0);
		playerPositionX += 1;
		timer = 0.0;
	}

	if (playerPositionX >= window->getWidth())
	{
		playerPositionX = 0;
		playerPositionY += 1;

		if (playerPositionY >= window->getHeight())
		{
			this->playerPositionY = 0;
		}
	}
}