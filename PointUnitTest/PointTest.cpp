#include "gtest/gtest.h"
#include "../PointLib/Point.h"
#include "../PointLib/Constans.h"
#include <cmath>

TEST(TestPointConstructor, ConstructorWithGivenCoordinates) 
{
	Point p1(1, PI/2, PI/2);
	EXPECT_NEAR(p1.getR(), 1, 0.01);
	EXPECT_NEAR(p1.getPhi(), 1.57, 0.01);
	EXPECT_NEAR(p1.getTheta(), 1.57, 0.01);
}



