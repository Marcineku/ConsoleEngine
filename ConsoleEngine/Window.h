#pragma once

#include <Windows.h>

#include <string>

namespace ConsoleEngine
{
	enum TEXT_COLOR
	{
		TEXT_BLACK = 0x0000,
		TEXT_BLUE = 0x0001,
		TEXT_GREEN = 0x0002,
		TEXT_AZURE = 0x0003,
		TEXT_RED = 0x0004,
		TEXT_VIOLET = 0x0005,
		TEXT_ORANGE = 0x0006,
		TEXT_LIGHT_GREY = 0x0007,
		TEXT_GREY = 0x0008,
		TEXT_LIGHT_BLUE = 0x0009,
		TEXT_LIGHT_GREEN = 0x000A,
		TEXT_CYAN = 0x000B,
		TEXT_LIGHT_RED = 0x000C,
		TEXT_MAGENTA = 0x000D,
		TEXT_YELLOW = 0x000E,
		TEXT_WHITE = 0x000F
	};

	enum PIXEL_COLOR
	{
		PIXEL_BLACK = 0x0000,
		PIXEL_BLUE = 0x0010,
		PIXEL_GREEN = 0x0020,
		PIXEL_AZURE = 0x0030,
		PIXEL_RED = 0x0040,
		PIXEL_VIOLET = 0x0050,
		PIXEL_ORANGE = 0x0060,
		PIXEL_LIGHT_GREY = 0x0070,
		PIXEL_GREY = 0x0080,
		PIXEL_LIGHT_BLUE = 0x0090,
		PIXEL_LIGHT_GREEN = 0x00A0,
		PIXEL_CYAN = 0x00B0,
		PIXEL_LIGHT_RED = 0x00C0,
		PIXEL_MAGENTA = 0x00D0,
		PIXEL_YELLOW = 0x00E0,
		PIXEL_WHITE = 0x00F0
	};

	enum KEY
	{
		KEY_ESC = 0x1B
	};

	class Window
	{
	private:
		HANDLE console;
		HANDLE consoleInput;

		short width;
		short height;

		COORD start;
		SMALL_RECT size;

		COORD bufferSize;
		CHAR_INFO* buffer;

	public:
		Window(int windowWidth, int windowHeight, int fontWidth, int fontHeight);
		~Window();

		inline int getWidth() { return width; }
		inline int getHeight() { return height; }

		void updateFPS(double deltaTime);

		void draw();
		void clear();

		bool isKeyDown(KEY key);

		void point(int x, int y, PIXEL_COLOR color = PIXEL_WHITE);
	};
}