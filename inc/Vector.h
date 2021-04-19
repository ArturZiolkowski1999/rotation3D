//
// Created by artur on 3/18/21.
//
#ifndef ROTATION2D_VECTOR_H
#define ROTATION2D_VECTOR_H
#include "Constants.h"
#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T>
class Vector {
private:
    T vector[VECTOR_DIM];
public:

    Vector();
    Vector(T _x, T _y, T _z);
    friend bool operator==(const Vector<T> &Vec1, const Vector<T> &Vec2);
    friend Vector<T> operator+(Vector<T> &Vec1, Vector<T> &Vec2);
    friend Vector<T> operator-(Vector<T> &Vec1, Vector<T> &Vec2);
    friend Vector<T> operator/(Vector<T> &Vec, const double &Num);
    friend Vector<T> operator*(Vector<T> &Vec, const double &Num);
    const T & operator[](int index) const;
    T & operator[](int index);
//
    T getLength();
    friend std::ostream & operator<<(std::ostream & ost, const Vector<T> &Vec);
    friend std::istream & operator>>(std::istream & ist, Vector<T> &Vec);
    void setX(T _x);
    void setY(T _y);
    void setZ(T _z);
};



#endif //ROTATION2D_VECTOR_H
