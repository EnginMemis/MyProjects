#include<stdio.h>

void displayBoard(int board[9][9]){
	int i,j;
	for(i=0; i<9; ++i){
		if(i != 0 && i % 3 == 0){
			printf("-----------------------\n");
		}
		for(j=0; j<9; ++j){
			if(j % 3 == 0){
				printf("| ");
			}
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}
