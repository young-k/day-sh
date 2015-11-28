#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <fcntl.h>

#include "parse.h"

void int_handler(){
  exit(0);
}

/*
 * Function Description:
 *    Deal with redirection, and execute in the child.
 * 
 * Arguments:
 *    char * [] (input split on the ' ' character)
 *
 * Return:
 *    void
 *
 */

void redirect(char *argray[]){
  int in;
  int out;
  char *execute[] = {argray[0], argray[1], NULL};

  int length = sizeof(argray)/sizeof(argray[0]);

  if(strcmp(argray[2], ">") == 0){
    out = creat(argray[3], 0644);
    dup2(out, STDOUT_FILENO);
  } else { 			/* if it is not >, we can assume it is < */
    in = open(argray[3], O_RDONLY, 0);
    dup2(in, STDIN_FILENO);
  }

  if(length > 4){		/* if there is a second redirection */
    if(strcmp(argray[4], ">") == 0){
      out = creat(argray[5], 0644);
      dup2(out, STDOUT_FILENO);
    } else {			/* same assumption */
      in = open(argray[5], O_RDONLY, 0);
      dup2(in, STDIN_FILENO);
    }
  }
  
  execvp(execute[0], execute);
  perror("day-sh");
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
  size_t i;
  int num_commands = stringExist(input, ";") + 1;
  /* commandarray is an array with each element is a complete command */
  char *commandarray[num_commands];
  /* argray is an array with each element an argument of the command */
  char *argray[50];
  
  parse_input(input,commandarray);
  
  
  for( i = 0; i < sizeof(commandarray)/sizeof(commandarray[0]); i++ ){
    parse_command(commandarray[i], argray);
    
    if (strcmp(argray[0], "cd") == 0) { /* Dealing with cd */
      if(chdir(argray[1]) != 0) perror("day-sh");
    }
    
    pid = fork();
    
    if(pid == 0) {		/* Child Process */
      /* 
       * If both < and > are in the string we are looking at, then simply execute the command.
       * Else, call the redirection function. 
       */
      /* if(strchr(argray[1], '>') == NULL && strchr(argray[1], '<') == NULL){ 
       * 	printf("argray: %s\n", commandarray[i]);
       * 	printf("Hello\n"); */
	execvp(argray[0], argray);
	// }
	//else redirect(argray);
    } else if (pid < 0) {	/* Error */
      perror("day-sh");
    }
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
