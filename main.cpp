/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This program creates a matrix calculator program.
**                  It has two main functions and two input functions
**                  for validating user data.
**
*********************************************************************/
#include "readMatrix.hpp"                       // header file
#include "determinant.hpp"                      // header file
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

int validateSize();                             // validator prototype

int main() {
    int size = 0;                               // holds matrix size
    int **ptrMatrix = nullptr;                  // pointer to a pointer

    // ask user to pick a matrix size
    cout << "Enter 2 or 3 to choose the size of the matrix:" << endl
         << "2. Matrix of size 2 x 2" << endl
         << "3. Matrix of size 3 x 3" << endl;

    // call function to get and validate size entered by user
    size = validateSize();
    // confirm size with user after validation passes
    cout << "\nYou have chosen a matrix of size " << size << endl;

    // create an array of pointers that point to arrays
    ptrMatrix = new int*[size];         // allocate pointer to array
    for(int i = 0; i < size; ++i) {
        // allocate arrays based on size value
        ptrMatrix[i] = new int[size];
    }

    // send pointer and size to readMatrix function
    readMatrix(ptrMatrix, size);

    // display matrix values graph
    cout << "\nMatrix Numbers\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << "   " << ptrMatrix[row][col] << " ";
        }
        cout << endl;
    }

    // display the determinant value
    cout << "\n|| Determinant is: " << determinant(ptrMatrix, size) << endl;

    // delete dynamically allocated pointers
    for (int arr = 0; arr < size; arr++) {
        // free each sub-array
        delete [] ptrMatrix[arr];
    }
    // Free the array of pointers
    delete [] ptrMatrix;

    // set pointer to null
    ptrMatrix = nullptr;

    return 0;
}

/*********************************************************************
** Description:     validates user input and returns a valid value
**                  back to main.
*********************************************************************/
int validateSize() {
    int validInput = 0;                 // holds validated input

    std::string userInput;
    cout << "\nEnter a Number: ";
    cin >> userInput;

    // validate input
    while(!cin || (userInput != "2" && userInput != "3") || (userInput.length() > 1) ) {
        cout << "Error! Enter an integer between 2 and 3: ";
        cin.clear();                // clear error flag in cin
        cin.ignore();               // ignore user input
        cin >> userInput;           // get new user input
    }

    // convert string to int
    validInput = stoi(userInput);

    // return the valid data back to main()
    return validInput;
}