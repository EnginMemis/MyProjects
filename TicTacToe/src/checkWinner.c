#include<stdio.h>

int checkWinner(int board[3][3]){										//function winner control
	
	int i,j;
	int countX,countO;
	int count;
	
	count = 0;
	for(i = 0 ; i < 3 ; i++){											//Check for free space on the board
		for(j = 0 ; j < 3 ; j++){
			if(board[i][j] == 0){
				count++;
			}	
		}
	}
	
	if(count == 0){														//if there is no space on the board the game is over
		return 0;
	}
	
	//Horizontal Check
	
	count = 0;
	for(i = 0 ; i < 3 ; i++){
		countX = 0;
		countO = 0;
		for(j = 0 ; j < 3 ; j++){
			
			if(board[i][j] == 1){
				countX++;
			}
			else if(board[i][j] == -1){
				countO++;
			}
		}
		
		
		if(countX == 3){
			return 1;
		}
		else if(countO == 3){
			return -1;
		}
		
	}
	
	// Vertical Check
	
	for(i = 0 ; i < 3 ; i++){
		countX = 0;
		countO = 0;
		for(j = 0 ; j < 3 ; j++){
			if(board[j][i] == 1){
				countX++;
			}
			else if(board[j][i] == -1){
				countO++;
			}
		}
		
		if(countX == 3){
			return 1;
		}
		else if(countO == 3){
			return -1;
		}
	}
	
	//Diagonal Check
	
	countX = 0;
	countO = 0;
	for(j = 0 ; j < 3 ; j++){
		if(board[j][j] == 1){
			countX++;
		}
		else if(board[j][j] == -1){
			countO++;
		}
	}
		
	if(countX == 3){
		return 1;
	}
	else if(countO == 3){
		return -1;
	}
	
	
	countX = 0;
	countO = 0;
	i = 0;
	for(j = 2 ; j >= 0 ; j--){
		if(board[i][j] == 1){
			countX++;
		}
		else if(board[i][j] == -1){
			countO++;
		}
		i++;
	}
		
	if(countX == 3){
		return 1;
	}
	else if(countO == 3){
		return -1;
	}
	
	
	return -2;
	
}
