#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//char* inputs[10];
//char* commands[10];
//char* parsed_commands[10];


char ** parse_input(char *input) {
  char temp[1][1];
  return temp;
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


  
  
