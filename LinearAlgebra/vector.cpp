#include "general/numberUtility.h"
#include "general/abstractFunctions.h"
#include "general/stringUtility.h"

#include "vector.h"

#ifndef self
#define self (*this)
#endif

Vector::Vector(const vector<double>& entries) {
    this->entries = entries;
}

double& Vector::operator [] (int i) {
    return entries.at(i - 1);
}

int Vector::size() {
    return entries.size();
}

double Vector::length() {
    double sum = accumulate(entries.begin(), entries.end(), 0, [] (double rsf, double curr) {
        return rsf + curr * curr;    
    });
    return sqrt(sum);
}

string Vector::toString(int precision) {
    return toMatrix().toString(precision);
}

Matrix Vector::toMatrix() {
    return Matrix(absFunc::map_f<double, vector<double>>(entries, [] (double entry) -> vector<double> {
        return {entry};
    }));
}

Vector Vector::operator + (Vector other) {
    // TODO
    throw runtime_error("to be implemented");
}

Vector Vector::operator - (Vector other) {
    return self + (-1 * other);
}

// dot product
double Vector::operator * (Vector other) {
    // TODO
    throw runtime_error("to be implemented");
}

Vector Vector::crossProduct(Vector other) {
    // TODO
    throw runtime_error("to be implemented");
}

Matrix Vector::outerProduct(Vector other) {
    // TODO
    throw runtime_error("to be implemented");
}

Vector Vector::operator += (Vector other) {
    self = self + other;
    return self;
}

Vector Vector::operator -= (Vector other) {
    self = self - other;
    return self;
}

Vector Vector::operator *= (double scalar) {
    self = scalar * self;
    return self;
}

Vector operator * (double scalar, Vector vector) {
    // TODO
    throw runtime_error("to be implemented");
}

Vector Vector::generateRandomVector(int size, int lower, int upper) {
    return Vector(Matrix::generateRandomMatrix(size, 1, lower, upper).getColumn(1));
}