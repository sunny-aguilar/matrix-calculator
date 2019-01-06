/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This program creates a matrix calculator program.
**                  It has two main functions and a 3rd function for
**                  validating user data.
**
*********************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
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
         << "3. Matrix of size 3 x 3" << endl
         << "\nEnter: ";

    // call function to validate size entered by user
    size = validateSize();
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
    cout << "\n||| Determinant is: " << determinant(ptrMatrix, size) << endl;

    // delete dynamically allocated pointers
    for (int arr = 0; arr < size; arr++) {
        // free each sub-array
        delete [] ptrMatrix[arr];
    }
    // Free the array of pointers
    delete [] ptrMatrix;
    ptrMatrix = nullptr;

    return 0;
}

/*********************************************************************
** Description:     validates user input and returns a valid value
**                  back to main.
*********************************************************************/
int validateSize() {
    char choice[100];                   // holds user input
    int validInput = 0;                 // holds validated input
    bool isDigit = false;               // checks if value is a digit
    bool tooLong = false;               // checks the # of characters
    bool notInRange = false;            // t/f if number is in range
    const int MIN_VAL = 2;              // min range of value acceptable
    const int MAX_VAL = 3;              // max range of value acceptable
    std::stringstream convert;          // convert char to number value

    do {    // ask a user to enter valid input
        // get user input
        cin.getline(choice, 100);

        // reject any input that has more than one character
        if (strlen(choice) > 1) {
            tooLong = true;
            cout << "Enter only one number\n";
            cout << "Length is " << strlen(choice) << endl;
        }
        else {
            tooLong = false;
        }

        // reject any input which is not a digit
        for (int i = 0; i < strlen(choice); i++) {
            if ( isdigit(choice[i]) ) {
                isDigit = true;
            }
            else if ( !isdigit(choice[i]) ) {
                isDigit = false;
            }
        }
        if (!isDigit) {
            cout << "you must enter a number\n";
        }

        // if input is a number and has digits within range
        if (!tooLong && isDigit) {
            convert.clear();
            convert << choice;
            convert >>  validInput;

            // reject any input which is not equal to valid menu options
            if (validInput < MIN_VAL  || validInput > MAX_VAL) {
                notInRange = true;
                cout << "you must enter 2 or 3\n";
            }
            else if (validInput >= MIN_VAL && validInput <= MAX_VAL) {
                notInRange = false;
            }
        }

        // keep looping until correct input
    } while (tooLong || !isDigit || notInRange);

    // return the valid data back to main()
    return validInput;
}
