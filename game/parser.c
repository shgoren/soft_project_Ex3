/*
 * parser.c
 *
 *  Created on: 17 May 2018
 *      Author: hp envy
 */
#include <stdio.h>
#include "parser.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int * readCommand(int type ,char *token, char *line, char *delim)

/*
 * read the amount of fixed cells 0-80
 */
int readFixedAmnt(){
	int amnt = -1;
	while(amnt<0 || amnt>80){
		printf("Please enter the number of cells to fill [0-80]:\n");
		scanf("%d", &amnt);
		if(amnt<0 || amnt>80)
			printf("Error: Invalid number of cells to fill (should be between 0 and 80)\n");
	}
	return amnt;
}

/*
 * read command from user an call the appropriate game function
 */
int * readCommand(){
	char 	*line = (char*)calloc(1024,sizeof(char)),
			*token, *delim = " \t\r\n";
	int i;
	int command[4];
	int commands = {{1,3},{2,2},{3,0},{4,0},{5,0}};

	while(1){
		fgets(line,1024,stdin);
		token = *strtok(line, delim);
		// read a line loop
		while(token != NULL){
			for(i=0; i<5; ++i){
				if(*token == "set"){
					command = readCommand(1,3,token, line, delim);
					if (command == 0){
						printf("Error: invalid command\n");
						break;
					}
					return command;
				}
			}

			/* read hint command */
			if(*token == "hint"){
				command = readCommand(2,2,token, line, delim);
				if (command == 0){
					printf("Error: invalid command\n");
					break;
				}
				return command;
			}

			/* read set command */
			if(*token == "set"){
				command = readCommand(1,3,token, line, delim);
				if (command == 0){
					printf("Error: invalid command\n");
					break;
				}
				return command;
			}
			token = *strtok(line, delim);
		}

	}
}

int * readCommand(int type, int varAmnt ,char *token, char *line, char *delim){
	int i;
	long x,y,z;
	int command[4];

	command[0] = type;
	/* read x y z */
	for(i=1 ; i<varAmnt+1; ++i){
		token = strtok(line, delim);
		command[i] = (int)strtol(token, NULL, 10);
		if(errno != 0){
			return 0;
		}
	}
	return command;
}


