//
// Created by artur on 3/17/21.
//



#ifndef ROTATION2D_RECTANGLE_H
#define ROTATION2D_RECTANGLE_H
#include <iostream>
#include <utility>
#include <float.h>
#include "Matrix3x3.h"
#include "Constants.h"
#include "Vector.h"

class Rectangle {
private:

    Vector centerOfMass; // i left this because it help when you want rotate vector over axis perpendicular to center of rectangle
    Vector vertices[VERTICES_NUMBER];
    void sortVertices(Vector &Vec1, Vector &Vec2, Vector &Vec3, Vector &Vec4);

public:
    Rectangle();
    Rectangle(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
    /* Set all parameters strictly */
    void setRectangle(Vector &center, Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
    friend bool operator==(const Rectangle &Rect1, const Rectangle &Rect2);
    const Vector & operator[](int index) const;
    Vector & operator[](int index);
    void rotationByDegrees(double degree);
    void translationByVector(Vector &Vec);
    friend std::ostream & operator<<(std::ostream & ost, Rectangle &Rect);
    std::pair<double, double> getSidesLength(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
};
#endif //ROTATION2D_RECTANGLE_H
