#include "../PointLib/Point.h"
#include "../PointLib/Constans.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(TestPointConstructor, ConstructorWithGivenCoordinates)
{
	Point p1(1.0, 90.0, 90.0);
	EXPECT_NEAR(p1.getR(), 1.0, 0.001);
	EXPECT_NEAR(p1.getPhi(), 1.57, 0.001);
	EXPECT_NEAR(p1.getTheta(), 1.57, 0.001);
}

TEST(TestPointConstructor, ConstructorWithoutoordinates)
{
	Point p1;
	EXPECT_EQ(p1.getR(), 0);
	EXPECT_EQ(p1.getPhi(), 0);
	EXPECT_EQ(p1.getTheta(), 0);
}

TEST(TestPointConstructor, ConstructorWithNegativeRadius)
{
	EXPECT_THROW(Point p1(-2, 0, 0), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithNegativePhiAngle)
{
	EXPECT_THROW(Point p1(0, -180, 0), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithNegativeThetaAngle)
{
	EXPECT_THROW(Point p1(0, 0, -180), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithNegativeValues)
{
	EXPECT_THROW(Point p1(-4, -90, -180), std::invalid_argument);
}


TEST(TestPointConstructor, ConstructorWithGivenOnlyRadius)
{
	Point p1(1.0);
	EXPECT_NEAR(p1.getR(), 1.0, 0.001);
	EXPECT_EQ(p1.getPhi(), 0);
	EXPECT_EQ(p1.getTheta(), 0);
}


TEST(TestPointConstructor, ConstructorWithGivenOnlyRadiusAndPhiAngle)
{
	Point p1(1, 180);
	EXPECT_NEAR(p1.getR(), 1, 0.001);
	EXPECT_NEAR(p1.getPhi(), 3.141, 0.001);
	EXPECT_EQ(p1.getTheta(), 0);
}

TEST(TestPointConstructor, ConstructorWithGivenCoordinatesEqualsToZero)
{
	Point p1(0,0,0);
	EXPECT_EQ(p1.getR(), 0);
	EXPECT_EQ(p1.getPhi(), 0);
	EXPECT_EQ(p1.getTheta(), 0);
}

TEST(TestPointConstructor, ConstructorWithThetaAngleOver180)
{
	EXPECT_THROW(Point p1(1, 180, 720), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithPhiAngleOver360)
{
	EXPECT_THROW(Point p1(1, 400, 180), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithPhiAngleOver360AndThetaAngleOver180)
{
	EXPECT_THROW(Point p1(1,600, 200), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithPhiAngleEqualTo180)
{
	EXPECT_THROW(Point p1(1, 600, 200), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithThetaAngleEqualTo180)
{
	Point p1(1, 90, 180);
	EXPECT_NEAR(p1.getR(), 1, 0.001);
	EXPECT_NEAR(p1.getPhi(), 1.57, 0.001);
	EXPECT_NEAR(p1.getTheta(), 3.141, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingCoordinateSystemOrigin)
{
	Point p1(0, 0, 0);
	double* cartesian = p1.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], 0, 0.001);
	EXPECT_NEAR(cartesian[2], 0, 0.001);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisZ)
{
	Point p1(1, 0, 0); // x,y,z=0,0,1
	double* cartesian = p1.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], 0, 0.001);
	EXPECT_NEAR(cartesian[2], 1, 0.001);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisX)
{
	Point p1(1, 0, 90); // x,y,z=1,0,0
	double* cartesian = p1.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 1, 0.001);
	EXPECT_NEAR(cartesian[1], 0, 0.001);
	EXPECT_NEAR(cartesian[2], 0, 0.001);
	delete[] cartesian;
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisY)
{
	Point p1(1, 90, 90); //x,y,z=0,1,0
	double* cartesian = p1.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], 1, 0.001);
	EXPECT_NEAR(cartesian[2], 0, 0.001);
	delete[] cartesian;
}



TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointWithPositivesCartesian) {
	Point point(1, 60.0, 45.0); 
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0.353553, 0.001); 
	EXPECT_NEAR(cartesian[1], 0.612372, 0.001); 
	EXPECT_NEAR(cartesian[2], 0.707107, 0.001); 
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointXEqualToZero) {
	Point point(2.5, 90.0, 30.0);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], 1.25, 0.001);
	EXPECT_NEAR(cartesian[2], 2.165, 0.001);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisX) {
	Point point(1, 180.0, 90.0);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], -1, 0.001);
	EXPECT_NEAR(cartesian[1], 0, 0.001);
	EXPECT_NEAR(cartesian[2], 0, 0.001);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisY) {
	Point point(1, 270.0, 90.0);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], -1, 0.001);
	EXPECT_NEAR(cartesian[2], 0, 0.001);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisZ) {
	Point point(1, 0, 180);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0, 0.001);
	EXPECT_NEAR(cartesian[1], 0, 0.001);
	EXPECT_NEAR(cartesian[2], -1, 0.001);
	delete[] cartesian;
}
