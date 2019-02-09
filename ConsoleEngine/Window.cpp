#include "Window.h"

ConsoleEngine::Window::Window(int windowWidth, int windowHeight, int fontWidth, int fontHeight)
{
	// Initializing private fields
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleInput = GetStdHandle(STD_INPUT_HANDLE);

	width = static_cast<short>(windowWidth);
	height = static_cast<short>(windowHeight);

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
}

ConsoleEngine::Window::~Window()
{
	delete[] buffer;
}