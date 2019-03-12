#include "Vector2Int.h"

ce::Vector2Int::Vector2Int(const int x, const int y)
	:
	x(x),
	y(y)
{}

ce::Vector2Int::Vector2Int(const unsigned int x, unsigned const int y)
	:
	Vector2Int(static_cast<int>(x), static_cast<int>(y))
{}

ce::Vector2Int::Vector2Int()
	:
	Vector2Int(0, 0)
{}

ce::Vector2Int::Vector2Int(const double x, const double y)
	:
	Vector2Int(std::lround(x), std::lround(y))
{}

ce::Vector2Int::Vector2Int(const Vector2& v)
	:
	Vector2Int(v.x, v.y)
{}

auto ce::Vector2Int::operator=(Vector2Int rhs) -> Vector2Int&
{
	swap(rhs);
	return *this;
}

auto ce::Vector2Int::operator+=(const Vector2Int& rhs) -> Vector2Int&
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

auto ce::Vector2Int::operator-=(const Vector2Int& rhs) -> Vector2Int&
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

auto ce::Vector2Int::operator*=(const int rhs) -> Vector2Int &
{
	x *= rhs;
	y *= rhs;
	return *this;
}

auto ce::Vector2Int::operator/=(const int rhs) -> Vector2Int &
{
	x /= rhs;
	y /= rhs;
	return *this;
}

auto ce::Vector2Int::swap(Vector2Int& v) -> void
{
	std::swap(x, v.x);
	std::swap(y, v.y);
}

auto ce::Vector2Int::sqrMagnitude() const -> double
{
	return x * x + y * y;
}

auto ce::Vector2Int::magnitude() const -> double
{
	return std::sqrt(sqrMagnitude());
}

auto ce::Vector2Int::distance(const Vector2Int& v) const -> double
{
	return (*this - v).magnitude();
}

auto ce::Vector2Int::toString() const -> std::wstring
{
	return L"x:" + std::to_wstring(x) + L" y:" + std::to_wstring(y);
}

auto ce::operator+(Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int
{
	lhs += rhs;
	return lhs;
}

auto ce::operator-(Vector2Int lhs, const Vector2Int& rhs) -> Vector2Int
{
	lhs -= rhs;
	return lhs;
}

auto ce::operator*(Vector2Int lhs, const int rhs) -> Vector2Int
{
	lhs *= rhs;
	return lhs;
}

auto ce::operator/(Vector2Int lhs, const int rhs) -> Vector2Int
{
	lhs /= rhs;
	return lhs;
}

auto ce::operator==(const Vector2Int& lhs, const Vector2Int& rhs) -> bool
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

auto ce::operator!=(const Vector2Int& lhs, const Vector2Int& rhs) -> bool
{
	return !operator==(lhs, rhs);
}

auto ce::swap(Vector2Int& v1, Vector2Int& v2) -> void
{
	v1.swap(v2);
}

auto ce::distance(const Vector2Int& v1, const Vector2Int& v2) -> double
{
	return v1.distance(v2);
}