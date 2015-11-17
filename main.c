#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void loop() {
  int status;
  char input[256];
  char cwd[1024];
  
  status = 1;

  while(status){
    getcwd(cwd, sizeof(cwd));
    printf("day-sh:%s$ ", cwd);
    fgets(input, 256, stdin);
    input[strlen(input) - 1] = '\0';
    printf("%s\n", input);
  }
}

int main() {
  loop();
    
  return 0;
}
