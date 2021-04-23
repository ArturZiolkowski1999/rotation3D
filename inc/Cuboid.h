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

template<typename T>
class Cuboid {
private:

    Vector<T, 3> vertices[VERTICES_NUMBER];
    T sidesLength[SIDES_NUMBER];
//    void sortVertices(Vector<T,dimension> *Vec1); // <- you have to specify vertices in correct order now

public:
    Cuboid();
    Cuboid(Vector<T, 3> *ver);
    /* Set all parameters strictly */
    template<typename T1>
    friend bool operator==(const Cuboid<T1> &cub1, const Cuboid<T1> &cub2);
    void translationByVector(const Vector<T, 3> &Vec);
    void rotationByMatrix(const Matrix<T, 3> &rotMatrix);

    const Vector<T, 3> & operator[](int index) const;
    Vector<T, 3> & operator[](int index);

    template<typename T1>
    friend std::ostream & operator<<(std::ostream & ost, Rectangle &Rect);

    void calculateSidesLength();
};


template<typename T>
Cuboid<T>::Cuboid() {
    for(int i = 0; i < VERTICES_NUMBER; i++){
        this->vertices[i] = Vector<T, 3>();
    }
}

//template<typename T, unsigned int dimension>
//void Cuboid<T, dimension>::sortVertices(Vector<T, dimension> *Vec){
//    Vector sortedVertices[dimension] = ;
//    //simple sort on vectors
//    Vector smallest = Vec[0];
//    int smallestIndex;
//    for(int j = 0; j < dimension; j++) {
//        for (int i = 0; i < dimension; i++) {
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

template<typename T>
Cuboid<T>::Cuboid(Vector<T, 3> *ver){

// VERTICES_NUMBER have to be equal 8; there is no sort of vertices
//  Front  | Back <- vertices number
//  3   2  | 7   6
//  0   1  | 4   5
//

    for(int i = 0; i < VERTICES_NUMBER; i++){
        this->vertices[i] = ver[i];
        for(int j = 0; j < VERTICES_NUMBER; j++){
            if(i != j){
                if(ver[i] == ver[j]){
                    throw std::invalid_argument("one or more vertices is the same in cuboid");
                }
            }
        }
    }

}

template<typename T>
bool operator==(const Cuboid<T> &cub1, const Cuboid<T> &cub2){
    if(
       cub1.vertices[0] == cub2.vertices[0] &&
       cub1.vertices[1] == cub2.vertices[1] &&
       cub1.vertices[2] == cub2.vertices[2] &&
       cub1.vertices[3] == cub2.vertices[3] &&
       cub1.vertices[4] == cub2.vertices[4] &&
       cub1.vertices[5] == cub2.vertices[5] &&
       cub1.vertices[6] == cub2.vertices[6] &&
       cub1.vertices[7] == cub2.vertices[7] ){
        return true;
    }
    return false;
}

template<typename T>
void Cuboid<T>::translationByVector(const Vector<T, 3> &Vec){
    this->vertices[0] = Vec + (this->vertices[0]);
    this->vertices[1] = Vec + (this->vertices[1]);
    this->vertices[2] = Vec + (this->vertices[2]);
    this->vertices[3] = Vec + (this->vertices[3]);
    this->vertices[4] = Vec + (this->vertices[4]);
    this->vertices[5] = Vec + (this->vertices[5]);
    this->vertices[6] = Vec + (this->vertices[6]);
    this->vertices[7] = Vec + (this->vertices[7]);
}

template<typename  T>
void Cuboid<T>::rotationByMatrix(const Matrix<T, 3> &rotMatrix){

    this->vertices[0] = rotMatrix * (this->vertices[0]);
    this->vertices[1] = rotMatrix * (this->vertices[1]);
    this->vertices[2] = rotMatrix * (this->vertices[2]);
    this->vertices[3] = rotMatrix * (this->vertices[3]);
    this->vertices[4] = rotMatrix * (this->vertices[4]);
    this->vertices[5] = rotMatrix * (this->vertices[5]);
    this->vertices[6] = rotMatrix * (this->vertices[6]);
    this->vertices[7] = rotMatrix * (this->vertices[7]);
}

template<typename  T>
const Vector<T, 3> &Cuboid<T>::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];;
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("");
    }
}

template<typename  T>
Vector<T, 3> &Cuboid<T>::operator[](int index) {
    switch (index) {
        case 0:
            return this->vertices[0];
        case 1:
            return this->vertices[1];;
        case 2:
            return this->vertices[2];
        case 3:
            return this->vertices[3];
        case 4:
            return this->vertices[4];
        case 5:
            return this->vertices[5];;
        case 6:
            return this->vertices[6];
        case 7:
            return this->vertices[7];
        default:
            throw std::invalid_argument("");
    }
}

template<typename T>
void Cuboid<T>::calculateSidesLength(){

    //ver 01 -> len [0]; ver 12 -> len [1] ... itd ver 04 -> len[8]; ver 15 -> len[9] ... ver 37 -> len [11]
    Vector<T, 3> side = Vector<T, 3>();
    for(int i = 0; i < VERTICES_NUMBER; i ++){
        side = this->vertices[i+] - this->vertices[0];
    }

    this->sidesLength[0] =
    std::pair<double, double> sides;
    double tmp;
    Vector side1 = ver4 - ver3;
    Vector side2 = ver4 - ver1;
    sides.first = side1.getLength();
    sides.second = side2.getLength();
    if(sides.first < sides.second){
        tmp = sides.first;
        sides.first = sides.second;
        sides.second = tmp;
    }
    return sides;
}

//std::ostream & operator<<(std::ostream & ost, Cuboid &Rect){
//    Vector Ver1 = Rect.vertices[0];
//    Vector Ver2 = Rect.vertices[1];
//    Vector Ver3 = Rect.vertices[2];
//    Vector Ver4 = Rect.vertices[3];
//    ost << Ver1 << Ver2 << Ver3 << Ver4;
//    return ost;
//}
//



#endif //ROTATION2D_CUBOID_H
