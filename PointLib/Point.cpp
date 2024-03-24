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
	double newX = x + p.getX();
	double newY = y + p.getY();
	double newZ = z + p.getZ();
	return Point(newX, newY, newZ);
}


Point Point::operator-(Point const& p) const noexcept
{
	double newX = x - p.getX();
	double newY = y - p.getY();
	double newZ = z - p.getZ();
	return Point(newX, newY, newZ);
}