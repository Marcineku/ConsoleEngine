#include "Window.h"

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
}

void ConsoleEngine::Window::updateFPS(double deltaTime)
{
	wchar_t title[MAX_PATH];
	swprintf_s(title, MAX_PATH, L"FPS: %f", 1.0 / deltaTime);
	SetConsoleTitle(title);
}

void ConsoleEngine::Window::draw()
{
	WriteConsoleOutput(console, buffer, bufferSize, start, &size);
}

void ConsoleEngine::Window::clear()
{
	memset(buffer, 0, sizeof(CHAR_INFO) * width * height);
}

bool ConsoleEngine::Window::isKeyDown(int key)
{
	return GetAsyncKeyState(key) >> 15;
}

void ConsoleEngine::Window::point(double x, double y, PIXEL_COLOR color)
{
	int bufferPoint = y * width + x;

	if (bufferPoint < 0 ||
		bufferPoint >= width * height)
		return;

	buffer[bufferPoint].Char.UnicodeChar = 0;
	buffer[bufferPoint].Attributes = color;
}