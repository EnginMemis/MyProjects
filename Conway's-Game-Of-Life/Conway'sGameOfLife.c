#include<stdio.h>
#include<stdlib.h>

#define HEIGHT 30      				// If you changed the size in the txt file, make the same change here.
#define WIDTH 100


void update(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population, int generation);
int gameControl(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population);
void displayGrid(int grid[HEIGHT][WIDTH], int population, int generation);
int loadFile(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population);

int main(){
	
	int grid[HEIGHT][WIDTH] = {0};
	int previousGrid[HEIGHT][WIDTH] = {0};
	int population, generation;
	int choice;
	
	printf("\n\n	Developed by Engin Memis\n\n");
	printf("1-Load Pattern From File!\n");
	printf("2-Start The Game!\n");
	printf("3-Exit!\n");
	do{
		printf("Choice:");
		scanf("%d",&choice);
	}while(choice != 1 && choice != 2 && choice != 3);
	
	switch(choice){													//MENU
		
		case 1:
			population = loadFile(grid, previousGrid, population);						//Load Pattern From File
			printf("\n\nSuccessfully Loaded!");
			sleep(1);
			system("cls");
		case 2:
			generation = 0;											//Total number of generations
	
			displayGrid(grid, population, generation);							//Display to screen
			sleep(1);
			generation++;
			update(grid, previousGrid, population, generation);						//Game Loop
			
			break;
			
		case 3:
			return 0;
	}


	return 0;
}


void update(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population, int generation){
	
	
	while(population != 0){
		system("cls");
		population = gameControl(grid, previousGrid,population);			//The process of determining the population and the new pattern
		displayGrid(grid, population, generation);
		generation++;
		sleep(1);
	}
	
}


int gameControl(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population){					

	int i, j, k;
	int count_neighbours;
	int dx[] = {+1, 0, -1, 0,+1,+1,-1,-1};
	int dy[] = {0, +1, 0, -1,+1,-1,-1,+1};
	
	
	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			
			count_neighbours = 0;
			for(k = 0; k<8; k++){
				if(i + dx[k] < 0 || i + dx[k] >= HEIGHT || i + dy[k] < 0 || i + dy[k] >= WIDTH){		//Array Size Control
					continue;
				}
				else if(previousGrid[ i + dx[k] ][ j + dy[k] ] == 1 ){			//if there is a live neighbor, number of neighbour increasing by 1
					count_neighbours++;
				}
			}
			if(previousGrid[i][j] == 0 && count_neighbours == 3){		//if there are two or three live neighbors, the next generation will be alive
				grid[i][j] = 1;
			}
			else if(previousGrid[i][j] == 1){
				if(count_neighbours != 2 && count_neighbours != 3){	//if there are not two or three live neighbors, the next generation will be death
					grid[i][j] = 0;
				}
			}
		}
	}
	
	population = 0;
	for(i=0; i<HEIGHT; i++){																					//Determining the number of population
		for(j=0; j<WIDTH; j++){
			previousGrid[i][j] = grid[i][j];
			if(previousGrid[i][j] == 1){
				population++;
			}
		}
	}
	
	
	return population;
}

int loadFile(int grid[HEIGHT][WIDTH], int previousGrid[HEIGHT][WIDTH], int population){			//Load Pattern from File
	
	FILE *file;
	int i, j;
	char temp[WIDTH];

	population = 0;
	
	file = fopen("Pattern.txt","r");
	if( file != NULL ){
		for(i=0; i<HEIGHT; i++){
			fscanf(file,"%s",&temp);
			for(j=0; j<WIDTH; j++){
				if(temp[j] == '#'){
					grid[i][j] = 1;
					previousGrid[i][j] = 1;
					population++;
				}
			}		
		}
		
		
	}
	else{
		printf("File not Found!");
	}
	
	fclose(file);
	return population;
}




void displayGrid(int grid[HEIGHT][WIDTH], int population, int generation){
	
	int i, j;
	
	printf("\n\n	Developed by Engin Memis");
	printf("\n\n");
	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(grid[i][j] == 0){
				printf(".");
			}
			else{
				printf("#");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("Generation: %d\nPopulation: %d",generation,population);
	
}


