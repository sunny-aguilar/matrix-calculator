//
#include "determinant.hpp"
#include <iostream>
using std::cout;
using std::endl;

int determinant(int **matrixPtr, int size) {
    cout << "You entered the numbers ";
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            cout << matrixPtr[i][j] << " ";

    return 0;
}