#ifndef MATRIX_DOT_H
#define MATRIX_DOT_H

#include <vector>
#include <string>

#include "general/randomUtility.h"

#include "vector.h"

using namespace std;

struct Vector; // forward declaration

struct Matrix {

    static RandUtil& randUtil;
    static Matrix generateRandomMatrix(int m, int n, int lower, int upper);

    vector<vector<double>> entries;

    Matrix(const vector<vector<double>>& entries);

    double& operator () (int i, int j);

    vector<double>& getRow(int i);
    vector<double> getColumn(int j);

    int numRows();
    int numColumns();
    int numEntries();

    string toString(int precision = 2);

    Matrix operator + (Matrix other);
    Matrix operator - (Matrix other);
    Matrix operator * (Matrix other);

    Matrix operator += (Matrix other);
    Matrix operator -= (Matrix other);
    Matrix operator *= (Matrix other);
    Matrix operator *= (double scalar);

};

Matrix operator * (double scalar, Matrix matrix);

#endif