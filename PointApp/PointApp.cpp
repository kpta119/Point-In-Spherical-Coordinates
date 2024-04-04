#include <iostream>
#include <iomanip>
#include "../PointLib/Point.h"

int main()
{
	Point p1, p2;

	std::cout << "Enter the coordinates of the first point in spherical coordinates (r, phi, theta): ";
	std::cin >> p1;
	std::cout << "Enter the coordinates of the second point in spherical coordinates (r, phi, theta): ";
	std::cin >> p2;


	std::cout<< p1 << " + " << p2 << " = " << p1 + p2 << std::endl;
	std::cout << p1 << " - " << p2 << " = " << p1 - p2 << std::endl;
	std::cout << "Distance between " << p1 << " and " << p2 << " = " << p1.distance(p2) << std::endl;
	std::cout << "Angle between " << p1 << " and " << p2 << " = " << p1.angleBetweenVectors(p2) << std::endl;
	std::cout << p1 << " == " << p2 << " is " << (p1 == p2) << std::endl;
	std::cout << p1 << " != " << p2 << " is " << (p1 != p2) << std::endl;
	
	double* cartesian1 = p1.convertingSphericalToCartesianCoordinates();
	double* cartesian2 = p2.convertingSphericalToCartesianCoordinates();
	std::cout << std::fixed << "The first point in cartesian coordinates: " << "(" <<
		std::setprecision(2) << cartesian1[0] << ", " << std::setprecision(2) <<
		cartesian1[1] << ", " << std::setprecision(2) << cartesian1[2] << ")" << std::endl;
	std::cout << std::fixed << "The second point in cartesian coordinates: " << "(" <<
		std::setprecision(2) << cartesian2[0] << ", " << std::setprecision(2) <<
		cartesian2[1] << ", " << std::setprecision(2) << cartesian2[2] << ")" << std::endl;

}


