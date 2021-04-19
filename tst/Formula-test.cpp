#include "gtest/gtest.h"
#include "Matrix3x3.h"
#include <iostream>
#include <utility>
#include "Rectangle.h"
#include "Constants.h"
#include "Vector.h"



TEST (Vector, EmptyConstructor) {


    Vector<double> Vec1 = Vector<double>();
    Vector<double> Vec2 = Vector<double>();
    Vec1.setX(0);
    Vec1.setY(0);
    Vec1.setZ(0);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, Constructor) {

    Vector<double> Vec1 = Vector<double>(2.3,4.5, 1.1);
    Vector<double> Vec2 = Vector<double>();
    Vec2.setX(2.3);
    Vec2.setY(4.5);
    Vec2.setZ(1.1);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, floatConstructor) {

    Vector<float> Vec1 = Vector<float>(2.3,4.5, 1.1);
    Vector<float> Vec2 = Vector<float>();
    Vec2.setX(2.3);
    Vec2.setY(4.5);
    Vec2.setZ(1.1);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, intConstructor) {

    Vector<int> Vec1 = Vector<int>(2,4, 1);
    Vector<int> Vec2 = Vector<int>();
    Vec2.setX(2);
    Vec2.setY(4);
    Vec2.setZ(1);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector, Addition) {

    Vector<double> Vec1 = Vector<double>(2.3,4.5, 1.1);
    Vector<double> Vec2 = Vector<double>(1,1, 1);

    EXPECT_EQ(Vec1 + Vec2, Vector<double>(3.3, 5.5, 2.1));
}

TEST (Vector, Subtruction) {

    Vector<double> Vec1 = Vector<double>(2.3,4.5, 1.1);
    Vector<double> Vec2 = Vector<double>(1,1, 1);

    EXPECT_EQ(Vec1 - Vec2, Vector<double>(1.3, 3.5, 0.1));
}

TEST (Vector, Multiplication) {

    Vector<double> Vec1 = Vector<double>(2,4, 5);

    EXPECT_EQ(Vec1 * 2, Vector<double>(4, 8, 10));
}

TEST (Vector, Division) {

    Vector<double> Vec1 = Vector<double>(2,4, 8);

    EXPECT_EQ(Vec1 / 2, Vector<double>(1, 2, 4));
}

TEST (Vector, FailDivision) {

    Vector<double> Vec1 = Vector<double>(2,4, 8);

    EXPECT_THROW(Vec1 / 0, std::invalid_argument);
}

TEST (Vector, FailIndexing) {

    Vector<double> Vec1 = Vector<double>(2,4, 8);

    EXPECT_THROW(Vec1[6], std::invalid_argument);
}

TEST (Vector, Indexing) {

    Vector<double> Vec1 = Vector<double>(2,4,8);

    EXPECT_EQ(Vec1[1], 4);

    Vec1[0] = 3;
    Vec1[1] = 4;
    Vec1[2] = 6;
    EXPECT_EQ(Vec1, Vector<double>(3, 4, 6));

}

TEST (Vector, Ostream) {

    std::stringstream ost;
    Vector<double> vec = Vector<double>(3.1, 3.1, 7.5);
    ost << vec;
    /* in cout program print double in 10 decimal point fixed precision, but i didnt know how to automaticly test cout*/
    EXPECT_EQ("3.1 3.1 7.5\n", ost.str());
}

TEST (Vector, GetLength) {

    Vector<double> Vec1 = Vector<double>(0, 4, 3);
    double length = Vec1.getLength();
    EXPECT_EQ(length, 5);

    Vec1 = Vector<double>(6,0,0);
    length = Vec1.getLength();
    EXPECT_EQ(length, 6);
}

TEST (Matrix, EmptyConstructor) {
    Matrix3x3 A = Matrix3x3();
    Matrix3x3 B = Matrix3x3();

    B.setMatrix(0,0,0,0);
    EXPECT_EQ(A, B);
}

TEST (Matrix, Constructor) {

    Matrix3x3 A = Matrix3x3(90);
    Matrix3x3 B = Matrix3x3();

    Matrix3x3 C = Matrix3x3(0);
    Matrix3x3 D = Matrix3x3();

    B.setMatrix(cos(M_PI/2),-sin(M_PI/2),sin(M_PI),cos(M_PI/2));
    D.setMatrix(cos(0),-sin(0),sin(0),cos(0));
    EXPECT_EQ(A, B);
    EXPECT_EQ(C, D);

}

