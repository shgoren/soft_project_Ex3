#include "parser.h"
#include "solver.h"
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
void setCell(int z, int x, int y){
	board.boardMatrix[x][y][0]=z;
}

/*
 * give hint in cell (x,y)
 */
void hintCell(int x,int y){
	board.boardMatrix[x][y][1]=1;
}

/*
 * return if the board is solveable or not
 */
void validateBoard(GameBoard board){
	if(hasSolution(board))
		printf("Validation passed: board is solvable\n");
	else
		printf("Validation failed: board is unsolvable\n");
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
	printf("Exiting…\n");
	fullCells = 81;
}

/*
 * PRIVATE METHOMDS FOLLOW
 */

/*
 * read command from user an call the appropriate game function
 */
void printBoard(GameBoard board){
	int i, j, k, l, x=0, y=0;

	for(int k=0; k<BLOCK_SIZE; ++k){
		printf("----------------------------------\n");
		for(int i=0; i<BLOCK_SIZE; ++i){
			printf("|");
			for(int j=0; j<BLOCK_SIZE; ++j){
				printf(" ");
				for(int l=0; l<BLOCK_SIZE; ++l){
					if(board.boardMatrix[x][y][1]==1)
						printf(".");
					else
						printf(" ");
					printf("%d",board.boardMatrix[x][y][0]);
					y++;
				}
			}
			y=0;
			x++;
		}
	}
}

void gamePlay(){

}

int isGameOver(){
	return (fullCells == 81);
}
