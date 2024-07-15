#include "Matrix.h"

Matrix::Matrix(): rows(0), columns(0) {
    this->matrix = new int[0];
}

Matrix::Matrix(int n, int m): rows(n), columns(m) {
    this->matrix = new int[rows*columns];
    for(int i=0; i<rows*columns; i++) {
        this->matrix[i] = 0;
    }   
}

Matrix::~Matrix() {
    delete[] matrix;
}

int Matrix::getRows()
{
    return this->rows;
}
int Matrix::getColumns()
{
    return this->columns;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if(this == &m){
        return *this;
    }
    rows = m.rows;
    columns = m.columns;
    delete[] matrix;
    matrix = new int[rows*columns];
    for(int i=0; i<rows*columns; i++){
        matrix[i] = m.matrix[i];
    }
    return *this;
}

Matrix::Matrix(const Matrix& m) :
    rows(m.rows),
    columns(m.columns),
    matrix(new int[rows*columns])
{
    for(int i=0; i<rows*columns; i++){
        matrix[i] = m.matrix[i];
    }
}

int& Matrix::operator()(int i, int j) const{
    if(i < 0 || j < 0 || i >= rows || j >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i*columns + j]; 
}

int& Matrix::operator()(int i, int j){
    if(i < 0 || j < 0 || i >= rows || j >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i*columns + j]; 
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for(int i=0; i<(m.rows); i++){
        for(int j=0; j<(m.columns); j++) {
            os << "|" << m(i,j);
        }
        os << "|" << "\n";
    }
    return os;
}

Matrix Matrix::operator+(const Matrix& m2) {
    Matrix *m1 = this;
    Matrix result(m1->rows, m1->columns);
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (result.matrix)[i] = (m1->matrix)[i] + (m2.matrix)[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m2) {
    Matrix *m1 = this;
    Matrix result(m1->rows, m1->columns);
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (result.matrix)[i] = (m1->matrix)[i] - (m2.matrix)[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m2) {
    Matrix *m1 = this;
    Matrix result(m1->rows, m2.columns);
    for(int i=0; i<(m1->rows); i++) {
        for(int j=0; j<(m2.columns); j++) {
            int temp = 0;
            for(int counter=0; counter<(m1->columns); counter++) {
                temp += (*m1)(i, counter) * (m2)(counter, j);
            }
            result(i,j) = temp;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& m2) {
    Matrix *m1 = this;
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (m1->matrix)[i] = (m1->matrix)[i] + (m2.matrix)[i];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m2) {
    Matrix *m1 = this;
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (m1->matrix)[i] = (m1->matrix)[i] - (m2.matrix)[i];
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m2) {
    Matrix *m1 = this;
    Matrix result(m1->rows, m2.columns);
    for(int i=0; i<(m1->rows); i++) {
        for(int j=0; j<(m2.columns); j++) {
            int temp = 0;
            for(int counter=0; counter<(m1->columns); counter++) {
                temp += (*m1)(i, counter) * (m2)(counter, j);
            }
            result(i,j) = temp;
        }
    }
    *this = result;
    return *this;
}

Matrix Matrix::operator-() {
    Matrix *m1 = this;
    Matrix result(m1->rows, m1->columns);
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (result.matrix)[i] = -(m1->matrix)[i];
    }
    return result;
}

Matrix Matrix::operator*(const int& lambda) {
    Matrix *m1 = this;
    Matrix result(m1->rows, m1->columns);
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (result.matrix)[i] = lambda*(m1->matrix)[i];
    }
    return result;
}



Matrix& Matrix::operator*=(const int& lambda) {
    Matrix *m1 = this;
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        (m1->matrix)[i] = lambda*(m1->matrix)[i];
    }
    return *this;
}


bool Matrix::operator==(const Matrix& m2) {
    Matrix *m1 = this;
    if(m1->rows != m2.rows || m1->columns != m2.columns) {
        return false;
    }
    for(int i=0; i<(m1->rows*m1->columns); i++) {
        if((m1->matrix)[i] != (m2.matrix)[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m2) {
    return !(*this==m2);
}

Matrix Matrix::rotateClockwise() {
    Matrix *m1 = this;
    Matrix result(m1->columns, m1->rows);
    for(int j=0; j<m1->columns; j++) {
        for(int i=0; i<result.rows; i++) {
            result(j,i) = (*m1)(i,j);
        }
    }
    return result;
}

