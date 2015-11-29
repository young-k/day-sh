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
  char *execute[8];

  int i;
  int length = 0;

  while(argray[length]){
    if(strcmp(argray[length], ">") == 0 || strcmp(argray[length], "<") == 0){
      i = length;
      break;
    }
    length++;
  }

  length = 0;

  while(argray[length] != NULL) length++;

  int k;
  
  for(k = 0; k < i; k++){
    execute[k] = argray[k];
  }

  execute[i] = NULL;

  /* 
   * length: length of the argument array
   * i: index of where the first < or > is
   * k: temp variable to copy what needs to be executed into execute[]
   */

  if(strcmp(argray[i], ">") == 0){
    out = creat(argray[i+1], 0644);
    dup2(out, STDOUT_FILENO);
  } else { 			/* if it is not >, we can assume it is < */
    in = open(argray[i+1], O_RDONLY, 0);
    dup2(in, STDIN_FILENO);
  }

  if(length > i+2){		/* if there is a second redirection */
    if(strcmp(argray[i+2], ">") == 0){
      out = creat(argray[i+3], 0644);
      dup2(out, STDOUT_FILENO);
    } else {			/* same assumption */
      in = open(argray[i+3], O_RDONLY, 0);
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
    char fullcommand[256];
    strcpy(fullcommand, commandarray[i]);
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
      if(strchr(fullcommand, '>') != NULL || strchr(fullcommand, '<') != NULL) redirect(argray); //DERRICK ADD YOUR ELSE IF ON THE FOLLOWING LINE
      else execvp(argray[0], argray);

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
