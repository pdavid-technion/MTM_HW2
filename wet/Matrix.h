#include "Utilities.h"
#include <iostream>

class Matrix {
    public:
    int getRows();
    int getColumns();
    Matrix();
    Matrix(int n,int m);
    ~Matrix();
    Matrix& operator=(const Matrix& m);
    Matrix(const Matrix& m);
    int& operator()(int i, int j) const;
    int& operator()(int i, int j);
    Matrix operator+(const Matrix& m2);
    Matrix operator-(const Matrix& m2);
    Matrix operator*(const Matrix& m2);
    Matrix& operator+=(const Matrix& m2);
    Matrix& operator-=(const Matrix& m2);
    Matrix& operator*=(const Matrix& m2);
    Matrix operator-();
    Matrix operator*(const int& lambda);
    Matrix& operator*=(const int& lambda);
    bool operator==(const Matrix& m2);
    bool operator!=(const Matrix& m2);
    Matrix rotateClockwise();
    

    private:
    int rows;
    int columns;
    int *matrix;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);