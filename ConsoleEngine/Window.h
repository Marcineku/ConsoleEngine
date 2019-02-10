#pragma once

#include <Windows.h>

#include <string>

namespace ConsoleEngine
{
	enum COLOR
	{

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

		void point(int x, int y);
	};
}