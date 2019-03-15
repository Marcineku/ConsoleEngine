#include "TestGame.h"

TestGame::TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight)
	:
	Engine(consoleWidth, consoleHeight, fontWidth, fontHeight, L"TestGame"),
	line(ce::Vector2Int(0, 0), ce::Vector2Int(consoleWidth - 1, consoleHeight - 1)),
	rect(1, 1, 3, 3),
	lineTransitionTimer(0.02)
{}

auto TestGame::preUpdate(const double deltaTime) -> void
{
	lineTransitionTimer.update(deltaTime);
}

auto TestGame::postUpdate(const double deltaTime) -> void
{
	for (auto gameObject : spawnedObjects)
	{
		draw(gameObject.x, gameObject.y);
	}

	draw(playerPosition);

	draw(getMousePosition() - ce::Vector2Int(0, 1));
	draw(getMousePosition() + ce::Vector2Int(0, 1));
	draw(getMousePosition() - ce::Vector2Int(1, 0));
	draw(getMousePosition() + ce::Vector2Int(1, 0));

	draw(getMousePosition() + ce::Vector2Int(2, -2), getMousePosition().toString());

	draw(line);

	draw(rect);
}

void TestGame::update(const double deltaTime)
{
	preUpdate(deltaTime);

	if (lineTransitionTimer.hasFinished())
	{
		auto transition = [](ce::Vector2Int& v, const int width, const int height) -> void
		{
			if (v.y == 0 && v.x >= 0 && v.x < width - 1)
			{
				++v.x;
			}
			else if (v.x == width - 1 && v.y >= 0 && v.y < height - 1)
			{
				++v.y;
			}
			else if (v.y == height - 1 && v.x >= 1 && v.x < width)
			{
				--v.x;
			}
			else if (v.x == 0 && v.y >= 1 && v.y < height)
			{
				--v.y;
			}
		};

		transition(line.first, getWindowWidth(), getWindowHeight());
		transition(line.second, getWindowWidth(), getWindowHeight());
	}

	if (isKeyPressed(ce::Key::Esc))
	{
		close();
	}

	if (isKeyPressed(ce::Mouse::Button::Left))
	{
		spawnedObjects.push_back(ce::Vector2(getMousePosition().x, getMousePosition().y));
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

	postUpdate(deltaTime);
}