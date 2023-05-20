#ifndef VECTOR_DOT_H
#define VECTOR_DOT_H

#include <vector>
#include <string>

#include "matrix.h"

using namespace std;

struct Matrix; // forward declaration

struct Vector {

    vector<double> entries;

    Vector(const vector<double>& entries);
    
    double& operator [] (int i);

    int size();
    double length();

    string toString(int precision = 2);
    Matrix toMatrix();

};

#endif