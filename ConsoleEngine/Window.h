#pragma once

#include "Event.h"

#include <Windows.h>
#include <vector>
#include <string_view>
#include <atomic>

namespace ce
{
	constexpr auto to_array_point(const int x, const int y, const int width) -> int
	{
		return y * width + x;
	}

	class Window
	{
	private:
		static std::atomic<bool> open;
		static auto WINAPI CtrlHandler(DWORD fdwCtrlType) -> BOOL;

		const HANDLE console;
		const HANDLE consoleInput;

		short width;
		short height;

		const COORD            screenBufferStartPoint;
		SMALL_RECT             screenBufferRect;
		COORD                  screenBufferSize;
		std::vector<CHAR_INFO> screenBuffer;

	public:
		Window(const short windowWidth, const short windowHeight, const short fontWidth, const short fontHeight);

		auto getWidth() const  -> int;
		auto getHeight() const -> int;

		auto pollEvent(Event& event) -> bool;
		auto isKeyDown(const int key) const -> bool;

		auto setTitle(std::wstring_view title) const                                               -> void;
		auto draw(const int x, const int y, const wchar_t unicodeChar, const unsigned short color) -> void;
		auto display()                                                                             -> void;
		auto clear()                                                                               -> void;

		auto isOpen() const -> bool;
		auto close()        -> void;
	};
}