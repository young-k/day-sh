
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*
char ** parse_commands(char *commands) {
  char **argray = generate_array(count_tokens(commands, " "), 10);
  int counter = 0;
  
  while (commands) {
    argray[counter] = strsep(&commands, " ");
    counter++;
  }
  argray[counter] = NULL;
  return argray;
}

char ** parse_input(char *input) {
  char **commandarray = generate_array(count_tokens(input, ";"), 10);
  int counter = 0;

  // removes the newline character when you return
  input = strsep(&input, "\n");

  while (input){
    argray[counter] = strsep(&input, ";");
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
  printf("step 2\n");
  int i;
  printf("step 3\n");
  char **output = (char **)malloc(a * sizeof(char *));
  for (i = 0; i < a; i++ ) {
    output[i] = (char *)malloc(b * sizeof(char) + 1);
  }
  return output;
}

/* void parse_all(char* stdinput) { */
/*   commandarray = parse_input(stdinput); */
/*   int i; */
/*   for (i = 0; i < sizeof(commandarray)/sizeof(commandarray[0]); i++) { */
    
/*   }     */
/* }   */

  
int main() {
  
  // test for count_token
  char asd[] = "this is a sentence";
  printf("%d\n", count_tokens(asd," "));
  
  // test for trim
  char abc[] = "       asdfasldkf      qwrwertwe    ";
  printf("[%s]\n", trim(abc));
  printf("end of trim\n");
  
  // test for generate_array
  printf("step 1\n");
  char **coolio = generate_array(4,3); 
  
  coolio[0]={0,1,2};
  coolio[1]={0,13,25};
  coolio[2]={0,3,2};
  coolio[3]={3,4,5};
  
  printf("step 4\n"); 
  int i, j, count;
  i = j = count = 0;

  for (i = 0; i < 4; i++) {
    printf("%d \n", i);
    for (j = 0; j < 3; j++) {
      printf(" %d\n", j);
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
