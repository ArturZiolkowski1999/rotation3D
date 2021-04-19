
#ifndef ROTATION2D_MATRIX_H
#define ROTATION2D_MATRIX_H

#include <ios>
#include "Vector.h"

template <typename T>
class Matrix3x3 {
private:
    T matrix[MATRIX_DIM][MATRIX_DIM];
    double degreeToRadians(double degree);
public:
    Matrix3x3();
    Matrix3x3(double degree, char axis);

//    friend bool operator==(const Matrix3x3 &matrix1, const Matrix3x3 &matrix2);
//    friend Vector<double> operator*(const Matrix3x3 &matrix, Vector<double> &vec);
//    double &operator()(int row, int column);
//    const double &operator()(int row, int column) const;
};

#endif //ROTATION2D_MATRIX_H