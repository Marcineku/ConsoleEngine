#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include <algorithm>

namespace ce
{
	struct Vector2
	{
		double x;
		double y;

		CONSOLEENGINE_API Vector2();
		CONSOLEENGINE_API Vector2(const double x, const double y);
		CONSOLEENGINE_API Vector2(const int x, const int y);

		CONSOLEENGINE_API auto operator =  (Vector2 rhs)        -> Vector2&;
		CONSOLEENGINE_API auto operator += (const Vector2& rhs) -> Vector2&;
		CONSOLEENGINE_API auto operator -= (const Vector2& rhs) -> Vector2&;

		CONSOLEENGINE_API auto swap(Vector2& v) -> void;
	};
	CONSOLEENGINE_API auto operator + (Vector2 lhs, const Vector2& rhs) -> Vector2;
	CONSOLEENGINE_API auto operator - (Vector2 lhs, const Vector2& rhs) -> Vector2;

	CONSOLEENGINE_API auto swap(Vector2& v1, Vector2& v2) -> void;
}