#include "Point.h"
#include "Constans.h"
#include <iostream>
#include <cmath>

Point::Point(double r, double phi, double theta)
{
	if (r < 0)
	{
		throw std::invalid_argument("Radius (r) must be equal to or greater than 0.");
	}
	if (phi < 0 || phi > PI)
	{
		throw std::invalid_argument("Phi must be in the range [0, pi].");
	}
	if (theta < 0 || theta >= 2 * PI)
	{
		throw std::invalid_argument("theta must be in the range [0, 2*pi)");
	}
	
	this->r = r;
	this->phi = phi;
	this->theta = theta;
}

double* Point::convertingSphericalToCartesianCoordinates() const noexcept
{
	double *cartesian = new double[3];
	cartesian[0] = r * sin(theta) * cos(phi);
	cartesian[1] = r * sin(theta) * sin(phi);
	cartesian[2] = r * cos(theta);
	return cartesian;
}

double Point::getR() const
{
	return r;
}

double Point::getPhi() const
{
	return phi;
}

double Point::getTheta() const
{
	return theta;
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
	double* cartesian1 = convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p.convertingSphericalToCartesianCoordinates();
	cartesian1[0] += cartesian2[0];
	cartesian1[1] += cartesian2[1];
	cartesian1[2] += cartesian2[2];
	r = sqrt(pow(cartesian1[0], 2) + pow(cartesian1[1], 2) + pow(cartesian1[2], 2));
	phi = acos(cartesian1[0] / r);
	theta = acos(cartesian1[2] / r);
}

void Point::operator-=(Point const& p) noexcept
{
	double* cartesian1 = convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p.convertingSphericalToCartesianCoordinates();
	cartesian1[0] -= cartesian2[0];
	cartesian1[1] -= cartesian2[1];
	cartesian1[2] -= cartesian2[2];
	r = sqrt(pow(cartesian1[0], 2) + pow(cartesian1[1], 2) + pow(cartesian1[2], 2));
	phi = acos(cartesian1[0] / r);
	theta = acos(cartesian1[2] / r);
}