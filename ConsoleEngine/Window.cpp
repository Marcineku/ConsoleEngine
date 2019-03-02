#include "Window.h"

std::atomic<bool> ce::Window::open(false);

auto __stdcall ce::Window::CtrlHandler(DWORD fdwCtrlType) -> BOOL
{
	open = false;
	return true;
}

ce::Window::Window(const short windowWidth, const short windowHeight, const short fontWidth, const short fontHeight)
	:
	console(GetStdHandle(STD_OUTPUT_HANDLE)),
	consoleInput(GetStdHandle(STD_INPUT_HANDLE)),
	width(windowWidth),
	height(windowHeight),
	screenBufferStartPoint({ 0, 0 }),
	screenBufferRect({ 0, 0, windowWidth - 1, windowHeight - 1 }),
	screenBufferSize({ windowWidth, windowHeight }),
	screenBuffer(windowWidth * windowHeight)
{
	// Shrinking window to minimum in order to set proper console buffer size
	SMALL_RECT minWindowSize = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(console, true, &minWindowSize);

	// Setting proper buffer size
	SetConsoleScreenBufferSize(console, screenBufferSize);
	SetConsoleActiveScreenBuffer(console);

	// Setting up font
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = fontWidth;
	font.dwFontSize.Y = fontHeight;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	wcscpy_s(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(console, false, &font);

	// Setting proper console size
	SetConsoleWindowInfo(console, true, &screenBufferRect);

	// Hiding console cursor
	CONSOLE_CURSOR_INFO cursor = { 1, false };
	SetConsoleCursorInfo(console, &cursor);

	// Disabling select, enabling window and mouse input events
	SetConsoleMode(consoleInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	// Setting up window close conditions
	open = true;
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
}

auto ce::Window::getWidth() const -> int
{
	return width;
}

auto ce::Window::getHeight() const -> int
{
	return height;
}

auto ce::Window::pollEvent(Event& event) -> bool
{
	DWORD numberOfInputEvents;
	GetNumberOfConsoleInputEvents(consoleInput, &numberOfInputEvents);
	if (numberOfInputEvents > 0)
	{
		INPUT_RECORD inputRecord;
		ReadConsoleInput(consoleInput, &inputRecord, 1, &numberOfInputEvents);
		
		switch (inputRecord.EventType)
		{
		case KEY_EVENT:
			event.type = Event::Type::KeyStateChange;
			event.keyState.key = static_cast<Key>(inputRecord.Event.KeyEvent.wVirtualKeyCode);
			event.keyState.isDown = inputRecord.Event.KeyEvent.bKeyDown;
			break;
		case MOUSE_EVENT:
			event.type = Event::Type::MouseMove;
			event.mousePosition.x = inputRecord.Event.MouseEvent.dwMousePosition.X;
			event.mousePosition.y = inputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		case WINDOW_BUFFER_SIZE_EVENT:
			width = inputRecord.Event.WindowBufferSizeEvent.dwSize.X;
			height = inputRecord.Event.WindowBufferSizeEvent.dwSize.Y;

			event.type = Event::Type::WindowResize;
			event.windowSize.x = width;
			event.windowSize.y = height;

			screenBufferRect = { 0, 0, width - 1, height - 1 };
			screenBufferSize = { width, height };
			screenBuffer.resize(width * height);
			break;
		default:
			break;
		}
		
		return true;
	}

	return false;
}

auto ce::Window::isKeyDown(const int key) const -> bool
{
	return GetAsyncKeyState(key) >> 15;
}

auto ce::Window::setTitle(std::wstring_view title) const -> void
{
	SetConsoleTitle(title.data());
}

auto ce::Window::draw(const int x, const int y, const wchar_t unicodeChar, const unsigned short color) -> void
{
	int arrayPoint = to_array_point(x, y, width);
	if (x >= 0 && x < width &&
		y >= 0 && y < height)
	{
		screenBuffer[arrayPoint].Char.UnicodeChar = unicodeChar;
		screenBuffer[arrayPoint].Attributes = color;
	}
}

auto ce::Window::display() -> void
{
	WriteConsoleOutput(console, screenBuffer.data(), screenBufferSize, screenBufferStartPoint, &screenBufferRect);
}

auto ce::Window::clear() -> void
{
	std::memset(screenBuffer.data(), 0, sizeof(CHAR_INFO) * width * height);
}

auto ce::Window::isOpen() const -> bool
{
	return open;
}

auto ce::Window::close() -> void
{
	open = false;
}