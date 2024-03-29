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
	if (phi < 0 || phi >= 360)
	{
		throw std::invalid_argument("Azimuth angle must be in the range [0, 360).");
	}
	if (theta < 0 || theta > 180)
	{
		throw std::invalid_argument("Zenithal angle must be in the range[0, 180]");
	}
	
	this->r = r;
	this->phi = phi * (PI / 180);
	this->theta = theta * (PI / 180);
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
	double newX = cartesian1[0] + cartesian2[0];
	double newY = cartesian1[1] + cartesian2[1];
	double newZ = cartesian1[2] + cartesian2[2];
	r = sqrt(pow(newX, 2) + pow(newY, 2) + pow(newZ, 2));
	phi = acos(newX / r);
	theta = acos(newZ / r);
	delete[] cartesian1; 
	delete[] cartesian2;
}

void Point::operator-=(Point const& p) noexcept
{
	double* cartesian1 = convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p.convertingSphericalToCartesianCoordinates();
	double newX = cartesian1[0] - cartesian2[0];
	double newY = cartesian1[1] - cartesian2[1];
	double newZ = cartesian1[2] - cartesian2[2];
	r = sqrt(pow(newX, 2) + pow(newY, 2) + pow(newZ, 2));
	phi = acos(newX / r);
	theta = acos(newZ / r);
	delete[] cartesian1; 
	delete[] cartesian2;
}