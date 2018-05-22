#ifndef SOLVER_H_
#define SOLVER_H_

#include "game.h"
#include <time.h>
#include <stdlib.h>

/*
 * seed to be set by main for randomization
 */
void setSeed();


/*
 * generate a solved board
 */
GameBoard* generateSolution(GameBoard *board);

/*
 * given a solved board and an amount of fixed cells, generates a gameplay board
 */
GameBoard* generateBoard(GameBoard *solution, GameBoard *board, int fixedAmnt);


/*
 * function needs to supply new solution + print appropriate message.
 */
GameBoard* hasSolution(GameBoard *board);

#endif /* SOLVER_H_ */
