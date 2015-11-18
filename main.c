#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 * Function Description:
 *   The basic while loop of the function. 
 *   while(True) is not used so that CTRL+C can be handled by the program.
 *   Deals with parsing input and printing the current working directory.
 */
void loop() {
  int status;			/* boolean; whether to exit loop or not */
  char input[256];		/* input from stdin */
  char cwd[256];		/* abbrev. for current working directory */
  char *home;			/* PATH of '~' */
  
  status = 1; 			

  home = getenv("HOME");
  
  while(status) {
    getcwd(cwd, sizeof(cwd));

    if(strstr(cwd,home) != NULL) { /* if the PATH of '~' is in the cwd */
      char pwd[256] = "~";	   /* replace PATH with '~' for brevity */
      strcat(pwd, cwd + strlen(home));
      printf("day-sh:%s$ ", pwd);
    } else {			   /* else print normal cwd */
      printf("day-sh:%s$ ",cwd);
    }
    
    fgets(input, 256, stdin);	/* read input and add terminating null */
    input[strlen(input) - 1] = '\0';
    
    printf("%s\n", input);
  }
}

int main() {
  loop();    
  return 0;
}
