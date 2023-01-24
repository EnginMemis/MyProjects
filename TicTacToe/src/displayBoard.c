#include<stdio.h>

void displayBoard(int board[3][3]){									// function that display the board
	
	int i,j;
	
	system("cls");
	printf("\n X -> AI   O -> You\n");
	printf("\n       1   2   3\n\n");
	for(i = 0 ; i < 3 ; i++){
		printf(" %d   |",i+1);
		for(j = 0 ; j < 3 ; j++){
			if(board[i][j] == 1){
				printf(" %c |",'X');
			}
			else if(board[i][j] == -1){
				printf(" %c |",'O');
			}
			else{
				printf("  %c |",0);
			}
		}
		printf("\n");
	}	
	printf("\n\n");
}
