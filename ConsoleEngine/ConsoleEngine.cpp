#include "ConsoleEngine.h"

auto ce::ConsoleEngine::isHeld(const int keyCode) const -> bool
{
	return isKeyDown[keyCode];
}

auto ce::ConsoleEngine::isPressed(const int keyCode) const -> bool
{
	return !wasKeyDown[keyCode] && isKeyDown[keyCode];
}

auto ce::ConsoleEngine::isReleased(const int keyCode) const -> bool
{
	return wasKeyDown[keyCode] && !isKeyDown[keyCode];
}

auto ce::ConsoleEngine::checkMouseButtonsState() -> void
{
	for (int i = 0; i < 8; ++i)
	{
		isKeyDown[i] = window.isKeyDown(i);
	}
}

auto ce::ConsoleEngine::drawLineLow(const int x0, int y0, const int x1, const int y1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = 2 * dy - dx;

	for (int x = x0; x < x1; ++x)
	{
		draw(x, y0, color, type, fill);
		if (D > 0)
		{
			y0 += yi;
			D -= 2 * dx;
		}
		D += 2 * dy;
	}
}

auto ce::ConsoleEngine::drawLineHigh(int x0, const int y0, const int x1, const int y1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = 2 * dx - dy;

	for (int y = y0; y < y1; ++y)
	{
		draw(x0, y, color, type, fill);
		if (D > 0)
		{
			x0 += xi;
			D -= 2 * dy;
		}
		D += 2 * dx;
	}
}

auto ce::ConsoleEngine::getWindowWidth() const -> int
{
	return window.getWidth();
}

auto ce::ConsoleEngine::getWindowHeight() const -> int
{
	return window.getHeight();
}

auto ce::ConsoleEngine::isKeyHeld(const ce::Key key) const -> bool
{
	return isHeld(to_underlying<Key>(key));
}

auto ce::ConsoleEngine::isKeyPressed(const ce::Key key) const -> bool
{
	return isPressed(to_underlying<Key>(key));
}

auto ce::ConsoleEngine::isKeyReleased(const ce::Key key) const -> bool
{
	return isReleased(to_underlying<Key>(key));
}

auto ce::ConsoleEngine::isKeyHeld(const Mouse::Button button) const -> bool
{
	return isHeld(to_underlying<Mouse::Button>(button));
}

auto ce::ConsoleEngine::isKeyPressed(const Mouse::Button button) const -> bool
{
	return isPressed(to_underlying<Mouse::Button>(button));
}

auto ce::ConsoleEngine::isKeyReleased(const Mouse::Button button) const -> bool
{
	return isReleased(to_underlying<Mouse::Button>(button));
}

auto ce::ConsoleEngine::getMousePosition() const -> Vector2Int
{
	return mousePosition;
}

auto ce::ConsoleEngine::draw(const int x, const int y, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	window.draw(x, y, to_underlying(type), to_underlying(color) | to_underlying(fill));
}

auto ce::ConsoleEngine::draw(const Vector2Int& point, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(point.x, point.y, color, type, fill);
}

auto ce::ConsoleEngine::draw(const int x0, const int y0, const int x1, const int y1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	if (std::abs(y1 - y0) < std::abs(x1 - x0))
	{
		if (x0 > x1)
		{
			drawLineLow(x1, y1, x0, y0, color, type, fill);
		}
		else
		{
			drawLineLow(x0, y0, x1, y1, color, type, fill);
		}
	}
	else
	{
		if (y0 > y1)
		{
			drawLineHigh(x1, y1, x0, y0, color, type, fill);
		}
		else
		{
			drawLineHigh(x0, y0, x1, y1, color, type, fill);
		}
	}
}

auto ce::ConsoleEngine::draw(const Vector2Int& p0, const Vector2Int& p1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(p0.x, p0.y, p1.x, p1.y, color, type, fill);
}

auto ce::ConsoleEngine::draw(const std::pair<Vector2Int, Vector2Int>& line, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(line.first, line.second, color, type, fill);
}

auto ce::ConsoleEngine::draw(const double x, const double y, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(std::lround(x), std::lround(y), color, type, fill);
}

auto ce::ConsoleEngine::draw(const Vector2& point, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(point.x, point.y, color, type, fill);
}

auto ce::ConsoleEngine::draw(const double x0, const double y0, const double x1, const double y1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(std::lround(x0), std::lround(y0), std::lround(x1), std::lround(y1), color, type, fill);
}

auto ce::ConsoleEngine::draw(const Vector2& p0, const Vector2& p1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(p0.x, p0.y, p1.x, p1.y, color, type, fill);
}

auto ce::ConsoleEngine::draw(const std::pair<Vector2, Vector2>& line, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void
{
	draw(line.first, line.second, color, type, fill);
}

ce::ConsoleEngine::ConsoleEngine(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight, const std::wstring_view title)
	:
	title(title),
	window(consoleWidth, consoleHeight, fontWidth, fontHeight),
	wasKeyDown({}),
	isKeyDown({}),
	mousePosition(0, 0)
{}

ce::ConsoleEngine::~ConsoleEngine()
{
	window.close();
}

auto ce::ConsoleEngine::start() -> void
{
	auto timePoint1 = std::chrono::system_clock::now();
	auto timePoint2 = std::chrono::system_clock::now();
	std::chrono::duration<double> duration;
	double deltaTime;

	Event event;

	std::wstringstream wstringStream;

	while (window.isOpen())
	{
		timePoint2 = std::chrono::system_clock::now();
		duration = timePoint2 - timePoint1;
		timePoint1 = timePoint2;
		deltaTime = duration.count();

		window.clear();
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Type::KeyStateChange:
				isKeyDown[to_underlying(event.keyState.key)] = event.keyState.isDown;
				break;
			case Event::Type::MouseMove:
				mousePosition = event.mousePosition;
				break;
			case Event::Type::WindowResize:
				break;
			default:
				break;
			}
		}
		checkMouseButtonsState();
		
		update(deltaTime);

		window.display();

		wasKeyDown = isKeyDown;

		wstringStream.str(std::wstring());
		wstringStream << title << L" FPS: " << 1.0 / deltaTime;
		window.setTitle(wstringStream.str());
	}
}