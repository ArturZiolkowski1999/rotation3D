#include "gtest/gtest.h"
#include "Matrix.h"
#include <iostream>
#include <utility>
#include "Cuboid.h"
#include "Constants.h"
#include "Vector.h"



TEST (Vector, EmptyConstructor) {

    // 3 dim
    Vector<double, 3> Vec1 = Vector<double, 3>();
    Vector<double, 3> Vec2 = Vector<double, 3>();
    Vec1.setX(0);
    Vec1.setY(0);
    Vec1.setZ(0);
    EXPECT_EQ(Vec1, Vec2);

    // 2 dim
    Vector<double, 2> Vec3 = Vector<double, 2>();
    Vector<double, 2> Vec4 = Vector<double, 2>();
    Vec1.setX(0);

    EXPECT_EQ(Vec3, Vec4);
}

TEST (Vector, Constructor) {

    // 3 dim
    Vector<double, 3> Vec1 = Vector<double, 3>(2.3,4.5, 1.1);
    Vector<double, 3> Vec2 = Vector<double, 3>();
    Vec2.setX(2.3);
    Vec2.setY(4.5);
    Vec2.setZ(1.1);
    EXPECT_EQ(Vec1, Vec2);

    // 2 dim
    Vector<double, 2> Vec3 = Vector<double, 2>(2.3,4.5);
    Vector<double, 2> Vec4 = Vector<double, 2>();
    Vec4.setX(2.3);
    Vec4.setY(4.5);
    EXPECT_EQ(Vec3, Vec4);
}

TEST (Vector, floatConstructor) {

    Vector<float, 3> Vec1 = Vector<float, 3>(2.3,4.5, 1.1);
    Vector<float, 3> Vec2 = Vector<float, 3>();
    Vec2.setX(2.3);
    Vec2.setY(4.5);
    Vec2.setZ(1.1);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, intConstructor) {

    Vector<int, 3> Vec1 = Vector<int, 3>(2,4, 1);
    Vector<int, 3> Vec2 = Vector<int, 3>();
    Vec2.setX(2);
    Vec2.setY(4);
    Vec2.setZ(1);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, Addition) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2.3,4.5, 1.1);
    Vector<double, 3> Vec2 = Vector<double, 3>(1,1, 1);
    Vector<double, 3> result = Vector<double, 3>(3.3, 5.5, 2.1);
    EXPECT_EQ(Vec1 + Vec2, result);
}

TEST (Vector, Subtruction) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2.3,4.5, 1.1);
    Vector<double, 3> Vec2 = Vector<double, 3>(1,1, 1);
    Vector<double, 3> result = Vector<double, 3>(1.3, 3.5, 0.1);

    EXPECT_EQ(Vec1 - Vec2, result);
}

TEST (Vector, Multiplication) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2,4, 5);
    Vector<double, 3> result = Vector<double, 3>(4, 8, 10);
    EXPECT_EQ(Vec1 * 2, result);
}

TEST (Vector, Division) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2,4, 8);
    Vector<double, 3> result = Vector<double, 3>(1, 2, 4);
    EXPECT_EQ(Vec1 / 2, result);
}

TEST (Vector, FailDivision) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2,4, 8);

    EXPECT_THROW(Vec1 / 0, std::invalid_argument);
}

TEST (Vector, FailIndexing) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2,4, 8);

    EXPECT_THROW(Vec1[6], std::invalid_argument);
}

TEST (Vector, Indexing) {

    Vector<double, 3> Vec1 = Vector<double, 3>(2,4,8);

    EXPECT_EQ(Vec1[1], 4);

    Vec1[0] = 3;
    Vec1[1] = 4;
    Vec1[2] = 6;
    Vector<double, 3> result =Vector<double, 3>(3, 4, 6);
    EXPECT_EQ(Vec1, result);

}

TEST (Vector, Ostream) {

    std::stringstream ost;
    Vector<double, 3> vec = Vector<double, 3>(3.1, 3.1, 7.5);
    ost << vec;
    /* in cout program print double in 10 decimal point fixed precision, but i didnt know how to automaticly test cout*/
    EXPECT_EQ("3.1 3.1 7.5\n", ost.str());
}

TEST (Vector, GetLength) {

    Vector<double, 3> Vec1 = Vector<double, 3>(0, 4, 3);
    double length;
    length = Vec1.getLength();
    EXPECT_EQ(length, 5.0);

    Vec1 = Vector<double, 3>(6,0,0);
    length = Vec1.getLength();
    EXPECT_EQ(length, 6);
}

