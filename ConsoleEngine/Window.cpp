#include "Window.h"

inline int ConsoleEngine::Window::toBufferPoint(int x, int y)
{
	return y * width + x;
}

inline void ConsoleEngine::Window::drawLineLow(int x0, int y0, int x1, int y1, PIXEL_COLOR color)
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
	
	int y = y0;
	for (int x = x0; x < x1; ++x)
	{
		drawPixel(x, y, color);
		if (D > 0)
		{
			y += yi;
			D -= 2 * dx;
		}
		D += 2 * dy;
	}
}

inline void ConsoleEngine::Window::drawLineHigh(int x0, int y0, int x1, int y1, PIXEL_COLOR color)
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
	
	int x = x0;
	for (int y = y0; y < y1; ++y)
	{
		drawPixel(x, y, color);
		if (D > 0)
		{
			x += xi;
			D -= 2 * dy;
		}
		D += 2 * dx;
	}
}

ConsoleEngine::Window::Window(int windowWidth, int windowHeight, int fontWidth, int fontHeight)
{
	// Initializing private fields
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleInput = GetStdHandle(STD_INPUT_HANDLE);

	width = static_cast<short>(windowWidth);
	height = static_cast<short>(windowHeight);

	start = { 0, 0 };
	size = { 0, 0, width - 1, height - 1 };

	bufferSize = { width, height };
	buffer = new CHAR_INFO[width * height];
	memset(buffer, 0, sizeof(CHAR_INFO) * width * height);

	numberOfInputEvents = 0;
	inputEventsBufferSize = 128;
	inputEventsBuffer = new INPUT_RECORD[inputEventsBufferSize];

	mousePosition = { 0, 0 };

	// Shrinking window to minimum in order to set proper console buffer size
	SMALL_RECT minWindowSize = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(console, true, &minWindowSize);

	// Setting proper buffer size
	SetConsoleScreenBufferSize(console, bufferSize);
	SetConsoleActiveScreenBuffer(console);

	// Setting up font
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = static_cast<short>(fontWidth);
	font.dwFontSize.Y = static_cast<short>(fontHeight);
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	wcscpy_s(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(console, false, &font);

	// Setting proper console size
	SetConsoleWindowInfo(console, true, &size);

	// Hiding console cursor
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(console, &cursor);

	// Disabling select, enabling window and mouse input events
	SetConsoleMode(consoleInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

ConsoleEngine::Window::~Window()
{
	delete[] buffer;
	delete[] inputEventsBuffer;
}

void ConsoleEngine::Window::updateTitle(double deltaTime)
{
	wchar_t title[MAX_PATH];
	swprintf_s(title, MAX_PATH, L"FPS: %f", 1.0 / deltaTime);
	SetConsoleTitle(title);
}

void ConsoleEngine::Window::updateScreen()
{
	WriteConsoleOutput(console, buffer, bufferSize, start, &size);
}

void ConsoleEngine::Window::clearBuffer()
{
	memset(buffer, 0, sizeof(CHAR_INFO) * width * height);
}

bool ConsoleEngine::Window::isKeyDown(int key)
{
	return GetAsyncKeyState(key) >> 15;
}

ConsoleEngine::Point ConsoleEngine::Window::getMousePosition()
{
	GetNumberOfConsoleInputEvents(consoleInput, &numberOfInputEvents);
	if (numberOfInputEvents > 0)
	{
		ReadConsoleInput(consoleInput, inputEventsBuffer, inputEventsBufferSize, &numberOfInputEvents);
		for (DWORD i = 0; i < numberOfInputEvents; ++i)
		{
			if (inputEventsBuffer[i].EventType == MOUSE_EVENT)
			{
				mousePosition.X = inputEventsBuffer[i].Event.MouseEvent.dwMousePosition.X;
				mousePosition.Y = inputEventsBuffer[i].Event.MouseEvent.dwMousePosition.Y;
			}
		}
	}

	return Point(mousePosition.X, mousePosition.Y);
}

void ConsoleEngine::Window::drawPixel(int x, int y, PIXEL_COLOR color)
{
	if (x < 0 || x >= width ||
		y < 0 || y >= height)
		return;

	buffer[toBufferPoint(x, y)].Attributes = color;
}

void ConsoleEngine::Window::drawPixel(double x, double y, PIXEL_COLOR color)
{
	int xInt = lround(x);
	int yInt = lround(y);

	drawPixel(xInt, yInt, color);
}

void ConsoleEngine::Window::drawLine(int x0, int y0, int x1, int y1, PIXEL_COLOR color)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			drawLineLow(x1, y1, x0, y0, color);
		else
			drawLineLow(x0, y0, x1, y1, color);
	}
	else
	{
		if (y0 > y1)
			drawLineHigh(x1, y1, x0, y0, color);
		else
			drawLineHigh(x0, y0, x1, y1, color);
	}
}

void ConsoleEngine::Window::drawLine(double x0, double y0, double x1, double y1, PIXEL_COLOR color)
{
	int x0Int = lround(x0);
	int y0Int = lround(y0);
	int x1Int = lround(x1);
	int y1Int = lround(y1);

	drawLine(x0Int, y0Int, x1Int, y1Int, color);
}