#pragma once
#include "Utilities.h"
#include <iostream>

class Matrix
{

private:
    int rows;
    int columns;
    int* matrix;

public:
    Matrix();
    Matrix(int n, int m);
    Matrix(const Matrix &matrixToCopy);
    ~Matrix();
    
    Matrix& operator=(const Matrix &matrixToAssign);
    
    const int& operator()(int i, int j) const;
    int& operator()(int i, int j);

    Matrix &operator+=(const Matrix &matrixToAdd);
    Matrix &operator-=(const Matrix &matrixToSubtract);
    Matrix &operator*=(const Matrix &matrixToMultiply);
    Matrix operator-();
    
    Matrix &operator*=(const int &lambda);
    Matrix rotateClockwise();
    Matrix rotateCounterClockwise();
    Matrix transpose();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    friend bool operator==(const Matrix& firstMatrix, const Matrix& secondMatrix);
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
Matrix operator+(const Matrix &leftMatrix, const Matrix &rightMatrix);
Matrix operator-(const Matrix &leftMatrix, const Matrix &rightMatrix);
Matrix operator*(const Matrix &leftMatrix, const Matrix &rightMatrix);
bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix);
bool operator!=(const Matrix& leftMatrix, const Matrix& rightMatrix);
Matrix operator*(const Matrix &matrixToMultiply, const int &lambda);
Matrix operator*(const int &lambda, const Matrix &matrixToMultiply);
