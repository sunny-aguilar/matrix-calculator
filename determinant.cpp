/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     A function that calculates the determinant of a
**                  2x2 or 3x3 matrix calculator. Returns the
**                  calculated value.
*********************************************************************/
#include "determinant.hpp"

int determinant(int **matrixPtr, int size) {
    // variables to hold user entered values
    int determinant = 0, a, b, c, d, e, f, g, h, i;

    // calcualte values on 2 x 2 grid
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
    // calculate determinant on a 3 x 3 grid
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

    // return determinant value
    return determinant;
}