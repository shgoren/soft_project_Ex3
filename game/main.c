#include "game.h"
#include "solver.h"
#include "parser.h"


int main(){
	int true = 1;
	int *command;
	startGame();
	while(true){
		command = readCommand();
		if(command[0]==1 && !isGameOver()){ /* command is "set" */
			setCell(command[1], command[2], command[3]);
			continue;
		}
		if(command[0]==2 && !isGameOver()){ /* command is "hint" */
			hintCell(command[1],command[2]);
			continue;
		}
		if(command[0]==3 && !isGameOver()){ /*command is "validate"*/
			validateBoard();
			continue;
		}
		if(command[0]==4){/* command is "restart"*/
			restartGame();
			continue;
		}
		if(command[0]==5){ /*command is "exit" */
			exitCommand();
		}

	}

	return 0;
}
