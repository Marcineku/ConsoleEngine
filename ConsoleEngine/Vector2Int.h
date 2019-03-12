#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include "Vector2.h"

#include <algorithm>
#include <cmath>
#include <string>

namespace ce
{
	struct Vector2;

	struct Vector2Int
	{
		int x;
		int y;

		CONSOLEENGINE_API Vector2Int(const int x, const int y);
		CONSOLEENGINE_API Vector2Int(const unsigned int x, unsigned const int y);
		CONSOLEENGINE_API Vector2Int();
		CONSOLEENGINE_API Vector2Int(const double x, const double y);
		CONSOLEENGINE_API Vector2Int(const Vector2& v);

		CONSOLEENGINE_API auto operator =  (Vector2Int rhs)        -> Vector2Int&;
		CONSOLEENGINE_API auto operator += (const Vector2Int& rhs) -> Vector2Int&;
		CONSOLEENGINE_API auto operator -= (const Vector2Int& rhs) -> Vector2Int&;
		CONSOLEENGINE_API auto operator *= (const int rhs)         -> Vector2Int&;
		CONSOLEENGINE_API auto operator /= (const int rhs)         -> Vector2Int&;

		CONSOLEENGINE_API auto swap(Vector2Int& v) -> void;

		CONSOLEENGINE_API auto sqrMagnitude() const                -> double;
		CONSOLEENGINE_API auto magnitude() const                   -> double;
		CONSOLEENGINE_API auto distance(const Vector2Int& v) const    -> double;

		CONSOLEENGINE_API auto toString() const -> std::wstring;
	};
	CONSOLEENGINE_API auto operator + (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;
	CONSOLEENGINE_API auto operator - (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;
	CONSOLEENGINE_API auto operator * (Vector2Int lhs, const int rhs)         -> Vector2Int;
	CONSOLEENGINE_API auto operator / (Vector2Int lhs, const int rhs)         -> Vector2Int;

	CONSOLEENGINE_API auto operator == (const Vector2Int& lhs, const Vector2Int& rhs) -> bool;
	CONSOLEENGINE_API auto operator != (const Vector2Int& lhs, const Vector2Int& rhs) -> bool;

	CONSOLEENGINE_API auto swap(Vector2Int& v1, Vector2Int& v2) -> void;

	CONSOLEENGINE_API auto distance(const Vector2Int& v1, const Vector2Int& v2) -> double;
}