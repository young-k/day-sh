#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* inputs[];
char* commands[];
char* parsed_commands[];


void parse_input(char *input) {
}

void parse_commands(char *commands){
  char *argray[15];
  int counter = 0;
  while (commands) {
    argray[counter] = strsep(&commands, " ");
    counter++;
  }
}


  
  
