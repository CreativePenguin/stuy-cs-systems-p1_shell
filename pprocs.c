#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pprocs.h"

int pprocs(char *term_in) {
  if(should_exit(term_in)) {
    execl("make", "clean");
    exit(0);
  }
  if(should_cd(term_in)) chdir(term_in);
  return 0;
}

int should_exit(char *term_in) {
  if(strcmp(term_in, "exit") == 0) {
    printf("Exit received, exiting\n");
    return 1;
  }
  return 0;
}

int should_cd(char *term_in) {
  if(strcmp(term_in, "cd") == 0) {
    printf("cd received, committing apoptosis now\n");
    return 1;
  }
  return 0;
}
