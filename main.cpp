#include "matrix.hpp"
#include "determinant.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void validateSize(int size);

int main() {
    int size;
//    int *ptrMatrix = nullptr;

    cout << "Pick 2 or 3 to choose the size of the matrix:" << endl
         << "2. Matrix of size 2 x 2" << endl
         << "3. Matrix of size 3 x 3" << endl
         << "Enter: ";
    cin >> size;
    validateSize(size);
    cout << "\nYou have chosen a matrix of size " << size << endl;

//    int *ptrMatrix = new int[3];      // allocate pointer to array

//    readMatrix();
//        ptrMatrix = new int[size];


    return 0;
}

void validateSize(int size) {
    while(size != 2 && size != 3) {
        cout << "\nYou must choose between 2 or 3: " << endl;
        cin >> size;
    }
}
