#include "Matrix.h"
#include <iostream>

Matrix::Matrix() : rows(0), columns(0)
{
    this->matrix = new int[0];
}

Matrix::Matrix(int n, int m) : rows(n), columns(m)
{
    this->matrix = new int[rows * columns];
    for (int i = 0; i < rows * columns; i++)
    {
        this->matrix[i] = 0;
    }
}

Matrix::Matrix(const Matrix &matrixToCopy) : // SHELLY - Change parameter names
                                             rows(matrixToCopy.rows),
                                             columns(matrixToCopy.columns),
                                             matrix(new int[rows * columns]) // TODO - SHELLY - Adjust spacing
{
    for (int i = 0; i < rows * columns; i++)
    {
        matrix[i] = matrixToCopy.matrix[i];
    }
}

Matrix::~Matrix()
{
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
    for (int i = 0; i < rows * columns; i++)
    {
        matrix[i] = matrixToAssign.matrix[i];
    }
    return *this;
}

const int &Matrix::operator()(int i, int j) const
{
    if (i < 0 || j < 0 || i >= rows || j >= columns)
    {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i * columns + j];
}

int &Matrix::operator()(int i, int j)
{
    if (i < 0 || j < 0 || i >= rows || j >= columns)
    {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i * columns + j];
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    for (int i = 0; i < (m.rows); i++)
    {
        for (int j = 0; j < (m.columns); j++)
        {
            os << "|" << m(i, j);
        }
        os << "|" << "\n";
    }
    return os;
}

void Matrix::checkMatchingSizes(const Matrix &secondMatrix) const
{
    if (this->columns != secondMatrix.columns || this->rows != secondMatrix.rows)
    {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
}

// TODO - SHELLY - convert to outer operator + check bounds
Matrix operator+(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix result = Matrix(matrix1);
    result += matrix2;
    return result;
}

// SHELLY - Check matching sizes
Matrix &Matrix::operator+=(const Matrix &matrixToAdd)
{

    this->checkMatchingSizes(matrixToAdd);

    for (int i = 0; i < (this->rows * this->columns); i++)
    {
        (this->matrix)[i] = (this->matrix)[i] + (matrixToAdd.matrix)[i];
    }
    return *this;
}

// TODO - SHELLY - convert to outer operator + check bounds
Matrix operator-(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix result = Matrix(matrix1);
    result -= matrix2;
    return result;
}

// SHELLY - Check matching sizes
Matrix &Matrix::operator-=(const Matrix &matrixToSubtract)
{
    this->checkMatchingSizes(matrixToSubtract);

    for (int i = 0; i < (this->rows * this->columns); i++)
    {
        (this->matrix)[i] = (this->matrix)[i] - (matrixToSubtract.matrix)[i];
    }
    return *this;
}

// TODO - SHELLY - convert to outer operator + check bounds
Matrix operator*(const Matrix &matrix1, const Matrix &matrix2)
{
    Matrix result = Matrix(matrix1);
    result *= matrix2;
    return result;
}

// SHELLY - Check matching sizes
Matrix &Matrix::operator*=(const Matrix &matrixToMultiply)
{

    if (this->columns != matrixToMultiply.rows)
    {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix result = Matrix(this->rows, matrixToMultiply.columns);

    for (int i = 0; i < (this->rows); i++)
    {
        for (int j = 0; j < (matrixToMultiply.columns); j++)
        {

            int currentCell = 0;

            for (int counter = 0; counter < (this->columns); counter++)
            {
                currentCell += (*this)(i, counter) * (matrixToMultiply)(counter, j);
            }

            result(i, j) = currentCell;
        }
    }
    *this = result;
    return *this;
}

// SHELLY - Use previous operators
Matrix Matrix::operator-()
{
    return (*this) * -1;
}

// SHELLY - Use previous operators
Matrix operator*(const Matrix &matrixToMultiply, const int &lambda)
{
    Matrix result = Matrix(matrixToMultiply);
    result *= lambda;
    return result;
}

Matrix operator*(const int &lambda, const Matrix &matrixToMultiply)
{
    Matrix result = Matrix(matrixToMultiply);
    result *= lambda;
    return result;
}

// SHELLY - Simplify
Matrix &Matrix::operator*=(const int &lambda)
{
    for (int i = 0; i < (this->rows * this->columns); i++)
    {
        (this->matrix)[i] = lambda * (this->matrix)[i];
    }
    return *this;
}

// SHELLY - Adjust to 2 matrices
bool operator==(const Matrix &firstMatrix, const Matrix &secondMatrix)
{
    // std::cout << "entered ==" << std::endl;
    //  std::cout << "firstMatrix.rows: " << firstMatrix.rows << std::endl;
    //  std::cout << "secondMatrix.rows: " << secondMatrix.rows << std::endl;
    //  std::cout << "firstMatrix.columns: " << firstMatrix.columns << std::endl;
    //  std::cout << "secondMatrix.columns: " << secondMatrix.columns << std::endl;
    if (firstMatrix.rows != secondMatrix.rows || firstMatrix.columns != secondMatrix.columns)
    {
        return false;
    }

    for (int i = 0; i < (firstMatrix.rows * firstMatrix.columns); i++)
    {
        if ((firstMatrix.matrix)[i] != (secondMatrix.matrix)[i])
        {
        //      std::cout << "i: " << i << std::endl;
        //      std::cout << "firstMatrix.matrix[i]: " << (firstMatrix.matrix)[i] << std::endl;
        //      std::cout << "secondMatrix.matrix[i]: " << (secondMatrix.matrix)[i] << std::endl;
            return false;
        }
    }
    //  std::cout << "end of ==" << std::endl;
    return true;
}

bool operator!=(const Matrix& firstMatrix, const Matrix& secondMatrix){
    return !(*this == m2);
}

Matrix Matrix::rotateClockwise() {
    Matrix result(this->columns, this->rows);
    for(int j = 0; j < this->columns; j++) {
        for(int i = 0; i < this->rows; i++) {
            result(j,this->rows-1-i) = (*this)(i,j);
        }
    }
    return result;
}

Matrix Matrix::rotateCounterClockwise() {
    Matrix result(this->columns, this->rows);
    for(int j = 0; j < this->columns; j++) {
        for(int i = 0; i < this->rows; i++) {
            result(this->columns-1-j,i) = (*this)(i,j);
        }
    }
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
