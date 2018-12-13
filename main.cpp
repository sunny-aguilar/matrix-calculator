#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void askSize();

int main() {
    askSize();


    return 0;
}

void askSize() {
    int size;
    int *ptrMatrix = nullptr;

    cout << "Pick 1 or 2 to choose the size of the matrix:" << endl
         << "1. size 2 x 2" << endl
         << "2. size 3 x 3" << endl
         << "Enter: ";
    do {
        cout << "\nYou must choose between 1 or 2: " << endl;
        cin >> size;
        ptrMatrix = new int[size];
    } while (size != 1 && size != 2);
}