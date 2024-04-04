#include "Point.h"
#include "Constans.h"
#include "CartesianPoint.h"
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
	CartesianPoint cartesian1(r, phi, theta);
	CartesianPoint cartesian2(p.getR(), p.getPhi(), p.getTheta());
	double newX = cartesian1.getX() + cartesian2.getX();
	double newY = cartesian1.getY() + cartesian2.getY();
	double newZ = cartesian1.getZ() + cartesian2.getZ();
	convertingNewCartesianCoordinatesToSpherical(newX, newY, newZ);
}

void Point::operator-=(Point const& p) noexcept
{
	CartesianPoint cartesian1(r, phi, theta);
	CartesianPoint cartesian2(p.getR(), p.getPhi(), p.getTheta());
	double newX = cartesian1.getX() - cartesian2.getX();
	double newY = cartesian1.getY() - cartesian2.getY();
	double newZ = cartesian1.getZ() - cartesian2.getZ();
	convertingNewCartesianCoordinatesToSpherical(newX, newY, newZ);
}

double Point::distance() const noexcept
{
	return r;
}

double Point::distance(Point const& p) const noexcept
{
	CartesianPoint cartesian1(r, phi, theta);
	CartesianPoint cartesian2(p.getR(), p.getPhi(), p.getTheta());
	double distance = sqrt((cartesian1.getX()-cartesian2.getX()) * (cartesian1.getX() - cartesian2.getX()) + 
		(cartesian1.getY()-cartesian2.getY()) * (cartesian1.getY() - cartesian2.getY()) +
	(cartesian1.getZ()-cartesian2.getZ()) * (cartesian1.getZ() - cartesian2.getZ()));
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
		r *= -scalar;
		phi = fmod(phi + PI,2 * PI);
		theta = PI - theta;
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
	CartesianPoint cartesian1(r, phi, theta);
	CartesianPoint cartesian2(p.getR(), p.getPhi(), p.getTheta());
	double scalar_product = cartesian1.getX() * cartesian2.getX() + cartesian1.getY() * cartesian2.getY() + cartesian1.getZ() * cartesian2.getZ();
	double length_of_vector1 = sqrt(cartesian1.getX() * cartesian1.getX() + cartesian1.getY() * cartesian1.getY() + cartesian1.getZ() * cartesian1.getZ());
	double length_of_vector2 = sqrt(cartesian2.getX() * cartesian2.getX() + cartesian2.getY() * cartesian2.getY() + cartesian2.getZ() * cartesian2.getZ());
	double angle_cosinus = scalar_product / (length_of_vector1 * length_of_vector2);
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