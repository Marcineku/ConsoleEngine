#include "TestGame.h"

TestGame::TestGame(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight)
	:
	Engine(consoleWidth, consoleHeight, fontWidth, fontHeight, L"TestGame"),
	line(ce::Vector2Int(0, 0), ce::Vector2Int(consoleWidth - 1, consoleHeight - 1)),
	rect(10.0, 10.0, 5.0, 5.0),
	isRectSelected(false),
	lineTransitionTimer(0.02),
	clickPoint(0, 0)
{}

auto TestGame::preUpdate(const double deltaTime) -> void
{
	lineTransitionTimer.update(deltaTime);
}

auto TestGame::postUpdate(const double deltaTime) -> void
{
	draw(ce::Rect(playerPosition, ce::Vector2(3.0, 3.0)));

	draw(getMousePosition() + ce::Vector2Int(2, -2), getMousePosition().toString());

	draw(line);

	draw(rect);

	if (rect.contains(getMousePosition()) || isRectSelected)
	{
		draw(rect.position() - ce::Vector2(0, 2), rect.toString());
		draw(rect.position() - ce::Vector2(0, 4), L"center: " + rect.center().toString());
	}

	if (isKeyHeld(ce::Mouse::Left))
	{
		const ce::RectInt r = ce::RectInt(clickPoint, getMousePosition() - clickPoint + ce::Vector2Int(1, 1));
		draw(r);
		draw(r.position() + ce::Vector2Int(1, 1), r.toString());
	}
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

	ce::Vector2 newPlayerPosition = playerPosition;

	if (isKeyHeld(ce::Key::Left) || isKeyHeld(ce::Key::A))
	{
		newPlayerPosition.x -= deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Up) || isKeyHeld(ce::Key::W))
	{
		newPlayerPosition.y -= deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Right) || isKeyHeld(ce::Key::D))
	{
		newPlayerPosition.x += deltaTime * 50;
	}

	if (isKeyHeld(ce::Key::Down) || isKeyHeld(ce::Key::S))
	{
		newPlayerPosition.y += deltaTime * 50;
	}

	if (!ce::Rect(newPlayerPosition, ce::Vector2(3.0, 3.0)).overlaps(rect))
	{
		playerPosition = newPlayerPosition;
	}

	if (isKeyPressed(ce::Mouse::Left))
	{
		clickPoint = getMousePosition();	
	}

	if (isKeyReleased(ce::Mouse::Left))
	{
		isRectSelected = ce::Rect(clickPoint, getMousePosition() - clickPoint + ce::Vector2Int(1, 1)).contains(rect.center());
	}

	postUpdate(deltaTime);
}