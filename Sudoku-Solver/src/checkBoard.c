#include<stdio.h>

int isNumberInRow(int board[9][9], int number, int row){
	int i;
	for(i=0; i<9; ++i){
		if(board[row][i] == number)
			return 1;
	}
	return 0;
}

int isNumberInColumn(int board[9][9], int number, int column){
	int i;
	for(i=0; i<9; ++i){
		if(board[i][column] == number)
			return 1;
	}
	return 0;
}

int isNumberInSquare(int board[9][9], int number, int row, int column){
	int x = row - (row % 3);
	int y = column - (column % 3);
	int i,j;
	
	for(i=x; i<x+3; ++i){
		for(j=y; j<y+3; ++j){
			if(board[i][j] == number){
				return 1;
			}
		}
	}
	return 0;
}

int isValidNumber(int board[9][9], int number, int row, int column){
	if( !isNumberInRow(board, number, row) && !isNumberInColumn(board, number, column) && !isNumberInSquare(board, number, row, column) )
		return 1;
	return 0;
}
