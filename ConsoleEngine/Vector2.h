#pragma once

#include <algorithm>

namespace ce
{
	struct Vector2
	{
		double x;
		double y;

		Vector2();
		Vector2(const double x, const double y);
		Vector2(const int x, const int y);
		  
		auto operator =  (Vector2 rhs)        -> Vector2&;
		auto operator += (const Vector2& rhs) -> Vector2&;
		auto operator -= (const Vector2& rhs) -> Vector2&;

		auto swap(Vector2& v) -> void;
	};
	auto operator + (Vector2 lhs, const Vector2& rhs) -> Vector2;
	auto operator - (Vector2 lhs, const Vector2& rhs) -> Vector2;

	auto swap(Vector2& v1, Vector2& v2) -> void;
}