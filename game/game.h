/*
 * game.h
 *
 *  Created on: 17 May 2018
 *      Author: hp envy
 */

#ifndef GAME_H_
#define GAME_H_

#define TABLE_SIZE 9
#define BLOCK_SIZE 3

typedef struct gameBoardStruct{
	int boardMatrix[TABLE_SIZE][TABLE_SIZE][2];
} GameBoard;


void startGame();

/*
 * set value z to cell (x,y)
 */
void setCell(int z, int x, int y);

/*
 * give hint in cell (x,y)
 */
void hintCell(int x,int y);

/*
 * return if the board is solveable or not
 */
void validateBoard(GameBoard board);

/*
 * a.	Restart the game by starting over with the initialization procedure
 * 		(followed by solving a new puzzle).
 * b. 	Restart the program by asking the
 *  	user again for the number of cells to fill, proceeding to the initialization
 *  	 procedure and then a new game.
 */
void restartGame();

/*
 * free space
 * close everything
 * set fullcells to 81
 */
void exitCommand();

/*
 * PRIVATE METHOMDS FOLLOW
 */

void printBoard(GameBoard board);

void gamePlay();

int isGameOver();



#endif /* GAME_H_ */
