#include "Vector2.h"

ce::Vector2::Vector2()
	:
	x(0.0),
	y(0.0)
{}

ce::Vector2::Vector2(const double x, const double y)
	:
	x(x),
	y(y)
{}

ce::Vector2::Vector2(const int x, const int y)
	:
	x(static_cast<double>(x)),
	y(static_cast<double>(y))
{}

auto ce::Vector2::operator=(Vector2 rhs) -> Vector2&
{
	swap(rhs);
	return *this;
}

auto ce::Vector2::operator+=(const Vector2& rhs) -> Vector2&
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

auto ce::Vector2::operator-=(const Vector2& rhs) -> Vector2&
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

auto ce::Vector2::swap(Vector2& v) -> void
{
	std::swap(x, v.x);
	std::swap(y, v.y);
}

auto ce::operator+(Vector2 lhs, const Vector2& rhs) -> Vector2
{
	lhs += rhs;
	return lhs;
}

auto ce::operator-(Vector2 lhs, const Vector2& rhs) -> Vector2
{
	lhs -= rhs;
	return lhs;
}

auto ce::swap(Vector2& v1, Vector2& v2) -> void
{
	v1.swap(v2);
}