TEST (Matrix, EmptyConstructor) {
    Matrix<double, 3> A = Matrix<double, 3>();
    Matrix B = Matrix<double, 3>();

    B(0,0) = 1; B(0,1) = 0; B(0,2) = 0;
    B(1,0) = 0; B(1,1) = 1; B(1,2) = 0;
    B(2,0) = 0; B(2,1) = 0; B(2,2) = 1;

    EXPECT_EQ(A, B);
}

TEST (Matrix, Constructor) {

    Matrix<double, 3> A = Matrix<double, 3>(90, 'z');
    Matrix<double, 3> B = Matrix<double, 3>();

    Matrix C = Matrix<double, 3>(0, 'z');
    Matrix D = Matrix<double, 3>();

    B(0,0) = cos(M_PI/2); B(0,1) = -sin(M_PI/2); B(0,2) = 0;
    B(1,0) = sin(M_PI); B(1,1) = cos(M_PI/2); B(1,2) = 0;
    B(2,0) = 0; B(2,1) = 0; B(2,2) = 1;


    D(0,0) = cos(0); D(0,1) = -sin(0); D(0,2) = 0;
    D(1,0) = sin(0); D(1,1) = cos(0); D(1,2) = 0;
    D(2,0) = 0; D(2,1) = 0; D(2,2) = 1;
    EXPECT_EQ(A, B);
    EXPECT_EQ(C, D);

    Matrix<double, 3> E = Matrix<double, 3>(90, 'x');
    B(0,0) = 1; B(0,1) = 0; B(0,2) = 0;
    B(1,0) = 0; B(1,1) = cos(M_PI/2); B(1,2) = -sin(M_PI/2);
    B(2,0) = 0; B(2,1) = sin(M_PI/2); B(2,2) = cos(M_PI/2);
    EXPECT_EQ(E, B);
}

TEST (Matrix, MultiplicationMatrixVector) {

    Matrix B = Matrix<double, 3>();
    Vector<double, 3> vec = Vector<double, 3>(1,2, 3);
    Vector<double, 3> result = Vector<double, 3>();

    B(0,0) = 1; B(0,1) = 1; B(0,2) = 0;
    B(1,0) = 0; B(1,1) = 2; B(1,2) = 0;
    B(2,0) = 0; B(2,1) = 0; B(2,2) = 3;
    result = B*vec;

    Vector<double, 3> result2 = Vector<double, 3>(3,4,9);
    EXPECT_EQ(result, result2);
}

TEST (Matrix, MultiplicationUnitByMatrixVector) {

    Matrix<double, 3> A = Matrix<double, 3>(0, 'z');
    Vector<double, 3> vec = Vector<double, 3>(1,2, 3);
    Vector<double, 3> result = Vector<double, 3>();
    result = A*vec;
    Vector<double, 3> result2 = Vector<double, 3>(1,2,3);
    EXPECT_EQ(result, result2);
}


