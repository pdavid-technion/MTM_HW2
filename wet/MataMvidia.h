#pragma once
#include <string>
#include "Matrix.h"
#include <iostream>

using std::string;

class MataMvidia {
    private:
    int size;
    string movieName;
    string movieCreator;

    Matrix* frames;

    public:
    
    MataMvidia(string movieName, string movieCreator, Matrix* frames, int size);
    MataMvidia(const MataMvidia& movieToCopy);
    ~MataMvidia();
    
    MataMvidia& operator=(const MataMvidia& movieToAssign);
    const Matrix& operator[](int frameIndex) const;
    Matrix& operator[](int frameIndex);
    MataMvidia& operator+=(const MataMvidia& movieToAppend);
    MataMvidia& operator+=(const Matrix& frameToAppend);

    friend MataMvidia operator+(const MataMvidia& firstMovie, const MataMvidia& secondMovie);
    friend std::ostream &operator<<(std::ostream &os, const MataMvidia& movie);
    
};

MataMvidia operator+(const MataMvidia& firstMovie, const MataMvidia& secondMovie);
std::ostream &operator<<(std::ostream &os, const MataMvidia& movie);