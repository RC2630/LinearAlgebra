#include "general/numberUtility.h"
#include "general/abstractFunctions.h"
#include "general/stringUtility.h"

#include "vector.h"

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