#ifndef VECTOR_DOT_H
#define VECTOR_DOT_H

#include <vector>
#include <string>

#include "general/randomUtility.h"

#include "matrix.h"

using namespace std;

struct Matrix; // forward declaration

struct Vector {

    static RandUtil& randUtil;
    static Vector generateRandomVector(int size, int lower, int upper);

    vector<double> entries;

    Vector(const vector<double>& entries);
    
    double& operator [] (int i);

    int size();
    double length();

    string toString(int precision = 2);
    Matrix toMatrix();

    Vector operator + (Vector other);
    Vector operator - (Vector other);

    double operator * (Vector other); // dot product
    Vector crossProduct(Vector other);
    Matrix outerProduct(Vector other);

    Vector operator += (Vector other);
    Vector operator -= (Vector other);
    Vector operator *= (double scalar);

};

Vector operator * (double scalar, Vector vector);

#endif