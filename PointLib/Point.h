#pragma once
class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0);
	~Point() = default;

	double getX() const;
	double getY() const;
	double getZ() const;

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

