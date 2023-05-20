#ifndef MATRIX_DOT_H
#define MATRIX_DOT_H

#include <vector>
#include <string>

#include "vector.h"

using namespace std;

struct Vector; // forward declaration

struct Matrix {

    vector<vector<double>> entries;

    Matrix(const vector<vector<double>>& entries);

    double& operator () (int i, int j);

    vector<double>& getRow(int i);
    vector<double> getColumn(int j);

    int numRows();
    int numColumns();
    int numEntries();

    string toString(int precision = 2);

};

#endif