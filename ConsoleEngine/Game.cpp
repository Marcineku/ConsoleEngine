#include "Game.h"

Game::Game(int consoleWidth, int consoleHeight, int fontWidth, int fontHeight)
	: ConsoleEngine(consoleWidth, consoleHeight, fontWidth, fontHeight)
{

}

Game::~Game()
{

}

void Game::update(const double deltaTime)
{
	if (isKeyPressed(ce::Key::MouseLeft))
	{
		ce::Vector2 block(getMousePosition().x, getMousePosition().y);
		gameObjects.push_back(block);
	}

	if (isKeyHeld(ce::Key::Left) || isKeyHeld(ce::Key::A))
	{
		playerPosition.x -= deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Up) || isKeyHeld(ce::Key::W))
	{
		playerPosition.y -= deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Right) || isKeyHeld(ce::Key::D))
	{
		playerPosition.x += deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Down) || isKeyHeld(ce::Key::S))
	{
		playerPosition.y += deltaTime * 50;
	}

	for (auto gameObject: gameObjects)
	{
		draw(gameObject.x, gameObject.y);
	}

	draw(playerPosition.x, playerPosition.y);

	draw(getMousePosition().x, getMousePosition().y - 1);
	draw(getMousePosition().x, getMousePosition().y + 1);
	draw(getMousePosition().x - 1, getMousePosition().y);
	draw(getMousePosition().x + 1, getMousePosition().y);

	draw(1, 1, getWindowWidth() - 1, getWindowHeight() - 1);
}