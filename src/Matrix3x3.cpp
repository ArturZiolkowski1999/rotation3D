#include "Matrix3x3.h"
#include "Vector.h"

template<typename T>
Matrix3x3<T>::Matrix3x3() {
    this = Matrix3x3<T>(0, 'x');
}

template<typename T>
Matrix3x3<T>::Matrix3x3(double degree, char axis) {
    /* [cos(), -sin(), ...]
     * [sin(),  cos(), ...]
     * [..................] */

    double radians = degreeToRadians(degree);
    switch (axis) {
        case 'x':
            this->matrix[0][0] = 1;
            this->matrix[0][1] = 0;
            this->matrix[0][2] = 0;
            this->matrix[1][0] = 0;
            this->matrix[1][1] = cos(radians);
            this->matrix[1][2] = -sin(radians);
            this->matrix[2][0] = 0;
            this->matrix[2][1] = sin(radians);
            this->matrix[2][2] = cos(radians);
            break;
        case 'y':
            this->matrix[0][0] = cos(radians);
            this->matrix[0][1] = 0;
            this->matrix[0][2] = sin(radians);
            this->matrix[1][0] = 0;
            this->matrix[1][1] = 1;
            this->matrix[1][2] = 0;
            this->matrix[2][0] = -sin(radians);
            this->matrix[2][1] = 0;
            this->matrix[2][2] = cos(radians);
            break;
        case 'z':
            this->matrix[0][0] = cos(radians);
            this->matrix[0][1] = -sin(radians);
            this->matrix[0][2] = 0;
            this->matrix[1][0] = sin(radians);
            this->matrix[1][1] = cos(radians);
            this->matrix[1][2] = 0;
            this->matrix[2][0] = 0;
            this->matrix[2][1] = 0;
            this->matrix[2][2] = 1;
            break;
        default:
            std::cout << "unknown axis, try again\n";
            break;
    }

    int i = 3;
    int j = 3;
    while(i<MATRIX_DIM){
        while(j<MATRIX_DIM){
            /*2x times assign because all left matrix symmetrically should be zeroed */
            this->matrix[i][j] = 0;
            this->matrix[j][i] = 0;
            j++;
        }
        i++;
    }
}

template<typename T>
double Matrix3x3<T>::degreeToRadians(double degree){
    return degree * M_PI / 180;
}


bool operator==(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2){
    int i = 0;
    int j = 0;
    while(i < MATRIX_DIM){
        while(j < MATRIX_DIM){
            if(std::abs(matrix1.matrix[i][j] - matrix2.matrix[i][j]) > MIN_THRESHOLD){
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

Vector operator*(const Matrix2x2 &matrix, Vector &vec){
    Vector result = Vector();
    result.setX(vec.getX() * matrix.matrix[0][0] + vec.getY() * matrix.matrix[0][1]);
    result.setY(vec.getX() * matrix.matrix[1][0] + vec.getY() * matrix.matrix[1][1]);
    return result;
}

double &Matrix3x3::operator()(int row, int column) {
    if(row >= MATRIX_DIM || row < 0 || column >= MATRIX_DIM || column < 0){
        throw std::invalid_argument("index out of range");
    }
    return matrix[row][column];
}

const double &Matrix3x3::operator()(int row, int column) const {
    if(row >= MATRIX_DIM || row < 0 || column >= MATRIX_DIM || column < 0){
        throw std::invalid_argument("index out of range");
    }
    return matrix[row][column];
}
