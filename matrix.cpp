//
#include "matrix.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void readMatrix(int **matrixPtr, int size) {
    if (size == 2) {
        int row, col;
        cout << "Please enter 4 numbers" << endl;

        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                cin >> matrixPtr[row][col];
                while ( matrixPtr[row][col] < 0 || matrixPtr[row][col] > 9) {
                    cout << "Please enter an integer between 0 and 9\n" << endl;
                    cin >> matrixPtr[row][col];
                }
            }
        }
    }
    else if (size == 3) {
        int row, col;
        cout << "Please enter 9 numbers" << endl;
        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                cin >> matrixPtr[col][col];
            }
        }
    }

    // display array contents to test data here
    // use for loop like above to step through it

}

//// initializing a 2-d array size 2
//int minutes[2][2] = {{0,0},
//                     {1,1}};
//
//// initializing a 2-D array size 3
//int hours[3][3] = {{1,1,1},
//                   {2,2,2},
//                   {3,3,3}};
//
