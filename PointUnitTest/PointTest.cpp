#include "gtest/gtest.h"
#include "../PointLib/Point.h"

TEST(TestPointConstructor, ConstructorWithGivenValues) 
{
	Point p1(1, 2, 4);
	EXPECT_NEAR(p1.getX(), 1, 0.01);
	EXPECT_NEAR(p1.getY(), 2, 0.01);
	EXPECT_NEAR(p1.getZ(), 4, 0.01);
}

TEST(TestPointConstructor, ConstructorWithGivenDoubleValues)
{
	Point p1(1.2, 1.33, 0.21);
	EXPECT_NEAR(p1.getX(), 1.2, 0.01);
	EXPECT_NEAR(p1.getY(), 1.33, 0.01);
	EXPECT_NEAR(p1.getZ(), 0.21, 0.01);
}

TEST(TestPointConstructor, ConstructorWithoutValues)
{
	Point p1;
	EXPECT_EQ(p1.getX(), 0);
	EXPECT_EQ(p1.getY(), 0);
	EXPECT_EQ(p1.getZ(), 0);
}

TEST(TestPointConstructor, ConstructorWithGivenNegativeValues)
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

TEST(TestPointConstructor, ConstructorWithNegativeValue)
{
	Point p1(-22.4, 2, 16);
	EXPECT_NEAR(p1.getX(), -22.4, 0.01);
	EXPECT_NEAR(p1.getY(), 2, 0.01);
	EXPECT_NEAR(p1.getZ(), 16, 0.01);
}

TEST(TestPointConstructor, ConstructorWithGivenValuesEqualToZero)
{
	Point p1(0,0,0);
	EXPECT_EQ(p1.getX(), 0);
	EXPECT_EQ(p1.getY(), 0);
	EXPECT_EQ(p1.getZ(), 0);

}