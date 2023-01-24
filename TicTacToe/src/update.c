#include<stdio.h>

int update(int board[3][3]){
	
	int winner = -2;													// if winner is -2 it's not game over 
	int i;
	int x,y;
	int count;
	
	i = 0;																//turn control
	while(winner == -2){												//game loop
		
		if(i % 2 == 1){													//Human turn
			do{
				printf("Coordinates:");
				scanf("%d %d",&x,&y);
				
			}while(board[x-1][y-1] != 0 || x<1 || x>3 || y<1 || y>3);
			
			board[x-1][y-1] = -1;										//'O' is placed at the given coordinates
			
			displayBoard(board);										//call displayBoard
			
			winner = checkWinner(board);								//Winner control
		}
		
		else{															//AI Turn
			
			choicePosition(board);										//AI choices best move
			
			displayBoard(board);										//Call displayBoard
			
			winner = checkWinner(board);								//Winner control
		}
		
		i++;
	}
	
	if(winner == 1){													
		printf("X WIN");
	}
	else if(winner == -1){
		printf("O WIN");
	}
	else{
		printf("TIE");
	}
}
