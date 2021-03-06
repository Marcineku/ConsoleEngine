#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include "Window.h"
#include "Pixel.h"
#include "Text.h"
#include "Event.h"
#include "Key.h"
#include "Mouse.h"
#include "Vector2Int.h"
#include "RectInt.h"

#include <chrono>
#include <array>
#include <sstream>
#include <string_view>

namespace ce
{
	template <typename T>
	constexpr typename std::underlying_type<T>::type to_underlying(T t)
	{
		return static_cast<typename std::underlying_type_t<T>>(t);
	}

	class Engine
	{
	private:
		std::wstring title;

		Window window;

		std::array<bool, 256> wasKeyDown;
		std::array<bool, 256> isKeyDown;

		Vector2Int mousePosition;
		
		auto isHeld(const int keyCode) const     -> bool;
		auto isPressed(const int keyCode) const  -> bool;
		auto isReleased(const int keyCode) const -> bool;

		auto checkMouseButtonsState() -> void;

		auto drawLineLow(const int x0, int y0, const int x1, const int y1, const Pixel::Color color, const Text::Type type, const Text::Color fill)  -> void;
		auto drawLineHigh(int x0, const int y0, const int x1, const int y1, const Pixel::Color color, const Text::Type type, const Text::Color fill) -> void;

	protected:
		virtual void update(const double deltaTime) = 0;

	public:
		CONSOLEENGINE_API Engine(const int consoleWidth, const int consoleHeight, const int fontWidth, const int fontHeight, const std::wstring_view title);

		CONSOLEENGINE_API auto start() -> void;
		CONSOLEENGINE_API auto close() -> void;

		CONSOLEENGINE_API auto getWindowWidth() const                          -> int;
		CONSOLEENGINE_API auto getWindowHeight() const                         -> int;

		CONSOLEENGINE_API auto isKeyHeld(const Key key) const                  -> bool;
		CONSOLEENGINE_API auto isKeyPressed(const Key key) const               -> bool;
		CONSOLEENGINE_API auto isKeyReleased(const Key key) const              -> bool;

		CONSOLEENGINE_API auto isKeyHeld(const Mouse button) const     -> bool;
		CONSOLEENGINE_API auto isKeyPressed(const Mouse button) const  -> bool;
		CONSOLEENGINE_API auto isKeyReleased(const Mouse button) const -> bool;

		CONSOLEENGINE_API auto getMousePosition() const -> Vector2Int;

		CONSOLEENGINE_API auto draw(const int    x, const int    y, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                                     -> void;
		CONSOLEENGINE_API auto draw(const double x, const double y, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                                     -> void;
		CONSOLEENGINE_API auto draw(const Vector2Int& point, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                                            -> void;

		CONSOLEENGINE_API auto draw(const int    x0, const int    y0, const int    x1, const int    y1, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White) -> void;
		CONSOLEENGINE_API auto draw(const double x0, const double y0, const double x1, const double y1, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White) -> void;
		CONSOLEENGINE_API auto draw(const Vector2Int& p0, const Vector2Int& p1, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                         -> void;
		CONSOLEENGINE_API auto draw(const std::pair<Vector2Int, Vector2Int>& line, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                      -> void;

		CONSOLEENGINE_API auto draw(const Vector2Int& position, const int width, const int height, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                   -> void;
		CONSOLEENGINE_API auto draw(const RectInt& rect, const Pixel::Color color = Pixel::Color::White, const Text::Type type = Text::Type::None, const Text::Color fill = Text::Color::White)                                                -> void;

		CONSOLEENGINE_API auto draw(const int    x, const int    y, const wchar_t           unicodeChar, const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                          -> void;
		CONSOLEENGINE_API auto draw(const int    x, const int    y, const std::wstring_view text,        const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                          -> void;
		CONSOLEENGINE_API auto draw(const double x, const double y, const wchar_t           unicodeChar, const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                          -> void;
		CONSOLEENGINE_API auto draw(const double x, const double y, const std::wstring_view text,        const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                          -> void;
		CONSOLEENGINE_API auto draw(const Vector2Int& point, const wchar_t           unicodeChar, const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                                 -> void;
		CONSOLEENGINE_API auto draw(const Vector2Int& point, const std::wstring_view text,        const Text::Color color = Text::Color::White, const Pixel::Color fill = Pixel::Color::Black)                                                 -> void;
	};
}