//
// Created by artur on 3/17/21.
//



#ifndef ROTATION2D_CUBOID_H
#define ROTATION2D_CUBOID_H
#include <iostream>
#include <utility>
#include <float.h>
#include "Matrix.h"
#include "Constants.h"
#include "Vector.h"

//class Rectangle {
//private:
//
//    Vector centerOfMass; // i left this because it help when you want rotate vector over axis perpendicular to center of rectangle
//    Vector vertices[VERTICES_NUMBER];
//    void sortVertices(Vector &Vec1, Vector &Vec2, Vector &Vec3, Vector &Vec4);
//
//public:
//    Rectangle();
//    Rectangle(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
//    /* Set all parameters strictly */
//    void setRectangle(Vector &center, Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
//    friend bool operator==(const Rectangle &Rect1, const Rectangle &Rect2);
//    const Vector & operator[](int index) const;
//    Vector & operator[](int index);
//    void rotationByDegrees(double degree);
//    void translationByVector(Vector &Vec);
//    friend std::ostream & operator<<(std::ostream & ost, Rectangle &Rect);
//    std::pair<double, double> getSidesLength(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
//};
//
//
//Rectangle::Rectangle(){
//    for(int i = 0; i < VERTICES_NUMBER; i++){
//        this->vertices[i] = Vector();
//    }
//    this->centerOfMass = Vector();
//}
//
//void Rectangle::sortVertices(Vector &Vec1, Vector &Vec2, Vector &Vec3, Vector &Vec4){
//    Vector vertices[VERTICES_NUMBER] = {Vec1, Vec2, Vec3, Vec4};
//    Vector sortedVertices[VERTICES_NUMBER];
//    //simple sort on vectors
//    Vector smallest = Vector(DBL_MAX/2, DBL_MAX/2);
//    int smallestIndex;
//    for(int j = 0; j < VERTICES_NUMBER; j++) {
//        for (int i = 0; i < VERTICES_NUMBER; i++) {
//            if ((vertices[i].getX() + vertices[i].getY()) < (smallest.getX() + smallest.getY())) {
//                smallest = vertices[i];
//                smallestIndex = i;
//            }
//        }
//        vertices[smallestIndex] = Vector(DBL_MAX/2, DBL_MAX/2);
//        sortedVertices[j] = smallest;
//        smallest = Vector(DBL_MAX/2, DBL_MAX/2);
//    }
//    //[0] -> Left down corner, [3] -> right up corner, [2][1] -> rest corners
//    // [1 2]                        [3 2]
//    // [4 3] <- rectangle final or  [4 1]
//
//    Vec1 = sortedVertices[1];
//    Vec2 = sortedVertices[3];
//    Vec3 = sortedVertices[2];
//    Vec4 = sortedVertices[0];
//}
//
//Rectangle::Rectangle(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){
//
//    sortVertices(ver1, ver2, ver3, ver4);
//    if (ver1 == ver2 || ver1 == ver3 || ver1 == ver4 || ver2 == ver3 || ver2 == ver4 || ver3 == ver4){
//        throw std::invalid_argument("one ore more vertices is the same in rectangle");
//    }
//    Vector tmp1 = ver2 - ver4;
//    Vector tmp2 = tmp1 / 2;
//    Vector center = tmp2 + ver4;
//    this->vertices[0] = ver1;
//    this->vertices[1] = ver2;
//    this->vertices[2] = ver3;
//    this->vertices[3] = ver4;
//    this->centerOfMass = center;
//    for(int i = 4; i < VERTICES_NUMBER; i++){
//        this->vertices[i] = Vector();
//    }
//}
//
//void Rectangle::setRectangle(Vector &center, Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){
//    this->vertices[0] = ver1;
//    this->vertices[1] = ver2;
//    this->vertices[2] = ver3;
//    this->vertices[3] = ver4;
//    this->centerOfMass = center;
//}
//
//bool operator==(const Rectangle &Rect1, const Rectangle &Rect2){
//    if(Rect1.centerOfMass == Rect2.centerOfMass &&
//       Rect1.vertices[0] == Rect2.vertices[0] &&
//       Rect1.vertices[1] == Rect2.vertices[1] &&
//       Rect1.vertices[2] == Rect2.vertices[2] &&
//       Rect1.vertices[3] == Rect2.vertices[3] ){
//        return true;
//    }
//    return false;
//}
//
//void Rectangle::translationByVector(Vector &Vec){
//    this->centerOfMass = this->centerOfMass + Vec;
//    this->vertices[0] = Vec + (this->vertices[0]);
//    this->vertices[1] = Vec + (this->vertices[1]);
//    this->vertices[2] = Vec + (this->vertices[2]);
//    this->vertices[3] = Vec + (this->vertices[3]);
//}
//
//void Rectangle::rotationByDegrees(double degree){
//    Matrix rotation = Matrix3x3(degree);
//    this->centerOfMass = rotation * (this->centerOfMass);
//    this->vertices[0] = rotation * (this->vertices[0]);
//    this->vertices[1] = rotation * (this->vertices[1]);
//    this->vertices[2] = rotation * (this->vertices[2]);
//    this->vertices[3] = rotation * (this->vertices[3]);
//}
//
//std::ostream & operator<<(std::ostream & ost, Rectangle &Rect){
//    Vector Ver1 = Rect.vertices[0];
//    Vector Ver2 = Rect.vertices[1];
//    Vector Ver3 = Rect.vertices[2];
//    Vector Ver4 = Rect.vertices[3];
//    ost << Ver1 << Ver2 << Ver3 << Ver4;
//    return ost;
//}
//
//std::pair<double, double> Rectangle::getSidesLength(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){
//    sortVertices(ver1, ver2, ver3, ver4);
//    //ver4 -> Left down corner, ver2 -> right up corner, ver1, ver3 -> rest corners
//    std::pair<double, double> sides;
//    double tmp;
//    Vector side1 = ver4 - ver3;
//    Vector side2 = ver4 - ver1;
//    sides.first = side1.getLength();
//    sides.second = side2.getLength();
//    if(sides.first < sides.second){
//        tmp = sides.first;
//        sides.first = sides.second;
//        sides.second = tmp;
//    }
//    return sides;
//}
//
//const Vector &Rectangle::operator[](int index) const {
//    switch (index) {
//        case 0:
//            return this->vertices[0];
//        case 1:
//            return this->vertices[1];;
//        case 2:
//            return this->vertices[2];
//        case 3:
//            return this->vertices[3];
//        default:
//            throw std::invalid_argument("");
//    }
//}
//
//Vector &Rectangle::operator[](int index) {
//    switch (index) {
//        case 0:
//            return this->vertices[0];
//        case 1:
//            return this->vertices[1];;
//        case 2:
//            return this->vertices[2];
//        case 3:
//            return this->vertices[3];
//        default:
//            throw std::invalid_argument("");
//    }
//}

#endif //ROTATION2D_CUBOID_H
