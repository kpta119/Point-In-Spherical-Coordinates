#include <iostream>
#include <iomanip>
#include "../PointLib/Point.h"
#include "../PointLib/CartesianPoint.h"

int main()
{
	Point p1, p2;
	double scalar;

	std::cout << "Enter the coordinates of the first point in spherical coordinates, angles in degrees (r, phi, theta): ";
	std::cin >> p1;
	std::cout << "Enter the coordinates of the second point in spherical coordinates, angles in degrees (r, phi, theta): ";
	std::cin >> p2;
	std::cout << "Enter a scalar to multiply the points: ";
	std::cin >> scalar;

	std::cout << p1 << " + " << p2 << " = " << p1 + p2 << std::endl;
	std::cout << p1 << " - " << p2 << " = " << p1 - p2 << std::endl;
	std::cout << "Distance between " << p1 << " and " << p2 << " = " << p1.distance(p2) << std::endl;
	std::cout << "Angle between " << p1 << " and " << p2 << " = " << p1.angleBetweenVectors(p2) << std::endl;
	std::cout << p1 << " == " << p2 << " is " << (p1 == p2) << std::endl;
	std::cout << p1 << " != " << p2 << " is " << (p1 != p2) << std::endl;
	std::cout << p1 << "*" << scalar << " = " << p1 * scalar << std::endl;
	std::cout << p2 << "*" << scalar << " = " << p2 * scalar << std::endl;

	CartesianPoint cp1(p1.getR(), p1.getPhi(), p1.getTheta());
	CartesianPoint cp2(p2.getR(), p2.getPhi(), p2.getTheta());
	std::cout << "Cartesian coordinates of the first point: " << cp1 << std::endl;
	std::cout << "Cartesian coordinates of the second point: " << cp2 << std::endl;
	
}


