/*********************************************************************
** Author:      Sandro Aguilar
** Date:        Jan 2019
** Description: Write a short description
**              of your code
**              here.
**
*********************************************************************/
#include "matrix.hpp"
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
    cout << "Determinant is: " << determinant(ptrMatrix, size);


    return 0;
}

/*********************************************************************
** Description:     Write description
**                  here
*********************************************************************/
int validateSize(int size) {
    int updateSize;
    while(size != 2 && size != 3) {
        cout << "You must choose between sizes 2 or 3: " << endl;
        cin >> size;
    }
    updateSize = size;
    return updateSize;
}
