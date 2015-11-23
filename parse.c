#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*
char ** parse_commands(char *commands) {
  char **argray;
  //first index would be count_tokens(commands, " ")
  int counter = 0;
  char **argray = abc;
  
  while (commands) {
    argray[counter] = strsep(&commands, " ");
    counter++;
  }
  argray[counter] = NULL;
  return argray;
}

char ** parse_input(char *input) {
  char **output;
  //first index is count_tokens(input, ";")
  int counter = 0;
  
  input = strsep(&input, "\n");
  input[strlen(input) - 1] = '\0';
  char *command;
  char *commandarray[20];
  
  command = input;
  command = strsep(&command, "\n");
	
  while (command){
    argray[counter] = strsep(&command, ";");
    counter+=1;
  }
  argray[counter] = NULL;
  return commandarray;
}
*/

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

char** generate_array(int a, int b) {
  printf("step 2");
  int i;
  printf("step 3");
  char **output = (char **)malloc(a * sizeof(char *));
  printf("p1");
  for (i = 0; i < a; i++ ) {
    output[i] = (char *)malloc(b * sizeof(char));
  }
  return output;
}
  
  
int main() {
  
  // test for count_token
  char asd[] = "this is a sentence";
  printf("%d\n", count_tokens(asd," "));
  
  // test for trim
  char abc[] = "       asdfasldkf      qwrwertwe    ";
  printf("[%s]\n", trim(abc));

  printf("end of trim\n");
  
  // test for generate_array
  printf("step 1");
  char **coolio = generate_array(4,3);
  printf("step 4");
  int i, j, count = 0;

  printf("test");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      *(coolio + i * 4 + j) = (char)count;
      count++;
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      printf("%s", *(coolio + i * 4 + j));
    }
  }
  

  /* 
  char test[] = "ls -a -l";
  char *test1 = test;
  char **test2 = parse_commands(test1);
  int i;
  for (i = 0; i < 14;i ++){
    printf("%s\n", test2[i]);
  }
  */
  return 0;
}
