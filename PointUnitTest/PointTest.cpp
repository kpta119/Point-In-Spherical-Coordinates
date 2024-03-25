#include "gtest/gtest.h"
#include "../PointLib/Point.h"

TEST(TestPointConstructor, ConstructorWithGivenCoordinates) 
{
	Point p1(1, 2, 4);
	EXPECT_NEAR(p1.getX(), 1, 0.01);
	EXPECT_NEAR(p1.getY(), 2, 0.01);
	EXPECT_NEAR(p1.getZ(), 4, 0.01);
}

TEST(TestPointConstructor, ConstructorWithGivenDoubleCoordinates)
{
	Point p1(1.2, 1.33, 0.21);
	EXPECT_NEAR(p1.getX(), 1.2, 0.01);
	EXPECT_NEAR(p1.getY(), 1.33, 0.01);
	EXPECT_NEAR(p1.getZ(), 0.21, 0.01);
}

TEST(TestPointConstructor, ConstructorWithoutCoordinates)
{
	Point p1;
	EXPECT_EQ(p1.getX(), 0);
	EXPECT_EQ(p1.getY(), 0);
	EXPECT_EQ(p1.getZ(), 0);
}

TEST(TestPointConstructor, ConstructorWithGivenNegativeCoordinates)
{
	Point p1(-2.3, -2, -4.22);
	EXPECT_NEAR(p1.getX(), -2.3, 0.01);
	EXPECT_NEAR(p1.getY(), -2, 0.01);
	EXPECT_NEAR(p1.getZ(), -4.22, 0.01);
}

TEST(TestPointConstructor, ConstructorWithOnlyGivenX)
{
	Point p1(1);
	EXPECT_NEAR(p1.getX(), 1, 0.01);
	EXPECT_EQ(p1.getY(), 0);
	EXPECT_EQ(p1.getZ(), 0);
}

TEST(TestPointConstructor, ConstructorWithOnlyGivenXAndY)
{
	Point p1(1.8, 2.23);
	EXPECT_NEAR(p1.getX(), 1.8, 0.01);
	EXPECT_NEAR(p1.getY(), 2.23, 0.01);
	EXPECT_EQ(p1.getZ(), 0);
}

TEST(TestPointConstructor, ConstructorWithNegativeCoordinate)
{
	Point p1(-22.4, 2, 16);
	EXPECT_NEAR(p1.getX(), -22.4, 0.01);
	EXPECT_NEAR(p1.getY(), 2, 0.01);
	EXPECT_NEAR(p1.getZ(), 16, 0.01);
}

TEST(TestPointConstructor, ConstructorWithGivenCoordinatessEqualToZero)
{
	Point p1(0,0,0);
	EXPECT_EQ(p1.getX(), 0);
	EXPECT_EQ(p1.getY(), 0);
	EXPECT_EQ(p1.getZ(), 0);

}

TEST(TestPointOperatorPlus, PointOperatorPlusPointsWithDefaultCoordinates)
{
	Point p1;
	Point p2;
	Point p3 = p1 + p2;
	EXPECT_EQ(p3.getX(), 0);
	EXPECT_EQ(p3.getY(), 0);
	EXPECT_EQ(p3.getZ(), 0);
}

TEST(TestPointOperatorPlus, PointOperatorPlusPointWithDefaultCoordinatesAndPointWithGivenCoordinates)
{
	Point p1(1,3,5.2);
	Point p2;
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), 1, 0.01);
	EXPECT_NEAR(p3.getY(), 3, 0.01);
	EXPECT_NEAR(p3.getZ(), 5.2, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusPointsWithGivenCoordinates)
{
	Point p1(1, 3, 5.1);
	Point p2(2, 10.2, 5.5);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), 3, 0.01);
	EXPECT_NEAR(p3.getY(), 13.2, 0.01);
	EXPECT_NEAR(p3.getZ(), 10.6, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusPointsWithNegativeAndPositiveCoordinates)
{
	Point p1(4, -2, 5.1);
	Point p2(-2, -9.2, -3.33);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), 2, 0.01);
	EXPECT_NEAR(p3.getY(), -11.2, 0.01);
	EXPECT_NEAR(p3.getZ(), 1.77, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusPointsWithOnlyNegativeCoordinates)
{
	Point p1(-1, -3, -3.2);
	Point p2(-2, -7.2, -5);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), -3, 0.01);
	EXPECT_NEAR(p3.getY(), -10.2, 0.01);
	EXPECT_NEAR(p3.getZ(), -8.2, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusPointsWithSomeDefaultCoordinates)
{
	Point p1(2,3);
	Point p2(2);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), 4, 0.01);
	EXPECT_NEAR(p3.getY(), 3, 0.01);
	EXPECT_EQ(p3.getZ(), 0);
}

TEST(TestPointOperatorPlus, PointOperatorPlusOnePointIsMultipleOfOther)
{
	Point p1(4, 3, 5);
	Point p2(8, 6, 10);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), 12, 0.01);
	EXPECT_NEAR(p3.getY(), 9, 0.01);
	EXPECT_NEAR(p3.getZ(), 15, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusDefaultPointAndPointWithNegativeCoordinates)
{
	Point p1;
	Point p2(-3.4,-6.6,-10);
	Point p3 = p1 + p2;
	EXPECT_NEAR(p3.getX(), -3.4, 0.01);
	EXPECT_NEAR(p3.getY(), -6.6, 0.01);
	EXPECT_NEAR(p3.getZ(), -10, 0.01);
}

TEST(TestPointOperatorPlus, PointOperatorPlusAddingPointToItself)
{
	Point p1(-3, 2, -10.3);
	Point p2 = p1 + p1;
	EXPECT_NEAR(p2.getX(), -6, 0.01);
	EXPECT_NEAR(p2.getY(), 4, 0.01);
	EXPECT_NEAR(p2.getZ(), -20.6, 0.01);
}


