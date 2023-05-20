#include "matrix.h"

#include <iostream>

int main() {

    Matrix A({{3, 2.4, 3.8}, {7, -6, -2.3}, {0, -0.1, 1.2}});
    cout << "\nA = " << A.toString() << "\nA(2, 3) = " << A(2, 3) << "\n";

    Vector b({3, -9, 4.52});
    cout << "\nb = " << b.toString() << "\n||b|| = " << b.length() << "\n";

}