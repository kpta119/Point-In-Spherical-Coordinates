#pragma once
#include <iostream>
class Point
{
private:
	double r;
	double phi;
	double theta;
	int countAngleToPositiveAxisX(double x, double y) noexcept;
public:
	Point(double r = 0.0, double phi = 0.0, double theta = 0.0);
	~Point() = default;

	double getR() const;
	double getPhi() const;
	double getTheta() const;

	double* convertingSphericalToCartesianCoordinates() const noexcept;
	Point operator+(Point const& p) const noexcept;
	Point operator-(Point const& p) const noexcept;

	void operator+(const double vec[]);
	void operator-(const double vec[]);

	double distance() const noexcept;
	double distance(Point const& p) const noexcept;

	Point middleOfSegment() const noexcept;
	Point middleOfSegment(Point const& p) const noexcept;

	void operator*(double const& v) noexcept;

	void operator+=(Point const& p) noexcept;
	void operator-=(Point const& p) noexcept;

	bool operator==(Point const& p) const noexcept;
	bool operator!=(Point const& p) const noexcept;

	friend std::ostream& operator<< (std::ostream& os, Point const& p);
	friend std::istream& operator>> (std::istream& is, Point& p);
};

