/*#include "parser.h"
#include "solver.h"
*/
#include "game.h"
#include <stdio.h>


GameBoard board;
GameBoard solution;
int fixedAmnt;
int fullCells;

void startGame(){
	int x;
	x = readFixedAmnt();
	solution = generateSolution();
	board = generateBoard(solution, x);

}

/*
 * set value z to cell (x,y)
 */
int setCell(int z, int x, int y){
	if(isFixed(x,y)){
		printf("Error: cell is fixed\n");
		return 0;
	}
	if(!isLegalSet(z,x,y)){
		printf("Error: value is invalid\n");
		return 0;
	}
	board.boardMatrix[x][y][0]=z;
	printBoard();
	return 1;
}

/*
 * checks if z is legal in place (x,y)
 * checks row and col, and then find top left corner of block and scans block
 */
int isLegalSet(int z, int x, int y){
	int i=0;
	int j=0;
	int currRow=x;
	int currCol=y;
	for(;currRow<10;currRow++;){
		if(z==board.boardMatrix[currRow][y][0])
			return 0;
	}
	for(;currCol<10;currCol++;){
			if(z==board.boardMatrix[x][currCol][0])
				return 0;
		}
	currRow=x-(x%BLOCK_SIZE);
	currCol=y-(y%BLOCK_SIZE);
	for(;i<BLOCK_SIZE;i++;){
		for(;j<BLOCK_SIZE;j+;){
			if(z==board.boardMatrix[currRow+i][currCol+j][0])
			return 0;
			}
	}
	return 1;

}

/*
 * check if value in (x,y) is legal
 */
int isFixed(int x, int y){
	return board.boardMatrix[x][y][1];
}

/*
 * give hint in cell (x,y) from solution matrix
 */
void hintCell(int x,int y){
	int hint = solution.boardMatrix[x][y][0];
	printf("Hint: set cell to %d \n",hint)
}

/*
 * return if the board is solvable or not and stores new solution. hasSolution is in charge of the prints
 */
void validateBoard(GameBoard board){
	solution = hasSolution(board);
}

/*
 * a.	Restart the game by starting over with the initialization procedure
 * 		(followed by solving a new puzzle).
 * b. 	Restart the program by asking the
 *  	user again for the number of cells to fill, proceeding to the initialization
 *  	 procedure and then a new game.
 */
void restartGame(){
	startGame();
}

/*
 * free space
 * close everything
 * set fullcells to 81
 */
void exitCommand(){
	printf("Exiting�\n");
	fullCells = 81;
}

/*
 * PRIVATE METHOMDS FOLLOW
 */

/*
 * print the game board
 */
void printBoard(GameBoard board){
	int i, j, k, l, x=0, y=0;

	for(k=0; k<BLOCK_SIZE; k++){
		printf("----------------------------------\n");
		for(l=0; l<BLOCK_SIZE; l++){
		for(i=0; i<BLOCK_SIZE; i++){
				printf("|");
				for(j=0; j<BLOCK_SIZE; j++){
					printf(" ");
					if(board.boardMatrix[x][y][1]==1)
						printf(".");
					else
						printf(" ");
					if(board.boardMatrix[x][y][0]==0)
						printf(" ");
					else
						printf("%d",board.boardMatrix[x][y][0]);
				}
				printf(" ");
			}
		printf("|\n");
		y=0;
		x++;
		}
	}
	printf("----------------------------------\n");
}

void gamePlay(){

}

int isGameOver(){
	return (fullCells == 81);
}
