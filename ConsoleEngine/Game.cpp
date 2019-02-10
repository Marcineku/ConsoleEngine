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

	if (isKeyDown(ConsoleEngine::KEY_LEFT))
		playerPositionX -= deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY_UP))
		playerPositionY -= deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY_DOWN))
		playerPositionY += deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY_RIGHT))
		playerPositionX += deltaTime * 50;

	window->point(playerPositionX, playerPositionY);
}