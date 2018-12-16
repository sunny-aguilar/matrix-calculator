/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Write a short description
**                  of your code
**                  here.
**
*********************************************************************/
#include "determinant.hpp"
#include <iostream>
using std::cout;
using std::endl;

int determinant(int **matrixPtr, int size) {

    int determinant = 0, a, b, c, d, e, f, g, h, i;

    if (size == 2) {
        // formula values from array
        a = matrixPtr[0][0];
        b = matrixPtr[0][1];
        c = matrixPtr[1][0];
        d = matrixPtr[1][1];

        // calculate determinant for size 2 matrix
        // |A| = ad - bc
        determinant = (a*d) - (b*c);
    }
    else if (size == 3) {
        // formula values from array
        a = matrixPtr[0][0];
        b = matrixPtr[0][1];
        c = matrixPtr[0][2];
        d = matrixPtr[1][0];
        e = matrixPtr[1][1];
        f = matrixPtr[1][2];
        g = matrixPtr[2][0];
        h = matrixPtr[2][1];
        i = matrixPtr[2][2];

        // calculate determinant for size 3 matrix
        // |A| = a(ei − fh) − b(di − fg) + c(dh − eg)
        determinant = a*((e*i) - (f*h)) -
                      b*((d*i) - (f*g)) +
                      c*((d*h) - (e*g));
    }

    return determinant;
}