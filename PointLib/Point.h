#pragma once
class Point
{
private:
	double r;
	double phi;
	double theta;
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

	void operator+=(Point const& p) noexcept;
	void operator-=(Point const& p) noexcept;

};

