#include "Game.h"

Game::Game(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight)
	: Engine(consoleWidth, consoleHeight, fontWidth, fontHeight)
{

}

Game::~Game()
{

}

void Game::setup()
{

}

void Game::update(double deltaTime)
{
	if (isKeyPressed(ConsoleEngine::KEY::KEY_LEFT))
		playerPositionX -= 1;

	if (isKeyReleased(ConsoleEngine::KEY::KEY_UP))
		playerPositionY -= 1;

	if (isKeyDown(ConsoleEngine::KEY::KEY_RIGHT))
		playerPositionX += deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY::KEY_DOWN))
		playerPositionY += deltaTime * 50;

	window->point(playerPositionX, playerPositionY);
}