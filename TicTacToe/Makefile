derlecalistir: birlestir calistir

birlestir: main checkWinner update minimax choicePosition displayBoard
	gcc ./lib/checkWinner.o ./lib/TicTacToe-AI.o ./lib/update.o ./lib/minimax.o ./lib/choicePosition.o ./lib/displayBoard.o -o ./bin/TicTacToe-AI

main:
	gcc -I "./include" -c ./src/TicTacToe-AI.c -o ./lib/TicTacToe-AI.o 

checkWinner:
	gcc -c ./src/checkWinner.c -o ./lib/checkWinner.o
	
update:
	gcc -c ./src/update.c -o ./lib/update.o

minimax:
	gcc -c ./src/minimax.c -o ./lib/minimax.o

choicePosition:
	gcc -c ./src/choicePosition.c -o ./lib/choicePosition.o

displayBoard:
	gcc -c ./src/displayBoard.c -o ./lib/displayBoard.o
	
calistir:
	./bin/TicTacToe-AI.exe