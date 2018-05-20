


int main(){
	int true = 1;
	int command[4];
	startGame();
	while(true){
		command = readCommand();
		if(command[0]==0 && !isGameOver()){ /* command is "set" */
			setCell(command[1], command[2], command[3]);
			continue;
		}
		if(command[0]==1 && !isGameOver()){ /* command is "hint" */
			hintCell(command[1],command[2])
			continue;
		}
		if(command[0]==2 && !isGameOver()){ /*command is "validate"*/
			validateBoard();
			continue;
		}
		if(command[0]==3){/* command is "restart"*/
			restartGame();
			continue;
		}
		if(command[0]==4){ /*command is "exit" */
			exitCommand();
		}

	}

}
