#include <stdio.h>
#include "game.h"
#include "solver.h"
#include "parser.h"

GameBoard board;


int main(void){
	int i=0;
	int j=0;
	int n=0;
	for(;i<9;i++){
		for(;j<9;j++){
			board.boardMatrix[i][j][0]=n;
			n++;
		}
	}
	board.boardMatrix[4][6][1]=1;
	printBoard(board);
	setCell(5,2,2);
	setCell(2,2,2);
	return 0;
}


/*
 *
int isFixed(int x, int y){
	return board.boardMatrix[x][y][1];
}
*/

/*
 * set value z to cell (x,y)
 */


/*

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
	printBoard(board);
	return 1;
}


 * checks if z is legal in place (x,y)
 * checks row and col, and then find top left corner of block and scans block


int isLegalSet(int z, int x, int y){
	int i=0;
	int j=0;
	int currRow=x;
	int currCol=y;
	for(;currRow<10;currRow++){
		if(z==board.boardMatrix[currRow][y][0])
			return 0;
	}
	for(;currCol<10;currCol++){
			if(z==board.boardMatrix[x][currCol][0])
				return 0;
		}
	currRow=x-(x%BLOCK_SIZE);
	currCol=y-(y%BLOCK_SIZE);
	for(;i<BLOCK_SIZE;i++){
		for(;j<BLOCK_SIZE;j++){
			if(z==board.boardMatrix[currRow+i][currCol+j][0])
			return 0;
			}
	}
	return 1;

}
*/


/*

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
					y++;
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

*/



