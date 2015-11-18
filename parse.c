#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//char* inputs[10];
//char* commands[10];
//char* parsed_commands[10];


char ** parse_input(char *input) {
	char **output[count_tokens(input,";")];
	int counter = 0;
	//Takes input and parses it
	input[strlen(input) - 1] = '\0';
	char *command;
	char *argray[20];

	command = input;
	command = strsep(&command, "\n");
	
	while (command){
		argray[counter] = strsep(&command, ";");
		counter+=1;
	}
	argray[counter] = NULL;
	//return argray; 
}

char ** parse_commands(char *commands){
	char *argray[15];
	int counter = 0;
	while (commands) {
		argray[counter] = strsep(&commands, " ");
		counter++;
	}
	char temp[1][1];
	return temp;
}


  
  
