#pragma once
#include <iostream>

class Point
{
private:
	// r is a radius from the origin of coordinate system
	// phi is an azimuthal angle
	// theta is a zenithal angle
	double r;
	double phi;
	double theta;
	double countAngleToPositiveAxisX(double x, double y) noexcept;
	void init(double r, double phi, double theta);
public:
	Point(double r = 0.0, double phi = 0.0, double theta = 0.0);
	~Point() = default;

	double getR() const;
	double getPhi() const;
	double getTheta() const;

	double* convertingSphericalToCartesianCoordinates() const noexcept;
	Point operator+(Point const& p) const noexcept;
	Point operator-(Point const& p) const noexcept;
	void operator+=(Point const& p) noexcept;
	void operator-=(Point const& p) noexcept;
	Point operator*(double const& scalar) const noexcept;
	void operator*=(double const& scalar) noexcept;


	double distance() const noexcept;
	double distance(Point const& p) const noexcept;
	double angleBetweenVectors(Point const& p) const noexcept;

	bool operator==(Point const& p) const noexcept;
	bool operator!=(Point const& p) const noexcept;
	
	friend std::ostream& operator<<(std::ostream& os, Point const& p);
	friend std::istream& operator>>(std::istream& is, Point& p);
};

