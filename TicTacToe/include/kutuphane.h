#ifndef KUTUPHANE_H_
#define KUTUPHANE_H_

#include<stdio.h>

extern int update(int [3][3]);
extern int checkWinner(int [3][3]);
extern void choicePosition(int [3][3]);
extern void displayBoard(int [3][3]);
extern int minimax(int [3][3], int);

#endif
