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

for(int i = 0; i < size; ++i)
    // allocate arrays based on size value
    matrixPtr[i] = new int[size];

    // ask user to enter integers for matrix
    cout << "Now, enter 4 integers sizes 0 - 9.\n";
    for(int row = 0; row < size; ++row) {
        for(int col = 0; col < size; ++col) {
            cout << "\nEnter a Number: ";
            cin >> matrixPtr[row][col];

            // validate input
            while(!cin || (matrixPtr[row][col] < -9 || matrixPtr[row][col] > 9)) {
                cout << "Error! Enter an integer between 0 and 9: ";
                cin.clear();
                cin.ignore();
                cin >> matrixPtr[row][col];
            }
        }
    }
}