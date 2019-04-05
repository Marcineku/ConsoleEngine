#pragma once

#ifdef CONSOLEENGINE_EXPORTS
#define CONSOLEENGINE_API __declspec(dllexport)
#else
#define CONSOLEENGINE_API __declspec(dllimport)
#endif

#include "Vector2Int.h"

#include <algorithm>
#include <string>

namespace ce
{
	struct Vector2Int;

	struct Vector2
	{
		static constexpr double approx_equality_diff = 1e-10;

		double x;
		double y;

		CONSOLEENGINE_API Vector2(const double x, const double y);
		CONSOLEENGINE_API Vector2();
		CONSOLEENGINE_API Vector2(const int x, const int y);
		CONSOLEENGINE_API Vector2(const unsigned int x, unsigned const int y);
		CONSOLEENGINE_API Vector2(const Vector2Int& v);

		CONSOLEENGINE_API auto operator =  (Vector2 rhs)        -> Vector2&;
		CONSOLEENGINE_API auto operator += (const Vector2& rhs) -> Vector2&;
		CONSOLEENGINE_API auto operator -= (const Vector2& rhs) -> Vector2&;
		CONSOLEENGINE_API auto operator *= (const double rhs)   -> Vector2&;
		CONSOLEENGINE_API auto operator /= (const double rhs)   -> Vector2&;

		CONSOLEENGINE_API auto swap(Vector2& v) -> void;

		CONSOLEENGINE_API auto sqrMagnitude() const             -> double;
		CONSOLEENGINE_API auto magnitude() const                -> double;
		CONSOLEENGINE_API auto distance(const Vector2& v) const -> double;
		CONSOLEENGINE_API auto normalized() const               -> Vector2;

		CONSOLEENGINE_API auto normalize()                      -> void;

		CONSOLEENGINE_API auto toString() const -> std::wstring;
	};
	CONSOLEENGINE_API auto operator + (Vector2 lhs, const Vector2& rhs) -> Vector2;
	CONSOLEENGINE_API auto operator - (Vector2 lhs, const Vector2& rhs) -> Vector2;
	CONSOLEENGINE_API auto operator * (Vector2 lhs, const double rhs)   -> Vector2;
	CONSOLEENGINE_API auto operator / (Vector2 lhs, const double rhs)   -> Vector2;

	CONSOLEENGINE_API auto operator == (const Vector2& lhs, const Vector2& rhs) -> bool;
	CONSOLEENGINE_API auto operator != (const Vector2& lhs, const Vector2& rhs) -> bool;

	CONSOLEENGINE_API auto swap(Vector2& v1, Vector2& v2) -> void;

	CONSOLEENGINE_API auto distance(const Vector2& v1, const Vector2& v2) -> double;
}