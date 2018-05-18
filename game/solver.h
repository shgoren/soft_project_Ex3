/*
 * solver.h
 *
 *  Created on: 17 May 2018
 *      Author: hp envy
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include "game.h"

/*
 * seed to be set by main for randomization
 */
extern int seed;

/*
 * check if z can be placed legally in (x,y) and print the corresponding message
 */
int checkIfValid(GameBoard board, int z,int x, int y);

GameBoard generateSolution();

/*
 * we need to make sure that fixed it is initialized to 0 unless really fixed
 */
GameBoard generateBoard(GameBoard solution, int fixedAmnt);


/*
 * function needs to supply new solution + print appropriate message.
 */
GameBoard hasSolution(GameBoard board);




/*
 * PRIVATE METHOMDS FOLLOW
 */



#endif /* SOLVER_H_ */
