#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include <algorithm>
#include <cmath>

namespace ce
{
	struct Vector2Int
	{
		int x;
		int y;

		CONSOLEENGINE_API Vector2Int();
		CONSOLEENGINE_API Vector2Int(const int x, const int y);
		CONSOLEENGINE_API Vector2Int(const double x, const double y);

		CONSOLEENGINE_API auto operator =  (Vector2Int rhs)        -> Vector2Int&;
		CONSOLEENGINE_API auto operator += (const Vector2Int& rhs) -> Vector2Int&;
		CONSOLEENGINE_API auto operator -= (const Vector2Int& rhs) -> Vector2Int&;

		CONSOLEENGINE_API auto swap(Vector2Int& v) -> void;
	};
	CONSOLEENGINE_API auto operator + (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;
	CONSOLEENGINE_API auto operator - (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;

	CONSOLEENGINE_API auto swap(Vector2Int& v1, Vector2Int& v2) -> void;
}