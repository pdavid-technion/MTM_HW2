#include "Matrix.h"

Matrix::Matrix() : rows(0), columns(0) {
    this->matrix = new int[0];
}

Matrix::Matrix(int n, int m) : rows(n), columns(m) {
    this->matrix = new int[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        this->matrix[i] = 0;
    }
}

Matrix::Matrix(const Matrix &matrixToCopy) :
    rows(matrixToCopy.rows),
    columns(matrixToCopy.columns),
    matrix(new int[rows * columns]) {
    for (int i = 0; i < rows * columns; i++) {
        matrix[i] = matrixToCopy.matrix[i];
    }
}

Matrix::~Matrix() {
    delete[] matrix;
}


Matrix &Matrix::operator=(const Matrix &matrixToAssign) {
    if (this == &matrixToAssign) {
        return *this;
    }
    rows = matrixToAssign.rows;
    columns = matrixToAssign.columns;
    
    delete[] matrix;
    
    matrix = new int[rows * columns];
    
    for (int i = 0; i < rows * columns; i++) {
        matrix[i] = matrixToAssign.matrix[i];
    }
    return *this;
}

const int &Matrix::operator()(int i, int j) const {
    if (i < 0 || j < 0 || i >= rows || j >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i * columns + j];
}

int &Matrix::operator()(int i, int j) {
    if (i < 0 || j < 0 || i >= rows || j >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i * columns + j];
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    if(m.rows == 0 || m.columns == 0 ) {
        return os;
    }

    for (int i = 0; i < (m.rows); i++) {
        for (int j = 0; j < (m.columns); j++) {
            os << "|" << m(i, j);
        }
        os << "|" << std::endl;
    }
    return os;
}

Matrix operator+(const Matrix &leftMatrix, const Matrix &rightMatrix) {
    Matrix result = Matrix(leftMatrix);
    result += rightMatrix;
    return result;
}

Matrix &Matrix::operator+=(const Matrix &matrixToAdd) {

      if (this->columns != matrixToAdd.columns || this->rows != matrixToAdd.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    for (int i = 0; i < (this->rows * this->columns); i++) {
        (this->matrix)[i] = (this->matrix)[i] + (matrixToAdd.matrix)[i];
    }
    
    return *this;
}

Matrix operator-(const Matrix &leftMatrix, const Matrix &rightMatrix) {
    Matrix result = Matrix(leftMatrix);
    result -= rightMatrix;
    return result;
}

Matrix &Matrix::operator-=(const Matrix &matrixToSubtract) {
      
    if (this->columns != matrixToSubtract.columns ||
        this->rows != matrixToSubtract.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    for (int i = 0; i < (this->rows * this->columns); i++) {
        (this->matrix)[i] = (this->matrix)[i] - (matrixToSubtract.matrix)[i];
    }
    return *this;
}

Matrix operator*(const Matrix &leftMatrix, const Matrix &rightMatrix) {
    Matrix result = Matrix(leftMatrix);
    result *= rightMatrix;
    return result;
}

Matrix &Matrix::operator*=(const Matrix &matrixToMultiply) {

    if (this->columns != matrixToMultiply.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix result = Matrix(this->rows, matrixToMultiply.columns);

    for (int i = 0; i < (this->rows); i++) {
        for (int j = 0; j < (matrixToMultiply.columns); j++) {

            int currentCell = 0;

            for (int counter = 0; counter < (this->columns); counter++) {
                currentCell += (*this)(i, counter) * (matrixToMultiply)(counter, j);
            }

            result(i, j) = currentCell;
        }
    }

    *this = result;
    return *this;
}

Matrix Matrix::operator-() {
    return (*this) * -1;
}

Matrix operator*(const Matrix &matrixToMultiply, const int &lambda) {
    Matrix result = Matrix(matrixToMultiply);
    result *= lambda;
    return result;
}

Matrix operator*(const int &lambda, const Matrix &matrixToMultiply) {
    Matrix result = Matrix(matrixToMultiply);
    result *= lambda;
    return result;
}

Matrix &Matrix::operator*=(const int &lambda) {
    for (int i = 0; i < (this->rows * this->columns); i++) {
        (this->matrix)[i] = lambda * (this->matrix)[i];
    }
    return *this;
}

bool operator==(const Matrix &leftMatrix, const Matrix &rightMatrix) {
    if (leftMatrix.rows != rightMatrix.rows || leftMatrix.columns != rightMatrix.columns) {
        return false;
    }

    for (int i = 0; i < (leftMatrix.rows * leftMatrix.columns); i++) {
        if ((leftMatrix.matrix)[i] != (rightMatrix.matrix)[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const Matrix &leftMatrix, const Matrix &rightMatrix) {
    return !(leftMatrix == rightMatrix);
}

Matrix Matrix::rotateClockwise() {
    Matrix result(this->columns, this->rows);
    for( int j = 0; j < this->columns; j++) {
        for( int i = 0; i < this->rows; i++) {
            result(j,this->rows-1-i) = (*this)(i,j);
        }
    }
    return result;
}

Matrix Matrix::rotateCounterClockwise() {
    Matrix result = this->rotateClockwise().rotateClockwise().rotateClockwise();
    return result;
}

Matrix Matrix::transpose() {
    Matrix result(this->columns, this->rows);
    for(int j = 0; j < this->columns; j++) {
        for(int i = 0; i < this->rows; i++) {
            result(j,i) = (*this)(i,j);
        }
    }
    return result;
}
