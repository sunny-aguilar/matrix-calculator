/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     A function that take a pointer to a 2-D array and
**                  an int as parameters. The function prompts the user
**                  to enter the values for a size 2 or size 3 matrix.
*********************************************************************/
#include "readMatrix.hpp"

/*********************************************************************
** Description:     validator function prototype
*********************************************************************/
void validateMatrixInput(int **matrixPtr, int size);

/*********************************************************************
** Description:     function receives two parameters: a pointer to a
**                  pointer and the size of the matrix chosen. It
**                  allocates the column of a 2D pointer and prompts
**                  user to enter integer values. Values received are
**                  validated by function validateMatrixInput().
*********************************************************************/
void readMatrix(int **matrixPtr, int size) {
    // ask user to enter integers for matrix & validate
    validateMatrixInput(matrixPtr, size);
}

/*********************************************************************
** Description:     A helper function that validates the data going
**                  into the 2D array. It takes a pointer to a pointer
**                  and a size value which are used to iterate through
**                  and store integers. No return value.
*********************************************************************/
void validateMatrixInput(int **matrixPtr, int size) {
    // ask user to enter integers for matrix
    switch(size) {
        case 2:
            cout << "Now, enter 4 integers between 0 - 9.\n";
            break;
        case 3:
            cout << "Now, enter 9 integers between 0 - 9.\n";
            break;
        default:
            cout << "unable to determine integers to enter\n";
    }
//    cout << "Now, enter 9 integers between 0 - 9.\n";

    // loop though the 2D array
    for(int row = 0; row < size; ++row) {
        for(int col = 0; col < size; ++col) {
            cout << "\nEnter a Number: ";
            cin >> matrixPtr[row][col];

            // validate input
            while(!cin || (matrixPtr[row][col] < -9 || matrixPtr[row][col] > 9)) {
                cout << "Error! Enter an integer between 0 and 9: ";
                cin.clear();                // clear error flag in cin
                cin.ignore();               // ignore user input
                cin >> matrixPtr[row][col]; // read in new input
            }
        }
    }
}