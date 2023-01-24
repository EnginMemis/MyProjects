#include<stdio.h>
#include<limits.h>

int minimax(int board[3][3], int isMaximizing){				//function choosing the best move for AI using minimax algorithm
	
	int winner = 0;
	int score;
	int bestScore;
	int i,j;
	
	
	winner = checkWinner(board);							//winner control
	if(winner != -2){
		return winner;
	}
	
	
	if(isMaximizing == 1){									// if it's AI's turn
		
		bestScore = INT_MIN;
		
		for(i = 0 ; i < 3 ; i++){
			for(j = 0 ; j < 3 ; j++){
				if(board[i][j] == 0){
					board[i][j] = 1;
					score = minimax(board,0);
					board[i][j] = 0;
					if(score > bestScore){
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}
	
	else{												// if it's human's turn
		bestScore = INT_MAX;
		
		for(i = 0 ; i < 3 ; i++){
			for(j = 0 ; j < 3 ; j++){
				if(board[i][j] == 0){
					board[i][j] = -1;
					score = minimax(board,1);			// recursively call minimax function
					board[i][j] = 0;
					if(score < bestScore){
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}
	
	
}
