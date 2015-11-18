#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// #include "parse.h"

void int_handler(){
  printf("\nClosing day-sh...\n");
  exit(0);
}

/*
 * Function Description: 
 *   Fork the child and run the command, while the parent waits,
 *
 * Arguments:
 *   char [] (input that user entered)
 * 
 * Return:
 *   void
 */
void run_command(char input[]){
  pid_t pid, status;

  pid = fork();
  if(pid == 0) {		/* Child process */ 
    //Call main parse function here
  } else if(pid < 0) {		/* Error */
    perror("Fork failed.");
  } else {			/* Parent process */
    wait(&status);
  }
  
}

/*
 * Function Description:
 *   Prints the shell prompt, replacing the HOME path with '~'.
 * 
 * Arguments:
 *   char * (path of HOME)
 * 
 * Return: 
 *   void (prints cwd)
 */
void print_cwd(char *home) {
  char cwd[256];
  char *user;
  
  getcwd(cwd, sizeof(cwd));
  user = getlogin();
  
  if(strstr(cwd,home) != NULL) { /* if the PATH of '~' is in the cwd */
    char pwd[256] = "~";	   /* replace PATH with '~' for brevity */
    strcat(pwd, cwd + strlen(home));
    printf("%s|day-sh|:%s$ ", user, pwd);
  } else {			   /* else print normal cwd */
    printf("%s|day-sh|:%s$ ", user, cwd);
  }
}

/*
 * Function Description:
 *   The basic while loop of the function. 
 *   while(True) is not used so that CTRL+C can be handled by the program.
 *   Deals with parsing input and printing the current working directory.
 */
void loop() {
  int status;			/* boolean; whether to exit loop or not */
  char input[256];		/* input from stdin */
  char *home;			/* PATH of '~' */
  
  status = 1; 			

  home = getenv("HOME");
  
  while(status) {
    print_cwd(home);

    fgets(input, 256, stdin);	/* read input and add terminating null */
    input[strlen(input) - 1] = '\0';
    
    run_command(input);
  }
}

int main() {
  signal(SIGINT,int_handler);
  
  loop();
  
  return 0;
}
