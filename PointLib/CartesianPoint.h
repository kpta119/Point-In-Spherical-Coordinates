#pragma once
#include <iostream>

class CartesianPoint
{
private:
	double x;
	double y;
	double z;
	void convertingSphericalToCartesianCoordinates(double r, double phi, double theta) noexcept;
public:
	CartesianPoint(double r = 0.0, double phi = 0.0, double theta = 0.0);
	~CartesianPoint() = default;
	double getX() const;
	double getY() const;
	double getZ() const;

	friend std::ostream& operator<<(std::ostream& is, CartesianPoint const& p);

};

