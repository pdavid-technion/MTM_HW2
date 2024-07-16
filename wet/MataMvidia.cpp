#include "Utilities.h"
#include <iostream>
#include "MataMvidia.h"
#include "Matrix.h"

using std::ostream;
using std::string;

MataMvidia::MataMvidia(string movieName, string movieCreator, Matrix *frames, int size) :
    size(size),
    movieName(movieName),
    movieCreator(movieCreator) {
    this->frames = new Matrix[size];

    for (int i = 0; i < size; i++) {
        this->frames[i] = Matrix(frames[i]);
    }
}

MataMvidia::MataMvidia(const MataMvidia &movieToCopy) :
    size(movieToCopy.size),
    movieName(movieToCopy.movieName),
    movieCreator(movieToCopy.movieCreator) {

    this->frames = new Matrix[this->size];
    for (int i = 0; i < this->size; i++) {
        this->frames[i] = Matrix(movieToCopy.frames[i]);
    }
}

MataMvidia::~MataMvidia() {
    delete[] frames;
}

MataMvidia &MataMvidia::operator=(const MataMvidia &movieToAssign) {
    if (this == &movieToAssign) {
        return *this;
    }

    delete[] frames;
    movieName = movieToAssign.movieName;
    movieCreator = movieToAssign.movieCreator;
    size = movieToAssign.size;

    frames = new Matrix[size];

    for (int i = 0; i < size; i++) {
        frames[i] = Matrix(movieToAssign.frames[i]);
    }

    return *this;
}

const Matrix &MataMvidia::operator[](int frameIndex) const {
    if (frameIndex >= size) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[frameIndex];
}

Matrix &MataMvidia::operator[](int frameIndex) {
    if (frameIndex >= size) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[frameIndex];
}

MataMvidia &MataMvidia::operator+=(const MataMvidia &movieToAppend) {

    Matrix* allFrames = new Matrix[size + movieToAppend.size];

    for (int i = 0; i < size; i++) {
        allFrames[i] = frames[i];
    }

    for (int i = 0; i < movieToAppend.size; i++) {
        allFrames[size + i] = movieToAppend.frames[i];
    }

    size = size + movieToAppend.size;
    delete[] frames;

    frames = allFrames;

    return *this;
}

MataMvidia &MataMvidia::operator+=(const Matrix &frameToAppend) {
    Matrix* allFrames = new Matrix[size + 1];

    for( int i = 0; i < size; i++ ){
        allFrames[i] = Matrix(frames[i]);
    }

    allFrames[size] = Matrix(frameToAppend);
    delete[] frames;
    frames = allFrames;
    size++;

    return *this;
}

MataMvidia operator+(const MataMvidia& firstMovie, const MataMvidia& secondMovie) {
    MataMvidia combinedMovie = MataMvidia(firstMovie);
    combinedMovie += secondMovie;
    return combinedMovie;
}

std::ostream &operator<<(std::ostream &os, const MataMvidia& movie){
        os << "Movie Name: " << movie.movieName << std::endl;
        os << "Author: " << movie.movieCreator << std::endl << std::endl;

        for( int i = 0; i < movie.size; i++ ) {
            os << "Frame " << i << ":" << std::endl;
            os << movie.frames[i] << std::endl;
        }

        os << "-----End of Movie-----" << std::endl;

        return os;
}