#pragma once

#include <algorithm>
#include <cmath>

namespace ce
{
	struct Vector2Int
	{
		int x;
		int y;

		Vector2Int();
		Vector2Int(const int x, const int y);
		Vector2Int(const double x, const double y);

		auto operator =  (Vector2Int rhs)        -> Vector2Int&;
		auto operator += (const Vector2Int& rhs) -> Vector2Int&;
		auto operator -= (const Vector2Int& rhs) -> Vector2Int&;

		auto swap(Vector2Int& v) -> void;
	};
	auto operator + (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;
	auto operator - (Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int;

	auto swap(Vector2Int& v1, Vector2Int& v2) -> void;
}