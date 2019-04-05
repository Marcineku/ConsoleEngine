#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include "Vector2.h"
#include "RectInt.h"

#include <algorithm>
#include <string>

namespace ce
{
	struct RectInt;

	struct Rect
	{
		double x;
		double y;
		double width;
		double height;

		CONSOLEENGINE_API Rect(const double x, const double y, const double width, const double height);
		CONSOLEENGINE_API Rect();
		CONSOLEENGINE_API Rect(const Vector2& position, const double width, const double height);
		CONSOLEENGINE_API Rect(const Vector2& position, const Vector2& size);
		CONSOLEENGINE_API Rect(const RectInt& r);

		CONSOLEENGINE_API auto operator = (Rect rhs) -> Rect&;

		CONSOLEENGINE_API auto swap(Rect& r) -> void;

		CONSOLEENGINE_API auto position() const -> Vector2;
		CONSOLEENGINE_API auto size() const     -> Vector2;
		CONSOLEENGINE_API auto center() const   -> Vector2;

		CONSOLEENGINE_API auto contains(const Vector2& v) const -> bool;
		CONSOLEENGINE_API auto overlaps(const Rect& r) const    -> bool;

		CONSOLEENGINE_API auto toString() const -> std::wstring;
	};
	CONSOLEENGINE_API auto operator == (const Rect& lhs, const Rect& rhs) -> bool;
	CONSOLEENGINE_API auto operator != (const Rect& lhs, const Rect& rhs) -> bool;

	CONSOLEENGINE_API auto swap(Rect& r1, Rect& r2) -> void;
}