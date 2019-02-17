#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

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
		BUTTON_LEFT = 0x01,
		BUTTON_RIGHT = 0x02,
		BUTTON_MIDDLE = 0x04,

		KEY_BACKSPACE = 0x08,
		KEY_TAB = 0x09,
		KEY_ENTER = 0x0D,
		KEY_SHIFT = 0x10,
		KEY_CTRL = 0x11,
		KEY_ALT = 0x12,
		KEY_CAPSLOCK = 0x14,
		KEY_ESC = 0x1B,
		KEY_SPACE = 0x20,
		KEY_PAGEUP = 0x21,
		KEY_PAGEDOWN = 0x22,
		KEY_END = 0x23,
		KEY_HOME = 0x24,
		KEY_LEFT = 0x25,
		KEY_UP = 0x26,
		KEY_RIGHT = 0x27,
		KEY_DOWN = 0x28,
		KEY_PRINTSCREEN = 0x2C,
		KEY_INSERT = 0x2D,
		KEY_DELETE = 0x2E,
		KEY_0 = 0x30,
		KEY_1 = 0x31,
		KEY_2 = 0x32,
		KEY_3 = 0x33,
		KEY_4 = 0x34,
		KEY_5 = 0x35,
		KEY_6 = 0x36,
		KEY_7 = 0x37,
		KEY_8 = 0x38,
		KEY_9 = 0x39,
		KEY_A = 0x41,
		KEY_B = 0x42,
		KEY_C = 0x43,
		KEY_D = 0x44,
		KEY_E = 0x45,
		KEY_F = 0x46,
		KEY_G = 0x47,
		KEY_H = 0x48,
		KEY_I = 0x49,
		KEY_J = 0x4A,
		KEY_K = 0x4B,
		KEY_L = 0x4C,
		KEY_M = 0x4D,
		KEY_N = 0x4E,
		KEY_O = 0x4F,
		KEY_P = 0x50,
		KEY_Q = 0x51,
		KEY_R = 0x52,
		KEY_S = 0x53,
		KEY_T = 0x54,
		KEY_U = 0x55,
		KEY_V = 0x56,
		KEY_W = 0x57,
		KEY_X = 0x58,
		KEY_Y = 0x59,
		KEY_Z = 0x5A
	};

	struct Point
	{
		int x, y;
		Point()
		{
			x = 0;
			y = 0;
		}
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
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

		DWORD numberOfInputEvents;
		short inputEventsBufferSize;
		INPUT_RECORD* inputEventsBuffer;

		COORD mousePosition;

		inline int toBufferPoint(int x, int y);

		inline void drawLineLow(int x0, int y0, int x1, int y1, PIXEL_COLOR color);
		inline void drawLineHigh(int x0, int y0, int x1, int y1, PIXEL_COLOR color);
	public:
		Window(int windowWidth, int windowHeight, int fontWidth, int fontHeight);
		~Window();

		inline int getWidth() { return width; }
		inline int getHeight() { return height; }

		void updateTitle(double deltaTime);

		void updateScreen();
		void clearBuffer();

		bool isKeyDown(int key);

		Point getMousePosition();

		CONSOLEENGINE_API void drawPixel(int x, int y, PIXEL_COLOR color = PIXEL_WHITE);
		CONSOLEENGINE_API void drawPixel(double x, double y, PIXEL_COLOR color = PIXEL_WHITE);
		CONSOLEENGINE_API void drawLine(int x0, int y0, int x1, int y1, PIXEL_COLOR color = PIXEL_WHITE);
		CONSOLEENGINE_API void drawLine(double x0, double y0, double x1, double y1, PIXEL_COLOR color = PIXEL_WHITE);
	};
}