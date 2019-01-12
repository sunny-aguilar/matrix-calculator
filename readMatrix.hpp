/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     A function that take a pointer to a 2-D array and
**                  an int as parameters. The function prompts the user
**                  to enter the values for a size 2 or size 3 matrix.
*********************************************************************/
#ifndef READMATRIX_HPP
#define READMATRIX_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// function prototype
void readMatrix(int **matrixPtr, int size);


#endif