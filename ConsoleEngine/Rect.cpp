#include "Rect.h"

ce::Rect::Rect(const double x, const double y, const double width, const double height)
	:
	x(x),
	y(y),
	width(width),
	height(height)
{}

ce::Rect::Rect()
	:
	Rect(0.0, 0.0, 0.0, 0.0)
{}

ce::Rect::Rect(const Vector2& position, const double width, const double height)
	:
	Rect(position.x, position.y, width, height)
{}

ce::Rect::Rect(const Vector2& position, const Vector2& size)
	:
	Rect(position, size.x, size.y)
{}

ce::Rect::Rect(const RectInt& r)
	:
	Rect(r.position(), r.size())
{}

auto ce::Rect::operator=(Rect rhs) -> Rect&
{
	swap(rhs);
	return *this;
}

auto ce::Rect::swap(Rect& r) -> void
{
	std::swap(x, r.x);
	std::swap(y, r.y);
	std::swap(width, r.width);
	std::swap(height, r.height);
}

auto ce::Rect::position() const -> Vector2
{
	return Vector2(x, y);
}

auto ce::Rect::size() const -> Vector2
{
	return Vector2(width, height);
}

auto ce::Rect::center() const -> Vector2
{
	return Vector2(x + width / 2, y + height / 2);
}

auto ce::Rect::contains(const Vector2& v) const -> bool
{
	return v.x >= x && v.x <= x + width  - 1.0 &&
		   v.y >= y && v.y <= y + height - 1.0;
}

auto ce::Rect::overlaps(const Rect& r) const -> bool
{
	if (x + width  < r.x || x > r.x + r.width ) return false;
	if (y + height < r.y || y > r.y + r.height) return false;

	return true;
}

auto ce::Rect::toString() const -> std::wstring
{
	return L"x:" + std::to_wstring(x) + L" y:" + std::to_wstring(y) + L" w:" + std::to_wstring(width) + L" h:" + std::to_wstring(height);
}

auto ce::operator==(const Rect& lhs, const Rect& rhs) -> bool
{
	return lhs.size() == rhs.size();
}

auto ce::operator!=(const Rect& lhs, const Rect& rhs) -> bool
{
	return !operator==(lhs, rhs);
}

auto ce::swap(Rect& r1, Rect& r2) -> void
{
	r1.swap(r2);
}