#include "TestGame.h"

TestGame::TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight)
	: 
	ConsoleEngine(consoleWidth, consoleHeight, fontWidth, fontHeight)
{}

void TestGame::update(const double deltaTime)
{
	if (isKeyPressed(ce::Mouse::Button::Left))
	{
		gameObjects.push_back(ce::Vector2(getMousePosition().x, getMousePosition().y));
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

	draw(playerPosition);

	draw(getMousePosition().x, getMousePosition().y - 1);
	draw(getMousePosition().x, getMousePosition().y + 1);
	draw(getMousePosition().x - 1, getMousePosition().y);
	draw(getMousePosition().x + 1, getMousePosition().y);

	draw(1, 1, getWindowWidth() - 1, getWindowHeight() - 1);
}