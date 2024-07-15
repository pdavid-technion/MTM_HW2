#include "Utilities.h"
#include <iostream>

class Matrix
{

private:
    int rows;
    int columns;
    int *matrix;

public:
    int getRows();
    int getColumns();
    Matrix();
    Matrix(int n, int m);
    Matrix(const Matrix &matrixToCopy);
    ~Matrix();
    
    Matrix &operator=(const Matrix &matrixToAssign); // TODO - SHELLY - Check if need to add operator that returns const
    
    const int &operator()(int i, int j) const;
    int &operator()(int i, int j);

    Matrix &operator+=(const Matrix &matrixToAdd);
    Matrix &operator-=(const Matrix &matrixToSubtract);
    Matrix &operator*=(const Matrix &matrixToMultiply);
    Matrix operator-();
    Matrix operator*(const int &lambda) const; //SHELLY - Changed to work from a const instance
    Matrix &operator*=(const int &lambda); // DAVID - why did you pass the integer as a reference?
    Matrix rotateClockwise();

    void checkMatchingSizes(const Matrix &secondMatrix) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    friend bool operator==(const Matrix& firstMatrix, const Matrix& secondMatrix); // SHELLY - Fix to support 2 matrices
    friend bool operator!=(const Matrix& firstMatrix, const Matrix& secondMatrix); // SHELLY - Fix to support 2 matrices
    friend Matrix operator*(const Matrix &matrix1, const Matrix &matrix2); //SHELLY - Fix to support 2 matrice
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
Matrix operator+(const Matrix &matrix1, const Matrix &matrix2); //SHELLY - Fix to support 2 matrices
Matrix operator-(const Matrix &matrix1, const Matrix &matrix2); //SHELLY - Fix to support 2 matrices
Matrix operator*(const Matrix &matrix1, const Matrix &matrix2); //SHELLY - Fix to support 2 matrice
bool operator==(const Matrix& firstMatrix, const Matrix& secondMatrix);
bool operator!=(const Matrix& firstMatrix, const Matrix& secondMatrix);