#include "prototypes.h"

int main(){
	
	int board[9][9];
	int i,j,count;
	FILE *readFile, *writeFile;
	if( (readFile = fopen("./doc/sudoku.txt","r")) != NULL){
		writeFile = fopen("./doc/Solved Sudoku.txt","w");
		
		count = 1;
		while( !feof(readFile) ){
			for(i=0; i<9; ++i){
				for(j=0; j<9; ++j){
					fscanf(readFile,"%d",&board[i][j]);
				}
			}
			
			if(solveSudoku(board)){
				displayBoard(board);
				solvedSudokuFile(board, writeFile, count);
			}
			else{
				printf("Unsolvable sudoku!");
			}
			count++;
		}
		
		fclose(readFile);
		fclose(writeFile);
		
		printf("Solved Sudoku file created!\n");
		printf("Developed by Engin MEMIS");
	}
	else
		printf("Txt File Error!");
	return 0;
}
