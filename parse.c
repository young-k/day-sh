#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_commands(char *input){
  char *argray[15];
  int counter = 0;
  while (input) {
    argray[counter] = strsep(&input, " ");
    counter++;
  }

  
  
