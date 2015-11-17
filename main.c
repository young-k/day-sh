#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void loop() {
  int status;
  char input[256];
  char cwd[256];
  char *home;
  
  status = 1;

  home = getenv("HOME");
  
  while(status) {
    getcwd(cwd, sizeof(cwd));

    if(strstr(cwd,home) != NULL) {
      char pwd[256] = "~";
      strcat(pwd, cwd + strlen(home));
      printf("day-sh:%s$ ", pwd);
    } else {
      printf("day-sh:%s$ ",cwd);
    }
    
    fgets(input, 256, stdin);
    input[strlen(input) - 1] = '\0';
    
    printf("%s\n", input);
  }
}

int main() {
  loop();
    
  return 0;
}
