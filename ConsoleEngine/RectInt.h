#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include "Vector2Int.h"
#include "Rect.h"

#include <algorithm>
#include <string>

namespace ce
{
	struct Rect;

	struct RectInt
	{
		int x;
		int y;
		int width;
		int height;
		 
		CONSOLEENGINE_API RectInt(const int x, const int y, const int width, const int height);
		CONSOLEENGINE_API RectInt();
		CONSOLEENGINE_API RectInt(const Vector2Int& position, const int width, const int height);
		CONSOLEENGINE_API RectInt(const Vector2Int& position, const Vector2Int& size);
		CONSOLEENGINE_API RectInt(const Rect& r);

		CONSOLEENGINE_API auto operator = (RectInt rhs) -> RectInt&;

		CONSOLEENGINE_API auto swap(RectInt& r) -> void;

		CONSOLEENGINE_API auto position() const -> Vector2Int;
		CONSOLEENGINE_API auto size() const     -> Vector2Int;

		CONSOLEENGINE_API auto contains(const Vector2Int& v) const -> bool;

		CONSOLEENGINE_API auto toString() const -> std::wstring;
	};
	CONSOLEENGINE_API auto operator == (const RectInt& lhs, const RectInt& rhs) -> bool;
	CONSOLEENGINE_API auto operator != (const RectInt& lhs, const RectInt& rhs) -> bool;

	CONSOLEENGINE_API auto swap(RectInt& r1, RectInt& r2) -> void;
}