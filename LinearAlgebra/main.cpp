#include "matrix.h"

#include <iostream>

int main() {
    Matrix A({{3, 2.4, 3.8}, {7, -6, -2.3}, {0, -0.1, 1.2}});
    cout << A.toString();
}