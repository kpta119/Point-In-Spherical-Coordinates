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


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFirstOctant) 
{	//x>0 y>0 z>0
	Point point(1.73, 45.0, 54.74);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 1, 0.01);
	EXPECT_NEAR(cartesian[1], 1, 0.01);
	EXPECT_NEAR(cartesian[2], 1, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSecondOctant) 
{	//x<0 y>0 z>0
	Point point(3, 153.43, 48.19);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], -2, 0.01);
	EXPECT_NEAR(cartesian[1], 1, 0.01);
	EXPECT_NEAR(cartesian[2], 2, 0.01);
	delete[] cartesian;
}


TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInThirdOctant) 
{	// x<0 y<0 z>0
	Point point(1, 225 ,45);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], -0.5, 0.01);
	EXPECT_NEAR(cartesian[1], -0.5, 0.01);
	EXPECT_NEAR(cartesian[2], 0.707, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFourthOctant) 
{	//x>0 y<0 z<0
	Point point(1, 315, 150);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0.353, 0.01);
	EXPECT_NEAR(cartesian[1], -0.353, 0.01);
	EXPECT_NEAR(cartesian[2], -0.866, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInFifthOctant)
{	//x>0 y<0 z>0
	Point point(1, 300, 60);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0.433, 0.01);
	EXPECT_NEAR(cartesian[1], -0.75, 0.01);
	EXPECT_NEAR(cartesian[2], 0.5, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSixthOctant)
{	//x<0 y<0 z>0
	Point point(1, 210, 60);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], -0.75, 0.01);
	EXPECT_NEAR(cartesian[1], -0.433, 0.01);
	EXPECT_NEAR(cartesian[2], 0.5, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInSeventhOctant)
{	//x>0 y<0 z<0
	Point point(1, 300, 120);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], 0.433, 0.01);
	EXPECT_NEAR(cartesian[1], -0.75, 0.01);
	EXPECT_NEAR(cartesian[2], -0.5, 0.01);
	delete[] cartesian;
}

TEST(TestConvertingSphericalToCartesianCoordinates, ConvertingPointInEighthOctant)
{	//x<0 y<0 z<0
	Point point(1, 240, 120);
	double* cartesian = point.convertingSphericalToCartesianCoordinates();
	EXPECT_NEAR(cartesian[0], -0.433, 0.01);
	EXPECT_NEAR(cartesian[1], -0.75, 0.01);
	EXPECT_NEAR(cartesian[2], -0.5, 0.01);
	delete[] cartesian;
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