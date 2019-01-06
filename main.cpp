/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::regex;   // REMOVE REGEX

int validateSize(int size);                     // validates menu choice

int main() {
    int size = 0;                               // holds matrix size
    int **ptrMatrix = nullptr;                  // pointer to a pointer

    regex selectPattern("[2-3]{1}");

    // ask user to pick a matrix size
    cout << "Enter 2 or 3 to choose the size of the matrix:" << endl
         << "2. Matrix of size 2 x 2" << endl
         << "3. Matrix of size 3 x 3" << endl
         << "\nEnter: ";
    cin >> size;
    // call function to validate size entered by user
    size = validateSize(size);
    // confirm size with user after validation passes
    cout << "\nYou have chosen a matrix of size " << size << endl;

    // create an array of pointers that point to arrays
    ptrMatrix = new int*[size];         // allocate pointer to array
    readMatrix(ptrMatrix, size);        // send pointer to readMatrix function

    // display matrix values
    cout << "\nMatrix Numbers\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << "   " << ptrMatrix[row][col] << " ";
        }
        cout << endl;
    }
    // display the determinant value
    cout << "\nDeterminant is: " << determinant(ptrMatrix, size) << endl;

    // delete dynamically allocated pointers
    for (int arr = 0; arr < size; arr++) {
        delete [] ptrMatrix[arr];
    }
    //Free the array of pointers
    delete[] ptrMatrix;

    return 0;
}

/*********************************************************************
** Description:     Simple validation function that validates user
**                  data entry
*********************************************************************/
int validateSize(int size) {
    while (!cin || (size != 2 && size != 3)) {
        cout << "You must enter 2 or 3: ";
        cin.clear();            // remove any errors in the buffer
        cin.ignore();           // remove first character in buffer
        cin >> size;
    }

    return size;
}
