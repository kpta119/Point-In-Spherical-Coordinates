#include "../PointLib/Point.h"
#include "../PointLib/Constans.h"
#include <cmath>
#include "gtest/gtest.h"
#include "../PointLib/CartesianPoint.h"

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
	CartesianPoint p1(0, 0, 0); 
	EXPECT_NEAR(p1.getX(), 0, 0.001);
	EXPECT_NEAR(p1.getY(), 0, 0.001);
	EXPECT_NEAR(p1.getZ(), 0, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisZ)
{
	CartesianPoint p1(1, 0, 0); // x,y,z=0,0,1
	EXPECT_NEAR(p1.getX(), 0, 0.001);
	EXPECT_NEAR(p1.getY(), 0, 0.001);
	EXPECT_NEAR(p1.getZ(), 1, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisX)
{
	CartesianPoint p1(1.0, 0, PI/2); // x,y,z=1,0,0
	EXPECT_NEAR(p1.getX(), 1, 0.001);
	EXPECT_NEAR(p1.getY(), 0, 0.001);
	EXPECT_NEAR(p1.getZ(), 0, 0.001);
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnPositiveAxisY)
{
	CartesianPoint p1(1, PI/2, PI/2); //x,y,z=0,1,0
	EXPECT_NEAR(p1.getX(), 0, 0.001);
	EXPECT_NEAR(p1.getY(), 1, 0.001);
	EXPECT_NEAR(p1.getZ(), 0, 0.001);
}



TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointWithPositivesCartesian) {
	CartesianPoint point(1, PI/3, PI/4); 
	EXPECT_NEAR(point.getX(), 0.353, 0.001);
	EXPECT_NEAR(point.getY(), 0.612, 0.001);
	EXPECT_NEAR(point.getZ(), 0.707, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointXEqualToZero) {
	CartesianPoint point(2.5, PI/2, PI/6);
	EXPECT_NEAR(point.getX(), 0, 0.001);
	EXPECT_NEAR(point.getY(), 1.25, 0.001);
	EXPECT_NEAR(point.getZ(), 2.165, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisX) {
	CartesianPoint point(1, PI, PI/2);
	EXPECT_NEAR(point.getX(), -1, 0.001);
	EXPECT_NEAR(point.getY(), 0, 0.001);
	EXPECT_NEAR(point.getZ(), 0, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisY) {
	CartesianPoint point(1, PI*3/2, PI/2);
	EXPECT_NEAR(point.getX(), 0, 0.001);
	EXPECT_NEAR(point.getY(), -1, 0.001);
	EXPECT_NEAR(point.getZ(), 0, 0.001);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointOnNegativeAxisZ) {
	CartesianPoint point(1, 0, PI);
	EXPECT_NEAR(point.getX(), 0, 0.001);
	EXPECT_NEAR(point.getY(), 0, 0.001);
	EXPECT_NEAR(point.getZ(), -1, 0.001);
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFirstOctant) 
{	//x>0 y>0 z>0
	CartesianPoint point(1.73, PI/4, 54.74 * PI /180);
	EXPECT_NEAR(point.getX(), 1, 0.01);
	EXPECT_NEAR(point.getY(), 1, 0.01);
	EXPECT_NEAR(point.getZ(), 1, 0.01);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSecondOctant) 
{	//x<0 y>0 z>0
	CartesianPoint point(3, 153.43 * PI / 180, 48.19 * PI / 180);
	EXPECT_NEAR(point.getX(), -2, 0.01);
	EXPECT_NEAR(point.getY(), 1, 0.01);
	EXPECT_NEAR(point.getZ(), 2, 0.01);
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInThirdOctant) 
{	// x<0 y<0 z>0
	CartesianPoint point(1, 225 * PI / 180,PI/4);
	EXPECT_NEAR(point.getX(), -0.5, 0.01);
	EXPECT_NEAR(point.getY(), -0.5, 0.01);
	EXPECT_NEAR(point.getZ(), 0.707, 0.01);
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFourthOctant)
{	//x>0 y<0 z<0
	CartesianPoint point(1, 315 * PI / 180, 150 * PI / 180);
	EXPECT_NEAR(point.getX(), 0.353, 0.01);
	EXPECT_NEAR(point.getY(), -0.353, 0.01);
	EXPECT_NEAR(point.getZ(), -0.866, 0.01);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFifthOctant)
{	//x>0 y<0 z>0
	CartesianPoint point(1, 300 * PI / 180, PI/3);
	EXPECT_NEAR(point.getX(), 0.433, 0.01);
	EXPECT_NEAR(point.getY(), -0.75, 0.01);
	EXPECT_NEAR(point.getZ(), 0.5, 0.01);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSixthOctant)
{	//x<0 y<0 z>0
	CartesianPoint point(1, 210 * PI / 180, PI/3);
	EXPECT_NEAR(point.getX(), -0.75, 0.01);
	EXPECT_NEAR(point.getY(), -0.433, 0.01);
	EXPECT_NEAR(point.getZ(), 0.5, 0.01);
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSeventhOctant)
{	//x>0 y<0 z<0
	CartesianPoint point(1, 300 * PI / 180, 120 * PI / 180);
	EXPECT_NEAR(point.getX(), 0.433, 0.01);
	EXPECT_NEAR(point.getY(), -0.75, 0.01);
	EXPECT_NEAR(point.getZ(), -0.5, 0.01);
	
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInEighthOctant)
{	//x<0 y<0 z<0
	CartesianPoint point(1, 240 * PI / 180, 120 * PI / 180);
	EXPECT_NEAR(point.getX(), -0.433, 0.01);
	EXPECT_NEAR(point.getY(), -0.75, 0.01);
	EXPECT_NEAR(point.getZ(), -0.5, 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorDefaultPoints)
{
	Point p1;
	Point p2;
	p1 += p2;
	EXPECT_NEAR(0, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorTheSamePointsOnAxialPlaneXY)
{
	Point p1(1, 45, 90);
	Point p2(1, 45, 90);
	p1 += p2;
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(PI/4, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI/2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsOnAxialPlaneXY)
{
	Point p1(1, 30, 90);
	Point p2(1, 45, 90);
	p1 += p2;
	EXPECT_NEAR(1.98, p1.getR(), 0.01);
	EXPECT_NEAR(37.5 * PI/180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI / 2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsOnAxialPlaneXYOnePointIsDefault)
{
	Point p1;
	Point p2(1, 45, 90);
	p1 += p2;
	EXPECT_NEAR(1, p1.getR(), 0.01);
	EXPECT_NEAR(PI / 4, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI / 2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsInDifferentOctants)
{
	Point p1(1, 300, 60);
	Point p2(1, 45, 90);
	p1 += p2;
	EXPECT_NEAR(1.245, p1.getR(), 0.01);
	EXPECT_NEAR(357.845*PI/180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(66.3349*PI/180.0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorResultPointsOnAxialPlaneXY)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(2.45,63.43,114.09); // 1,2,-1
	p1 += p2; // 2,3,0
	EXPECT_NEAR(3.61, p1.getR(), 0.01);
	EXPECT_NEAR(56.31 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI/2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsInAxisXAndAxisZ)
{
	Point p1(1,0,90); // 1,0,0
	Point p2(1,0, 0); // 0,0,1
	p1 += p2; // 1,0,1
	EXPECT_NEAR(1.41, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI / 4, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsInAxisXAndAxisY)
{
	Point p1(1, 0, 90); // 1,0,0
	Point p2(1,90,90); // 0,1,0
	p1 += p2; // 1,1,0
	EXPECT_NEAR(1.41, p1.getR(), 0.01);
	EXPECT_NEAR(PI/4, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI/2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointsInAxisYAndAxisZ)
{
	Point p1(1, 0, 0); // 0,0,1
	Point p2(1, 90, 90); // 0,1,0
	p1 += p2; // 1,1,0
	EXPECT_NEAR(1.41, p1.getR(), 0.01);
	EXPECT_NEAR(PI / 2, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI / 4, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointIntheNorthAndTheOtherInTheSouth)
{
	Point p1(2.45, 45, 35.26); // 1,1,2
	Point p2(3.46, 225, 125.26); // -2,-2,-2
	p1 += p2; // 1,1,0
	EXPECT_NEAR(1.41, p1.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(PI / 2, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorPointIntheEastAndTheOtherInTheWest)
{
	Point p1(2.45, 45, 35.26); // 1,1,2
	Point p2(3.74, 243.43, 36.7); // -1,-2,3
	p1 += p2; // 0,-1,5
	EXPECT_NEAR(5.1, p1.getR(), 0.01);
	EXPECT_NEAR(270 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(11.31 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorBothPointsOnAxisZ)
{
	Point p1(1,0,0); // 0,0,1
	Point p2(2,0,0); // 0,0,2
	p1 += p2; // 0,0,3
	EXPECT_NEAR(3, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorOnePointOnAxisXTheOtherPointInTheSouth)
{
	Point p1(1,0,90); // 1,0,0
	Point p2(3.74, 243.43, 36.7); // -1,-2,3
	p1 += p2; // 0,-2, 3
	EXPECT_NEAR(3.61, p1.getR(), 0.01);
	EXPECT_NEAR(270 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(33.69 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorOppositePoints)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(1.73, 225, 125.26); // -1,-1,-1
	p1 += p2; // 0,0,0
	EXPECT_NEAR(0, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddAndAssignOperatorTheSamePointsOnAxialPlaneYZ)
{
	Point p1(1.41, 90, 45); // 0,1,1
	Point p2(1.41, 90, 45); // 0,1,1
	p1 += p2; // 0,2,2
	EXPECT_NEAR(2.82, p1.getR(), 0.01);
	EXPECT_NEAR(90*PI/180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(45*PI/180.0, p1.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorTheSamePointsOnAxialPlaneYZ)
{
	Point p1(1.41, 90, 45); // 0,1,1
	Point p2(1.41, 90, 45); // 0,1,1
	Point p3 = p1 + p2; // 0,2,2
	EXPECT_NEAR(2.82, p3.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorOppositePoints)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(1.73, 225, 125.26); // -1,-1,-1
	Point p3 = p1 + p2; // 0,0,0
	EXPECT_NEAR(0, p3.getR(), 0.01);
	EXPECT_NEAR(0, p3.getPhi(), 0.01);
	EXPECT_NEAR(0, p3.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorPointIntheNorthAndTheOtherInTheSouth)
{
	Point p1(2.45, 45, 35.26); // 1,1,2
	Point p2(3.46, 225, 125.26); // -2,-2,-2
	Point p3 = p1 + p2; // 1,1,0
	EXPECT_NEAR(1.41, p3.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(PI / 2, p3.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorPointIntheEastAndPointIntheWest)
{
	Point p1(2.45, 45, 35.26); // 1,1,2
	Point p2(3.74, 243.43, 36.7); // -1,-2,3
	Point p3 = p1 + p2; // 0,-1,5
	EXPECT_NEAR(5.1, p3.getR(), 0.01);
	EXPECT_NEAR(270 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(11.31 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorPointOnAxisXAndTheOtherOnAxisZ)
{
	Point p1(1, 0, 90); // 1,0,0
	Point p2(3, 0, 0); // 0,0,3
	Point p3 = p1 + p2; // 1,0,3
	EXPECT_NEAR(3.16, p3.getR(), 0.01);
	EXPECT_NEAR(0, p3.getPhi(), 0.01);
	EXPECT_NEAR(18.43 * PI / 180.0, p3.getTheta(), 0.01);
}


TEST(TestPointAddition, AddOperatorPointOnAxisYAndTheOtherPointOnAxisZ)
{
	Point p1(1, 90, 90); // 0,1,0
	Point p2(3, 0, 0); // 0,0,3
	Point p3 = p1 + p2; // 0,1,3
	EXPECT_NEAR(3.16, p3.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(18.43 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointAddition, AddOperatorPointInDifferentOctants)
{
	Point p1(3.74, 303.69, 74.5); // 2,-3,1
	Point p2(3.74, 116.57, 36.7); // -1,2,3
	Point p3 = p1 + p2; // 1,-1,4
	EXPECT_NEAR(4.24, p3.getR(), 0.01);
	EXPECT_NEAR(315 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(19.47 * PI / 180.0, p3.getTheta(), 0.01);
}


TEST(TestPointSubstraction, SubstractAndAssignOperatorTheSamePoints)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(1.73, 45, 54.74); // 1,1,1
	p1 -= p2; // 0,0,0
	EXPECT_NEAR(0, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorOppositePoints)
{	
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(1.73, 225, 125.36); // -1,-1,-1
	p1 -= p2; // 2,2,2
	EXPECT_NEAR(3.46, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI/180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(54.74 * PI/180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointsOnAxialPlaneXY)
{
	Point p1(1.41, 45, 90); // 1,1,0
	Point p2(2.24, 26.57, 90); // 2,1,0
	p1 -= p2; // -1,0,0
	EXPECT_NEAR(1, p1.getR(), 0.01);
	EXPECT_NEAR(180 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI /180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointsOnAxialPlaneXZ)
{
	Point p1(1.41, 0, 45); // 1,0,1
	Point p2(3.61, 0, 33.69); // 2,0,3
	p1 -= p2; // -1,0,-2
	EXPECT_NEAR(2.24, p1.getR(), 0.01);
	EXPECT_NEAR(180 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(153.43 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointsOnAxialPlaneYZ)
{
	Point p1(1.41, 90, 45); // 0,1,1
	Point p2(2.24, 270, 116.57); // 0,-2,-1
	p1 -= p2; // 0,3,2
	EXPECT_NEAR(3.61, p1.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(56.31 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointsInDifferentOctants)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(2.45, 243.43, 65.91); // -1,-2,1
	p1 -= p2; // 2,3,0
	EXPECT_NEAR(3.61, p1.getR(), 0.01);
	EXPECT_NEAR(56.31 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointOnAxisXAndTheOtherOnAxisY)
{
	Point p1(1, 0, 90); // 1,0,0
	Point p2(1, 270, 90); // 0,-1,0
	p1 -= p2; // 1,1,0
	EXPECT_NEAR(1.41, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointOnAxisXAndTheOtherOnAxisZ)
{
	Point p1(1, 0, 90); // 1,0,0
	Point p2(2, 0, 180); // 0,0,-2
	p1 -= p2; // 1,0,-2
	EXPECT_NEAR(2.24, p1.getR(), 0.01);
	EXPECT_NEAR(0 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(26.57 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorPointOnAxisYAndTheOtherOnAxisZ)
{
	Point p1(1, 90, 90); // 0,1,0
	Point p2(2, 0, 0); // 0,0,2
	p1 -= p2; // 0,1,-2
	EXPECT_NEAR(2.24, p1.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(153.43 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorDefaultPoints)
{
	Point p1; 
	Point p2; 
	p1 -= p2; 
	EXPECT_NEAR(0, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorOnePointIsDefault)
{
	Point p1; 
	Point p2(1.73, 225, 125.36); // -1,-1,-1
	p1 -= p2; // 1,1,1
	EXPECT_NEAR(1.73, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(54.74 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractAndAssignOperatorSubstractedPointIsDefault)
{
	Point p1(1.73, 225, 125.36); // -1,-1,-1
	Point p2;
	p1 -= p2; // 1,1,1
	EXPECT_NEAR(1.73, p1.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(125.36 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOppositePoints)
{
	Point p1(1.73, 225, 125.36); // -1,-1,-1
	Point p2(1.73, 45, 54.74); // 1,1,1
	Point p3 = p1 - p2; // 1,1,1
	EXPECT_NEAR(3.46, p3.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(125.36 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorTheSamePoints)
{
	Point p1(1.73, 45, 54.74); // 1,1,1
	Point p2(1.73, 45, 54.74); // 1,1,1
	Point p3 = p1 - p2; // 1,1,1
	EXPECT_NEAR(0, p3.getR(), 0.01);
	EXPECT_NEAR(0, p3.getPhi(), 0.01);
	EXPECT_NEAR(0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOnePointIntheNorthAndTheOtherIntheSouth)
{
	Point p1(4.12, 45, 43.31); // 2,2,3
	Point p2(4.24,45,160.53); // 1,1,-4
	Point p3 = p1 - p2; // 1,1,7
	EXPECT_NEAR(7.14, p3.getR(), 0.01);
	EXPECT_NEAR(45 * PI /180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(11.42 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOnePointIntheEastAndTheOtherIntheWest)
{
	Point p1(3, 315, 70.53); // 2,-2,1
	Point p2(2.45, 45, 144.74); // 1,1,-2
	Point p3 = p1 - p2; // 1,-3,3
	EXPECT_NEAR(4.36, p3.getR(), 0.01);
	EXPECT_NEAR(288.43 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(46.51 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOneBothPointsOnAxisX)
{
	Point p1(2, 0, 90); // 2,0,0
	Point p2(3, 180, 90); // -3,0,0
	Point p3 = p1 - p2; // 5,0,0
	EXPECT_NEAR(5, p3.getR(), 0.01);
	EXPECT_NEAR(0 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOneBothPointsOnAxisY)
{
	Point p1(1, 90, 90); // 0,1,0
	Point p2(2, 270, 90); // 0,-2,0
	Point p3 = p1 - p2; // 0,3,0
	EXPECT_NEAR(3, p3.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p3.getTheta(), 0.01);
}

TEST(TestPointSubstraction, SubstractOperatorOneBothPointsOnAxisZ)
{
	Point p1(1, 0, 0); // 0,0,1
	Point p2(2, 0, 0); // 0,0,2
	Point p3 = p1 - p2; // 0,0,-1
	EXPECT_NEAR(1, p3.getR(), 0.01);
	EXPECT_NEAR(0 * PI / 180.0, p3.getPhi(), 0.01);
	EXPECT_NEAR(180 * PI / 180.0, p3.getTheta(), 0.01);
}


TEST(TestPointDistance, CountDistanceOnePointDefaultPoint)
{
	Point p1;
	EXPECT_NEAR(0, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceOnePointOnAxisX)
{
	Point p1(2,0,90); //2,0,0
	EXPECT_NEAR(2, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceOnePointOnAxisY)
{
	Point p1(2, 90, 90); //0,2,0
	EXPECT_NEAR(2, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceOnePointOnAxisZ)
{
	Point p1(2, 0, 0); //0,0,2
	EXPECT_NEAR(2, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceOnePointIntheNorth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	EXPECT_NEAR(2.45, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceOnePointIntheSouth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	EXPECT_NEAR(2.45, p1.distance(), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOppositePoints)
{
	Point p1(1.73, 45, 54.74); //1,1,1
	Point p2(1.73,225,125.36); //-1,-1,-1
	EXPECT_NEAR(3.46, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsTheSamePoints)
{
	Point p1(1.73, 45, 54.74); //1,1,1
	Point p2(1.73, 45, 54.74); //1,1,1
	EXPECT_NEAR(0, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsBothPointsOnAxisX)
{
	Point p1(1, 0, 90); //1,0,0
	Point p2(2, 180, 90); //-2,0,0
	EXPECT_NEAR(3, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsBothPointsOnAxisY)
{
	Point p1(1, 90, 90); //0,1,0
	Point p2(3, 90, 90); //0,3,0
	EXPECT_NEAR(2, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsBothPointsOnAxisZ)
{
	Point p1(1, 0, 0); //0,0,1
	Point p2(4, 0, 180); //0,0,-4
	EXPECT_NEAR(5, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisXTheOtherPointInTheNorth)
{
	Point p1(1, 0, 90); //1,0,0
	Point p2(2.45, 45, 35.26); //1,1,2
	EXPECT_NEAR(2.24, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisYTheOtherPointInTheNorth)
{
	Point p1(1, 90, 90); //0,1,0
	Point p2(2.45, 45, 35.26); //1,1,2
	EXPECT_NEAR(2.24, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisZTheOtherPointInTheNorth)
{
	Point p1(1, 0, 0); //0,0,1
	Point p2(2.45, 45, 35.26); //1,1,2
	EXPECT_NEAR(1.73, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisXTheOtherPointInTheSouth)
{
	Point p1(1, 0, 90); //1,0,0
	Point p2(1.73, 225, 125.36); //-1,-1,-1
	EXPECT_NEAR(2.45, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisYTheOtherPointInTheSouth)
{
	Point p1(1, 90, 90); //0,1,0
	Point p2(1.73, 225, 125.36); //-1,-1,-1
	EXPECT_NEAR(2.45, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointOnAxisZTheOtherPointInTheSouth)
{
	Point p1(1, 0, 0); //0,0,1
	Point p2(1.73, 225, 125.36); //-1,-1,-1
	EXPECT_NEAR(2.45, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointInTheNorthTheOtherPointInTheSouth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(1.73, 225, 125.36); //-1,-1,-1
	EXPECT_NEAR(4.12, p1.distance(p2), 0.01);
}

TEST(TestPointDistance, CountDistanceTwoPointsOnePointInTheEastTheOtherPointInTheWest)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(3.74, 243.43, 36.7); //-1,-2,3
	EXPECT_NEAR(3.74, p1.distance(p2), 0.01);
}


TEST(TestPointMultiplication, MultiplyAndAssignOperatorDefaultPoint)
{
	Point p1;
	p1 *= 2;
	EXPECT_NEAR(0, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointOnAxisX)
{
	Point p1(1, 0, 90); //1,0,0
	p1 *= 2; //2,0,0
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI /180, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointOnAxisY)
{
	Point p1(1, 90, 90); //0,1,0
	p1 *= 2; //0,2,0
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointOnAxisZ)
{
	Point p1(1, 0, 0); //0,0,1
	p1 *= 2; //0,0,2
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(0, p1.getPhi(), 0.01);
	EXPECT_NEAR(0, p1.getTheta(), 0.01);
}


TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointIntheNorth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	p1 *= 2; //2,2,4
	EXPECT_NEAR(4.9, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(35.26 * PI / 180.0, p1.getTheta(), 0.01);
}


TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointIntheSouth)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	p1 *= 2; //2,2,-4
	EXPECT_NEAR(4.9, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(144.74 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorNegativeScalar)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	p1 *= -2; //-2,-2,4
	EXPECT_NEAR(4.9, p1.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(35.26 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorPointIntheNorthAndTheOtherInTheSouth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(3.46, 225, 125.26); //-2,-2,-2
	p1 *= 2; //2,2,4
	p2 *= 2; //-4,-4,-4
	EXPECT_NEAR(4.9, p1.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(35.26 * PI / 180.0, p1.getTheta(), 0.01);
	EXPECT_NEAR(6.92, p2.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p2.getPhi(), 0.01);
	EXPECT_NEAR(125.26 * PI / 180.0, p2.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorNegativeScalarPointOnAxisX)
{
	Point p1(1,0,90); //1,0,0
	p1 *= -2; //-2,0,0
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(180 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorNegativeScalarPointOnAxisY)
{
	Point p1(1, 90, 90); //0,1,0
	p1 *= -2; //0,-2,0
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(270 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(90 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorNegativeScalarPointOnAxisZ)
{
	Point p1(1, 0, 0); //0,0,1
	p1 *= -2; //0,0,-2
	EXPECT_NEAR(2, p1.getR(), 0.01);
	EXPECT_NEAR(180 * PI /180, p1.getPhi(), 0.01);
	EXPECT_NEAR(180 * PI / 180, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyAndAssignOperatorNegativeScalarPointIntheNorth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	p1 *= -2; //-2,-2,-4
	EXPECT_NEAR(4.9, p1.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p1.getPhi(), 0.01);
	EXPECT_NEAR(144.74 * PI / 180.0, p1.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyOperatorPointInTheSouth)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	Point p2 = p1 * 2; //2,2,-4
	EXPECT_NEAR(4.9, p2.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p2.getPhi(), 0.01);
	EXPECT_NEAR(144.74 * PI / 180.0, p2.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyOperatorNegativeScalar)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	Point p2 = p1 * ( -2); //-2,-2,4
	EXPECT_NEAR(4.9, p2.getR(), 0.01);
	EXPECT_NEAR(225 * PI / 180.0, p2.getPhi(), 0.01);
	EXPECT_NEAR(35.26 * PI / 180.0, p2.getTheta(), 0.01);
}

TEST(TestPointMultiplication, MultiplyOperatorPointIntheNorthAndTheOtherInTheSouth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2 = p1 * 2; //2,2,4
	EXPECT_NEAR(4.9, p2.getR(), 0.01);
	EXPECT_NEAR(45 * PI / 180.0, p2.getPhi(), 0.01);
	EXPECT_NEAR(35.26 * PI / 180.0, p2.getTheta(), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointOnAxiXAndY)
{
	Point p1(1, 0, 90); //1,0,0
	Point p2(1, 90, 90); //0,1,0
	EXPECT_NEAR(90, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointOnAxiXAndZ)
{
	Point p1(1, 0, 90); //1,0,0
	Point p2(1, 0, 0); //0,0,1
	EXPECT_NEAR(90, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointOnAxiYAndZ)
{
	Point p1(1, 90, 90); //0,1,0
	Point p2(1, 0, 0); //0,0,1
	EXPECT_NEAR(90, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointIntheNorthAndTheOtherInTheSouth)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(3.46, 225, 125.26); //-2,-2,-2
	EXPECT_NEAR(160.53, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointIntheNorthAndTheOtherInTheEast)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(3.74, 243.43, 36.7); //-1,-2,3
	EXPECT_NEAR(70.89, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointIntheNorthAndTheOtherInTheWest)
{
	Point p1(2.45, 45, 35.26); //1,1,2
	Point p2(3.74, 26.57, 36.7); //2,1,3
	EXPECT_NEAR(10.89, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointInTheSouthAndTheOtherInTheEast)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	Point p2(3.74, 243.43, 36.7); //-1,-2,3
	EXPECT_NEAR(169.11, p1.angleBetweenVectors(p2), 0.01);
}

TEST(TestAngleBetweenPoints, AngleBetweenPointsMethodPointInTheSouthAndTheOtherInTheWest)
{
	Point p1(2.45, 45, 144.74); //1,1,-2
	Point p2(3.74, 26.57, 36.7); //2,1,3
	EXPECT_NEAR(109.11, p1.angleBetweenVectors(p2), 0.01);
}

TEST(PointTestInputOutput, OutputPointWithDefaultCoordinates)
{
	Point p;
	std::ostringstream stream;
	stream << p;
	EXPECT_EQ("(0.00, 0.00, 0.00)", stream.str());
}

TEST(PointTestInputOutput, OutputPointWithCoordinates)
{
	Point p(2.45, 45, 35.26); //1,1,2
	std::ostringstream stream;
	stream << p;
	EXPECT_EQ("(2.45, 45.00, 35.26)", stream.str());
}

TEST(PointTestInputOutput, OutputPointWithAnotherCoordinates)
{
	Point p(3.74, 26.57, 36.7); //2,1,3
	std::ostringstream stream;
	stream << p;
	EXPECT_EQ("(3.74, 26.57, 36.70)", stream.str());
}