#include "CartesianPoint.h"
#include <cmath>
#include <iomanip>
#include <iostream>

CartesianPoint::CartesianPoint(double r, double phi, double theta)
{
	convertingSphericalToCartesianCoordinates(r, phi, theta);
}

void CartesianPoint::convertingSphericalToCartesianCoordinates(double r, double phi, double theta)  noexcept
{
	x = r * sin(theta) * cos(phi);
	y = r * sin(theta) * sin(phi);
	z = r * cos(theta);
}

double CartesianPoint::getX() const
{
	return x;
}

double CartesianPoint::getY() const
{
	return y;
}

double CartesianPoint::getZ() const
{
	return z;
}

std::ostream& operator<<(std::ostream& os, CartesianPoint const& p)
{
	os << std::fixed << "(" << std::setprecision(2) << p.getX() << ", "
		<< std::setprecision(2) << p.getY() << ", "
		<< std::setprecision(2) << p.getZ() << ")";
	return os;
}