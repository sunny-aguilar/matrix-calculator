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
using std::cout;
using std::cin;
using std::endl;

int validateSize(int size);                     // validates menu choice

int main() {
    int size{};
    int **ptrMatrix = nullptr;

    cout << "Pick 2 or 3 to choose the size of the matrix:" << endl
         << "2. Matrix of size 2 x 2" << endl
         << "3. Matrix of size 3 x 3" << endl
         << "Enter: ";
    cin >> size;
    size = validateSize(size);
    cout << "\nYou have chosen a matrix of size " << size << endl;

    ptrMatrix = new int*[size];         // allocate pointer to array
    readMatrix(ptrMatrix, size);        // send to readMatrix function
    // display matrix
    cout << "\nMatrix Numbers\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << " " << ptrMatrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Determinant is: " << determinant(ptrMatrix, size);

    // delete dynamically allocated pointers
    for (int i = 0; i < size; i++) {
        delete [] ptrMatrix[i];
    }

    return 0;
}

/*********************************************************************
** Description:     Write description
**                  here
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
