#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>



char **generate_array(int a, int b) {
  int i;
  char **output = (char **)malloc(a * sizeof(char *));
  for (i = 0; i < a; i++ ) {
    output[i] = (char *)malloc(b * sizeof(char) + 1);
  }
  return output;
}

char argray[50][50];
void parse_command(char *command, char **argray) {
  //char **argray = (char **)generate_array(count_tokens(command, " ") + 1, 10);
  int counter = 0;
  
  while (command) {
    argray[counter] = strsep(&command, " ");
    counter++;
  }
  argray[counter] = '\0';
  //return argray;
}

char commandarray[50][50];
void parse_input(char *input, char **commandarray) {
  //char **commandarray = (char **)generate_array(count_tokens(input, ";") + 1, 10);
  int counter = 0;

  // removes the newline character when you return
  input = strsep(&input, "\n");
  input = strsep(&input, "\r");
  
  while (input){
    commandarray[counter] = strsep(&input, ";");
    counter+=1;
  }
  commandarray[counter] = '\0';
  //return commandarray;
}

int count_tokens(char *s1, char *delim) {
  int counter = 0;
  while (s1) {
    strsep(&s1, delim);
    counter += 1;
  }
  return counter;
}

char* trim(char *str) {
  char *end;
  while (isspace(*str)) str++;
  if(*str == 0)
    return str;
  end = str + strlen(str) -1;
  while(end>str && isspace(*end)) end--;
  
  *(end+1) = 0;
  
  return str;
}

/*
char*** parse_all(char* stdinput) {
  char ***commandarray = (char ***)malloc((count_tokens(stdinput, ";")+1) * sizeof(char **));
  int i,j;
  for (i = 0; i < count_tokens(stdinput, ";") + 1; i ++) {
    commandarray[i] = (char **)malloc(32 * sizeof(char *));
    for (j = 0; j < 10; j ++) {
      commandarray[i][j] = (char *)malloc(32 * sizeof(char *));
    }
  } 
    
  char **commands = parse_input(stdinput);
  for (i = 0; i < sizeof(commandarray)/sizeof(commandarray[0]); i++) {
    (char **)commandarray[i] = (char **)parse_command(commandarray[i]);
  }
  return commandarray;
}
*/ 
  
/* int main() {
 *   
 *   // test for count_token
 *   char asd[] = "this is a sentence";
 *   printf("%d\n", count_tokens(asd," "));
 *   
 *   // test for trim
 *   char abc[] = "       asdfasldkf      qwrwertwe    ";
 *   printf("[%s]\n", trim(abc));
 *   printf("end of trim\n");
 *   
 *   // test for generate_array
 * 
 *   /\* 
 *   char test[] = "ls -a -l";
 *   char *test1 = test;
 *   char **test2 = parse_commands(test1);
 *   int i;
 *   for (i = 0; i < 14;i ++){
 *     printf("%s\n", test2[i]);
 *   }
 *   *\/
 *   return 0;
 * } */

int main() {
  char test[] = "ls -l;pwd";
  parse_input(test, commandarray);
  int i;
  printf("Should return ls -l: %s\n", commandarry[0], commandarray);
  printf("Should return pwd: %s\n", commandarray[1], commandarray);
  
  char test1[] = "ls -a -l";
  parse_command(test1, argray);
  
  printf("Should return ls: %s\n", parsed_command[0], argray);
  printf("Should return -a: %s\n", parsed_command[1], argray);
  printf("Should return -l: %s\n", parsed_command[2], argray);
  

  return 0;
}
