#include "RectInt.h"

ce::RectInt::RectInt(const int x, const int y, const int width, const int height)
	:
	x(x),
	y(y),
	width(width),
	height(height)
{}

ce::RectInt::RectInt()
	:
	RectInt(0, 0, 0, 0)
{}

ce::RectInt::RectInt(const Vector2Int& position, const int width, const int height)
	:
	RectInt(position.x, position.y, width, height)
{}

ce::RectInt::RectInt(const Vector2Int& position, const Vector2Int& size)
	:
	RectInt(position, size.x, size.y)
{}

ce::RectInt::RectInt(const Rect& r)
	:
	RectInt(r.position(), r.size())
{}

auto ce::RectInt::operator=(RectInt rhs) -> RectInt&
{
	swap(rhs);
	return *this;
}

auto ce::RectInt::swap(RectInt& r) -> void
{
	std::swap(x, r.x);
	std::swap(y, r.y);
	std::swap(width, r.width);
	std::swap(height, r.height);
}

auto ce::RectInt::position() const -> Vector2Int
{
	return Vector2Int(x, y);
}

auto ce::RectInt::size() const -> Vector2Int
{
	return Vector2Int(width, height);
}

auto ce::RectInt::contains(const Vector2Int& v) const -> bool
{
	return v.x >= x && v.x <= x + width  - 1 &&
		   v.y >= y && v.y <= y + height - 1;
}

auto ce::RectInt::toString() const -> std::wstring
{
	return L"x:" + std::to_wstring(x) + L" y:" + std::to_wstring(y) + L" w:" + std::to_wstring(width) + L" h:" + std::to_wstring(height);
}

auto ce::operator==(const RectInt& lhs, const RectInt& rhs) -> bool
{
	return lhs.size() == rhs.size();
}

auto ce::operator!=(const RectInt& lhs, const RectInt& rhs) -> bool
{
	return !operator==(lhs, rhs);
}

auto ce::swap(RectInt& r1, RectInt& r2) -> void
{
	r1.swap(r2);
}