TEST (Matrix, FailIndexing) {

    Matrix<double, 3> A = Matrix<double, 3>();
    Vector<double, 3> vec = Vector<double, 3>(1,1,3);
    Vector<double, 3> result = Vector<double, 3>();

    EXPECT_THROW(A(2,4), std::invalid_argument);
}
//
//TEST (Cuboid, EmptyConstructor) {
//
//    Rectangle Adam = Cuboid();
//    Rectangle Ewa = Cuboid();
//
//    Vector Vec0 = Vector();
//    Vector Vec1 = Vector();
//    Vector Vec2 = Vector();
//    Vector Vec3 = Vector();
//    Vector Vec4 = Vector();
//    Ewa.setCuboid(Vec0, Vec1, Vec2, Vec3, Vec4);
//
//    EXPECT_EQ(Adam, Ewa);
//}
//
//TEST (Cuboid, ConstructorWithVerticesInOrder) {
//
//    Vector Ver1 = Vector(1,3);
//    Vector Ver2 = Vector(3,3);
//    Vector Ver3 = Vector(3,1);
//    Vector Ver4 = Vector(1,1);
//
//    Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//    Cuboid Ewa = Rectangle();
//
//    Vector center = Vector(2,2);
//
//    Ewa.setCuboid(center, Ver1, Ver2, Ver3, Ver4);
//
//    EXPECT_EQ(Adam, Ewa);
//}
//
//TEST (Cuboid, ConstructorWithMixedUpVerticesInArguments) {
//
//    Vector Ver1 = Vector(1,3);
//    Vector Ver2 = Vector(3,3);
//    Vector Ver3 = Vector(3,1);
//    Vector Ver4 = Vector(1,1);
//
//    Cuboid Adam = Rectangle(Ver2, Ver1, Ver4, Ver3);
//    Rectangle Ewa = Cuboid();
//
//    Vector center = Vector(2,2);
//
//    Vector Vec1 = Vector(1,3);
//    Vector Vec2 = Vector(3,3);
//    Vector Vec3 = Vector(3,1);
//    Vector Vec4 = Vector(1,1);
//    Ewa.setCuboid(center, Vec1, Vec2, Vec3, Vec4);
//
//    EXPECT_EQ(Adam, Ewa);
//}
//
//TEST (Cuboid, FailConstructor) {
//
//    Vector Ver1 = Vector(1,3);
//    Vector Ver2 = Vector(3,3);
//    Vector Ver3 = Vector(3,1);
//    Vector Ver4 = Vector(1,1);
//
//    Cuboid Adam;
//
//    EXPECT_THROW(Adam = Cuboid(Ver1, Ver1, Ver4, Ver3), std::invalid_argument);
//}
//
//TEST (Cuboid, TranslationByWector) {
//
//    Vector Ver1 = Vector(1,3);
//    Vector Ver2 = Vector(3,3);
//    Vector Ver3 = Vector(3,1);
//    Vector Ver4 = Vector(1,1);
//    Vector translation = Vector(1,1);
//
//    Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//    Rectangle Ewa = Cuboid();
//    Adam.translationByVector(translation);
//    Vector center = Vector(3,3);
//    Vector Vec1 = Vector(2,4);
//    Vector Vec2 = Vector(4,4);
//    Vector Vec3 = Vector(4,2);
//    Vector Vec4 = Vector(2,2);
//
//    Ewa.setCuboid(center, Vec1, Vec2, Vec3, Vec4);
//
//    EXPECT_EQ(Adam, Ewa);
//}
//
//TEST (Cuboid, RotationByDegrees) {
//
//    Vector Ver1 = Vector(1, 3);
//    Vector Ver2 = Vector(3, 3);
//    Vector Ver3 = Vector(3, 1);
//    Vector Ver4 = Vector(1, 1);
//    Vector translation = Vector(1, 1);
//
//    Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//    Cuboid Ewa = Rectangle();
//    Adam.rotationByDegrees(90);
//
//    Vector center = Vector(-2, 2);
//    Vector Vec1 = Vector(-3, 1);
//    Vector Vec2 = Vector(-3, 3);
//    Vector Vec3 = Vector(-1, 3);
//    Vector Vec4 = Vector(-1, 1);
//
//    Ewa.setCuboid(center, Vec1, Vec2, Vec3, Vec4);
//
//    EXPECT_EQ(Adam, Ewa);
//}
//
//TEST (Cuboid, RectangleOstream) {
//
//    std::stringstream ost;
//    Vector Ver1 = Vector(1, 3);
//    Vector Ver2 = Vector(3, 3);
//    Vector Ver3 = Vector(3, 1);
//    Vector Ver4 = Vector(1, 1);
//
//    Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//    ost << Adam;
//    /* rectangle in cout give 10 decimal point fixed precision */
//    EXPECT_EQ("1 3\n3 3\n3 1\n1 1\n", ost.str());
//}
//
//TEST (Cuboid, GetSidesLength) {
//
//    std::stringstream ost;
//    Vector Ver1 = Vector(1, 3);
//    Vector Ver2 = Vector(3, 3);
//    Vector Ver3 = Vector(1, 1);
//    Vector Ver4 = Vector(3, 1);
//
//    Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//    std::pair<double,double> sides = Adam.getSidesLength(Ver1, Ver2, Ver3, Ver4);
//    double shorterSide = sides.first;
//    double longerSide = sides.second;
//
//    EXPECT_EQ(shorterSide, 2);
//    EXPECT_EQ(longerSide, 2);
//}
//
//TEST (Cuboid, Indexing) {
//
//std::stringstream ost;
//Vector Ver1 = Vector(1, 3);
//Vector Ver2 = Vector(3, 3);
//Vector Ver3 = Vector(1, 1);
//Vector Ver4 = Vector(3, 1);
//
//Rectangle Adam = Cuboid(Ver1, Ver2, Ver3, Ver4);
//
//
//EXPECT_EQ(Adam[0], Ver1);
//EXPECT_EQ(Adam[1], Ver2);
//EXPECT_EQ(Adam[2], Ver3);
//EXPECT_EQ(Adam[3], Ver4);
//
//}