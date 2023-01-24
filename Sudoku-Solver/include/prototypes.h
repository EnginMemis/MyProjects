#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include<stdio.h>

extern int isNumberInRow(int [9][9], int, int);
extern int isNumberInColumn(int [9][9], int, int);
extern int isNumberInSquare(int [9][9], int, int, int);
extern int isValidNumber(int [9][9], int, int, int);
extern void displayBoard(int [9][9]);
extern void solvedSudokuFile(int [9][9], FILE *, int);
extern int solveSudoku(int [9][9]);

#endif
