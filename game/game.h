/*
 * game.h
 *
 *  Created on: 17 May 2018
 *      Author: hp envy
 */

#ifndef GAME_H_
#define GAME_H_

extern int TABLE_SIZE = 9;
extern int BLOCK_SIZE = 3;

typedef struct gameBoardStruct{
	int[TABLE_SIZE][TABLE_SIZE][2];
} GameBoard;


void startGame();

/*
 * set value z to cell (x,y)
 */
int setCell(int z, int x, int y);

/*
 * give hint in cell (x,y)
 */
int hintCell(int x,int y);

/*
 * return if the board is solveable or not
 */
int validateBoard(GameBoard board);

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
void exit();

/*
 * PRIVATE METHOMDS FOLLOW
 */

/*
 * read command from user an call the appropriate game function
 */
void printBoard(GameBoard board);

void gamePlay();

void isGameOver();



#endif /* GAME_H_ */
