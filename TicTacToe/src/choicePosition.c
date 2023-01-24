#include<stdio.h>
#include<limits.h>


void choicePosition(int board[3][3]){								//function choosing best move using minimax algorithm
	
	int i,j;
	int score,bestScore;
	int x,y;
	bestScore = INT_MIN;
	for(i = 0 ; i < 3 ; i++){
		for(j = 0 ; j < 3 ; j++){
			if(board[i][j] == 0){
				board[i][j] = 1;
				score = minimax(board,0);							// call minimax algorithm
				board[i][j] = 0;
				if(score > bestScore){
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	board[x][y] = 1;
}
