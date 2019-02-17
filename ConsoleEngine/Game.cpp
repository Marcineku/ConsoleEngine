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
	if (isKeyPressed(ConsoleEngine::KEY::BUTTON_LEFT))
	{
		Block block(getMousePosition().x, getMousePosition().y);
		gameObjects.push_back(block);
	}

	if (isKeyDown(ConsoleEngine::KEY::KEY_LEFT))
		playerPositionX -= deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY::KEY_UP))
		playerPositionY -= deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY::KEY_RIGHT))
		playerPositionX += deltaTime * 50;

	if (isKeyDown(ConsoleEngine::KEY::KEY_DOWN))
		playerPositionY += deltaTime * 50;

	for (auto gameObject: gameObjects)
	{
		window->drawPixel(gameObject.x, gameObject.y);
	}

	window->drawPixel(playerPositionX, playerPositionY);

	window->drawPixel(getMousePosition().x, getMousePosition().y - 1);
	window->drawPixel(getMousePosition().x, getMousePosition().y + 1);
	window->drawPixel(getMousePosition().x - 1, getMousePosition().y);
	window->drawPixel(getMousePosition().x + 1, getMousePosition().y);

	window->drawLine(1, 1, window->getWidth() - 1, window->getHeight() - 1);
}