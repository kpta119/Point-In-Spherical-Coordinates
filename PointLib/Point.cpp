#include "Point.h"
#include "Constans.h"
#include <iostream>
#include <cmath>
#include <iomanip>


void Point::init(double r, double phi, double theta)
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

Point::Point(double r, double phi, double theta)
{
	init(r, phi, theta);
}


double Point::countAngleToPositiveAxisX(double x, double y) noexcept
{
	double scalar_product = x * 1 + y * 0;
	double length_of_vector = sqrt(x * x + y * y);
	if ( length_of_vector-0.0 <= 1e-6) 
	{
		return 0.0;
	}
	double angle_cosinus = scalar_product / length_of_vector;
	double angle = 0;

	if ((x < -1e-6 && y < -1e-6) || (x > 1e-6 && y < -1e-6))
	{
		angle = 2*PI - acos(angle_cosinus);
	}
	else
	{
		angle = acos(angle_cosinus);
	}
	return angle;

}

void Point::convertingNewCartesianCoordinatesToSpherical(double x, double y, double z) noexcept
{
	r = sqrt(x * x + y * y + z * z);
	phi = countAngleToPositiveAxisX(x, y);
	if (r - 0.0 >= 1e-6)
	{
		theta = acos(z / r);
	}
	else
	{
		theta = 0.0;
	}
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
	convertingNewCartesianCoordinatesToSpherical(newX, newY, newZ);
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
	convertingNewCartesianCoordinatesToSpherical(newX, newY, newZ);
	delete[] cartesian1; 
	delete[] cartesian2;
}

double Point::distance() const noexcept
{
	return r;
}

double Point::distance(Point const& p) const noexcept
{
	double* cartesian1 = convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p.convertingSphericalToCartesianCoordinates();
	double x1 = *cartesian1;
	double y1 = *(cartesian1 + 1);
	double z1 = *(cartesian1 + 2);
	double x2 = *cartesian2;
	double y2 = *(cartesian2 + 1);
	double z2 = *(cartesian2 + 2);
	double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	delete[] cartesian1;
	delete[] cartesian2;
	return distance;
}

Point Point::operator*(double const& scalar) const noexcept
{
	Point resPoint(*this);
	resPoint *= scalar;
	return resPoint;
}

void Point::operator*=(double const& scalar) noexcept
{	
	if (scalar > 1e-6)
	{
		r *= scalar;
	}
	else if (scalar < -1e-6)
	{
		r *= scalar;
		phi = fmod(phi + PI,2 * PI);
		theta = fmod(theta - PI, PI);
	}
	else
	{
		r = 0;
		phi = 0;
		theta = 0;
	}
	
}

double Point::angleBetweenVectors(Point const& p) const noexcept
{
	double* cartesian1 = convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p.convertingSphericalToCartesianCoordinates();
	double x1 = *cartesian1;
	double y1 = *(cartesian1 + 1);
	double z1 = *(cartesian1 + 2);
	double x2 = *cartesian2;
	double y2 = *(cartesian2 + 1);
	double z2 = *(cartesian2 + 2);
	double scalar_product = x1 * x2 + y1 * y2 + z1 * z2;
	double length_of_vector1 = sqrt(x1 * x1 + y1 * y1 + z1 * z1);
	double length_of_vector2 = sqrt(x2 * x2 + y2 * y2 + z2 * z2);
	double angle_cosinus = scalar_product / (length_of_vector1 * length_of_vector2);
	delete[] cartesian1;
	delete[] cartesian2;
	return acos(angle_cosinus) * 180 / PI;
}


bool Point::operator==(Point const& p) const noexcept
{
	return (abs(r - p.getR()) < 1e-6 && abs(phi - p.getPhi()) < 1e-6 && abs(theta - p.getTheta()) < 1e-6);
}

bool Point::operator!=(Point const& p) const noexcept
{
	return !(*this == p);
}


std::ostream& operator<<(std::ostream& os, Point const& p)
{
	os << std::fixed << "(" << std::setprecision(2) << p.getR() << ", "
		<< std::setprecision(2) << p.getPhi() * 180 / PI << ", "
		<< std::setprecision(2) << p.getTheta() * 180 / PI << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
	is >> p.r;
	char c = is.get();
	if (c != ',')
	{
		is.unget();
		is.setstate(std::ios::failbit);
		return is;

	}
	is >> p.phi;
	c = is.get();
	if (c != ',')
	{
		is.unget();
		is.setstate(std::ios::failbit);
		return is;
	}
	is >> p.theta;
	p.init(p.r, p.phi, p.theta);
	return is;
}