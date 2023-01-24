#include<stdio.h>

int solveSudoku(int board[9][9]){
	int i,j;
	int number;
	for(i=0; i<9; ++i){
		for(j=0; j<9; ++j){
			if( board[i][j] == 0 ){
				for(number = 1; number <= 9; number++){
					if( isValidNumber(board, number, i, j) ){
						board[i][j] = number;
						
						if(solveSudoku(board)){
							return 1;
						}
						else{
							board[i][j] = 0;
						}
					}
				}
				return 0;
			}
		}
	}
	return 1;
}