TEST (Matrix, MultiplicationMatrixVector) {

    Matrix3x3 A = Matrix3x3();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_EQ(result, Vector(3,7));
}

TEST (Matrix, MultiplicationUnitByMatrixVector) {

    Matrix3x3 A = Matrix3x3(0);
    Vector vec = Vector(1,2);
    Vector result = Vector();
    result = A*vec;

    EXPECT_EQ(result, Vector(1,2));
}

TEST (Matrix, Indexing) {

    Matrix3x3 A = Matrix3x3();
    Matrix3x3 B = Matrix3x3();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    B(0,0) = 1;
    B(0,1) = 2;
    B(1,0) = 3;
    B(1,1) = 4;
    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_EQ(result, Vector(3,7));
    EXPECT_EQ(A(0,1), 2);
}

TEST (Matrix, FailIndexing) {

    Matrix3x3 A = Matrix3x3();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_THROW(A(2,4), std::invalid_argument);
}

TEST (Rectangle, EmptyConstructor) {

    Rectangle Adam = Rectangle();
    Rectangle Ewa = Rectangle();

    Vector Vec0 = Vector();
    Vector Vec1 = Vector();
    Vector Vec2 = Vector();
    Vector Vec3 = Vector();
    Vector Vec4 = Vector();
    Ewa.setRectangle(Vec0, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle, ConstructorWithVerticesInOrder) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();

    Vector center = Vector(2,2);

    Ewa.setRectangle(center, Ver1, Ver2, Ver3, Ver4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle, ConstructorWithMixedUpVerticesInArguments) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);

    Rectangle Adam = Rectangle(Ver2, Ver1, Ver4, Ver3);
    Rectangle Ewa = Rectangle();

    Vector center = Vector(2,2);

    Vector Vec1 = Vector(1,3);
    Vector Vec2 = Vector(3,3);
    Vector Vec3 = Vector(3,1);
    Vector Vec4 = Vector(1,1);
    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle, FailConstructor) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);

    Rectangle Adam;

    EXPECT_THROW(Adam = Rectangle(Ver1, Ver1, Ver4, Ver3), std::invalid_argument);
}

TEST (Rectangle, TranslationByWector) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);
    Vector translation = Vector(1,1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();
    Adam.translationByVector(translation);
    Vector center = Vector(3,3);
    Vector Vec1 = Vector(2,4);
    Vector Vec2 = Vector(4,4);
    Vector Vec3 = Vector(4,2);
    Vector Vec4 = Vector(2,2);

    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle, RotationByDegrees) {

    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(3, 1);
    Vector Ver4 = Vector(1, 1);
    Vector translation = Vector(1, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();
    Adam.rotationByDegrees(90);

    Vector center = Vector(-2, 2);
    Vector Vec1 = Vector(-3, 1);
    Vector Vec2 = Vector(-3, 3);
    Vector Vec3 = Vector(-1, 3);
    Vector Vec4 = Vector(-1, 1);

    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle, RectangleOstream) {

    std::stringstream ost;
    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(3, 1);
    Vector Ver4 = Vector(1, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    ost << Adam;
    /* rectangle in cout give 10 decimal point fixed precision */
    EXPECT_EQ("1 3\n3 3\n3 1\n1 1\n", ost.str());
}

TEST (Rectangle, GetSidesLength) {

    std::stringstream ost;
    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(1, 1);
    Vector Ver4 = Vector(3, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    std::pair<double,double> sides = Adam.getSidesLength(Ver1, Ver2, Ver3, Ver4);
    double shorterSide = sides.first;
    double longerSide = sides.second;

    EXPECT_EQ(shorterSide, 2);
    EXPECT_EQ(longerSide, 2);
}

TEST (Rectangle, Indexing) {

std::stringstream ost;
Vector Ver1 = Vector(1, 3);
Vector Ver2 = Vector(3, 3);
Vector Ver3 = Vector(1, 1);
Vector Ver4 = Vector(3, 1);

Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);


EXPECT_EQ(Adam[0], Ver1);
EXPECT_EQ(Adam[1], Ver2);
EXPECT_EQ(Adam[2], Ver3);
EXPECT_EQ(Adam[3], Ver4);

}