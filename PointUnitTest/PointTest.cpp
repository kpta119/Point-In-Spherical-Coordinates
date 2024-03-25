#include "../PointLib/Point.h"
#include "../PointLib/Constans.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(TestPointConstructor, ConstructorWithGivenCoordinates)
{
	Point p1(1, PI / 2, PI / 2);
	EXPECT_NEAR(p1.getR(), 1, 0.001);
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
	EXPECT_THROW(Point p1(0, -PI, 0), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithNegativeThetaAngle)
{
	EXPECT_THROW(Point p1(0, 0, -PI), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithNegativeValues)
{
	EXPECT_THROW(Point p1(-4, -PI/2, -PI), std::invalid_argument);
}


TEST(TestPointConstructor, ConstructorWithGivenOnlyRadius)
{
	Point p1(1);
	EXPECT_NEAR(p1.getR(), 1, 0.001);
	EXPECT_EQ(p1.getPhi(), 0);
	EXPECT_EQ(p1.getTheta(), 0);
}


TEST(TestPointConstructor, ConstructorWithGivenOnlyRadiusAndPhiAngle)
{
	Point p1(1, PI);
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

TEST(TestPointConstructor, ConstructorWithThetaAngleOver2Pi)
{
	EXPECT_THROW(Point p1(1, PI, 3*PI), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithPhiAngleOverPi)
{
	EXPECT_THROW(Point p1(1, PI*4/3, PI), std::invalid_argument);
}

TEST(TestPointConstructor, ConstructorWithPhiAngleOverPiAndThetaAngleOver2Pi)
{
	EXPECT_THROW(Point p1(1, PI * 4 / 3, 3*PI), std::invalid_argument);
}