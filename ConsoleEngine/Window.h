#pragma once

#include <Windows.h>
#include <string>

namespace ConsoleEngine
{
	class Window
	{
	private:
		HANDLE console;
		HANDLE consoleInput;

		short width;
		short height;

		SMALL_RECT size;

		COORD bufferSize;
		CHAR_INFO* buffer;

	public:
		Window(int windowWidth, int windowHeight, int fontWidth = 8, int fontHeight = 8);
		~Window();
	};
}