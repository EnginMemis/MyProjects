#include<stdio.h>

void solvedSudokuFile(int board[9][9], FILE *file, int count){
	int i,j;
	fprintf(file,"        SUDOKU #%d\n",count);
	for(i=0; i<9; ++i){
		if(i != 0 && i % 3 == 0){
			fprintf(file,"-----------------------\n");
		}
		for(j=0; j<9; ++j){
			if(j % 3 == 0){
				fprintf(file,"| ");
			}
			fprintf(file,"%d ",board[i][j]);
		}
		fprintf(file,"\n");
	}
	fprintf(file,"\n\n\n");
}
