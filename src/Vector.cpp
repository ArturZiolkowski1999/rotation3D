//
// Created by artur on 3/18/21.
//

#include "Vector.h"

template <typename T>
Vector<T>::Vector(){
    int i = 0;
    while(i < VECTOR_DIM) {
        this->vector[i] = 0;
        i++;
    }
}

template <typename T>
Vector<T>::Vector(T _x, T _y, T _z){
    this->vector[0] = _x;
    this->vector[1] = _y;
    int i = 2;
    if (VECTOR_DIM >= 3){
        this->vector[2] = _z;
        i = 3;
    }
    while(i < VECTOR_DIM){
        this->vector[i] = 0;
        i++;
    }
}


template<typename T>
void Vector<T>::setX(T _x){
    if(VECTOR_DIM >=1) this->vector[0] = _x;
}

template<typename T>
void Vector<T>::setY(T _y){
    if(VECTOR_DIM >=2) this->vector[1] = _y;
}

template<typename T>
void Vector<T>::setZ(T _z) {
    if(VECTOR_DIM >=3) this->vector[2] = _z;
}

template<typename T>
bool operator==(const Vector<T> &Vec1, const Vector<T> &Vec2){
    if((std::abs(Vec1[0] - Vec2[0]) < MIN_THRESHOLD) &&
        (std::abs(Vec1[1] - Vec2[1]) < MIN_THRESHOLD)){
        return true;
    }
    return false;
}

template<typename T>
const T &Vector<T>::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vector[0];
        case 1:
            return this->vector[1];
        case 3:
            return this->vector[2];
        default:
            throw std::invalid_argument("");
    }
}

template<typename T>
T &Vector<T>::operator[](int index) {
    switch (index) {
        case 0:
            return this->vector[0];
        case 1:
            return this->vector[1];
        case 2:
            return this->vector[2];
        default:
            throw std::invalid_argument("");
    }
}

template<typename T>
Vector<T> operator+(Vector<T> &Vec1, Vector<T> &Vec2){
    Vector<T> result;
    result[0] = (Vec1[0] + Vec2[0]);
    result[1] = (Vec1[1] + Vec2[1]);
    result[2] = (Vec1[2] + Vec2[2]);
    return result;
}

template<typename T>
Vector<T> operator-(Vector<T> &Vec1, Vector<T> &Vec2){
    Vector<T> result;
    result[0] = (Vec1[0] - Vec2[0]);
    result[1] = (Vec1[1] - Vec2[1]);
    result[2] = (Vec1[2] - Vec2[2]);
    return result;
}

template<typename T>
Vector<T> operator*(Vector<T> &Vec, const double &Num){
    Vector<T> result;
    result[0] = (Vec[0] * Num);
    result[1] = (Vec[1] * Num);
    result[2] = (Vec[2] * Num);
    return result;
}

template<typename T>
Vector<T> operator/(Vector<T> &Vec, const double &Num){
    if(Num == 0){
        throw std::invalid_argument("division by zero");
    }
    Vector<T> result;
    result[0] = (Vec[0] / Num);
    result[1] = (Vec[1] / Num);
    result[2] = (Vec[2] / Num);
    return result;
}


template<typename T>
T Vector<T>::getLength(){
    double length = sqrt((this[0]) * (this[0]) + (this[1]) * (this[1]) + (this[2] * this[2]));
    return length;
}

template<typename T>
std::istream &operator>>(std::istream &ist, Vector<T> &Vec) {
    T x,y,z;
    std::cout << "enter x cord of vector:\n";
    ist >> x;
    Vec[0] = x;

    std::cout << "enter y cord of vector:\n";
    ist >> y;
    Vec[1] = y;

    std::cout << "enter z cord of vector:\n";
    ist >> z;
    Vec[2] = z;
    return ist;
}

template<typename T>
std::ostream & operator<<(std::ostream & ost, const Vector<T> &Vec){
    std::cout << std::fixed;
    std::cout << std::setprecision(VECTOR_PRECISION);
    ost << Vec.vector[0] << " ";
    ost << Vec.vector[1] << " ";
    ost << Vec.vector[2] << std::endl;
    return ost;
}

