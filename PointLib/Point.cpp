#include "Point.h"

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}


Point Point::operator+(Point const& p) const noexcept
{
	Point resPoint(*this);
	resPoint += p;
	return resPoint;
}


Point Point::operator-(Point const& p) const noexcept
{
	Point resPoint(*this);
	resPoint -= p;
	return resPoint;
}

void Point::operator+=(Point const& p) noexcept
{
	x += p.getX();
	y += p.getY();
	z += p.getZ();
}

void Point::operator-=(Point const& p) noexcept
{
	x -= p.getX();
	y -= p.getY();
	z -= p.getZ();
}