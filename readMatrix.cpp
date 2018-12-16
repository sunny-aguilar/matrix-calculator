/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "readMatrix.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void readMatrix(int **matrixPtr, int size) {
    if (size == 2) {                                // initialize a size 2 matrix
        // dynamically add an array to the array
        for(int i = 0; i < size; ++i)
            matrixPtr[i] = new int[size];

        cout << "Now, enter 4 integers sizes 0 - 9.\n";
        for(int row = 0; row < size; ++row) {
            for(int col = 0; col < size; ++col) {
                cout << "Enter a Number: ";
                cin >> matrixPtr[row][col];
                while(!cin || (matrixPtr[row][col] < -9 || matrixPtr[row][col] > 9)) {
                    cout << "Error! Enter an integer between 0 and 9: ";
                    cin.clear();
                    cin.ignore();
                    cin >> matrixPtr[row][col];
                }
            }
        }
    }
    else if (size == 3) {                           // initialize a size 3 matrix
        // dynamically add an array to the array
        for(int i = 0; i < size; ++i)
            matrixPtr[i] = new int[size];

        cout << "Now, enter 9 integers sizes 0 - 9.\n";
        for(int row = 0; row < size; ++row) {
            for(int col = 0; col < size; ++col) {
                cout << "Enter a Number: ";
                cin >> matrixPtr[row][col];
                while(!cin || (matrixPtr[row][col] < -9 || matrixPtr[row][col] > 9)) {
                    cout << "Error! Enter an integer between 0 and 9: ";
                    cin.clear();
                    cin.ignore();
                    cin >> matrixPtr[row][col];
                }
            }
        }
    }
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