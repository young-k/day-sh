#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int stringExist( char *string, char *sub )
{
  int count = 0;

  while( *string )
    {
      char *a = string, *b = sub;
      while( *a && *a == *b ) {a++;b++;}
      count += !*b;
      ++string;
    }

  return count;
}

/* char **generate_array(int a, int b) { */
/*   int i; */
/*   char **output = (char **)malloc(a * sizeof(char *)); */
/*   for (i = 0; i < a; i++ ) { */
/*     output[i] = (char *)malloc(b * sizeof(char) + 1); */
/*   } */
/*   return output; */
/* } */

//char *argray[50];
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

//char *commandarray[50];
void parse_input(char *input, char **commandarray) {
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

/* int main() { */
/*   char test[] = "ls -l;pwd"; */
/*   parse_input(test, commandarray); */
/*   int i; */
/*   printf("Should return ls -l: %s\n", commandarray[0]); */
/*   printf("Should return pwd: %s\n", commandarray[1]); */
  
/*   char test1[] = "ls -a -l"; */
/*   parse_command(test1, argray); */
  
/*   printf("Should return ls: %s\n", argray[0]); */
/*   printf("Should return -a: %s\n", argray[1]); */
/*   printf("Should return -l: %s\n", argray[2]); */
  

/*   return 0; */
/* } */
