#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/* char ** parse_commands(char *commands) {
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

	 /* char ** parse_input(char *input) { */
/*   char **output; */
/*   //first index is count_tokens(input, ";") */
/*   int counter = 0; */
  
/*   input = strsep(&input, "\n"); */
/*   input[strlen(input) - 1] = '\0'; */
/*   char *command; */
/*   char *commandarray[20]; */
  
/*   command = input; */
/*   command = strsep(&command, "\n"); */
	
/*   while (command){ */
/*     argray[counter] = strsep(&command, ";"); */
/*     counter+=1; */
/*   } */
/*   argray[counter] = NULL; */
/*   return commandarray; */
/* } */

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

  
  
int main() {

	char asd[] = "this is a sentence";
	printf("%d\n", count_tokens(asd," "));

	char cool[] = "     trim     test     ";
	printf("%s\n", trim(cool));
  
	/* char test[] = "ls -a -l"; */
	/* char *test1 = test; */
	/* char **test2 = parse_commands(test1); */
	/* int i; */
	/* for (i = 0; i < 14;i ++){ */
	/* 	printf("%s\n", test2[i]); */
	/* } */
	/* return 0; */

}
