#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "args.h"
#include "redirec.h"

int my_open(char *filename, int flag) {
	int ans = open(filename, flag);
	if(ans < 0) printf("error %d: %s\n", errno, strerror(errno));
	return ans;
}

int my_write(int file, int *buffer, int size) {
	int ans = write(file, buffer, size);
	if(ans < 0) printf("error %d: %s\n", errno, strerror(errno));
	return ans;
}

int redirect(char *term_in) {
  char **to_exec = parse_args(term_in, " ");
  while(*parse_args) {
    if(strcmp(parse_args, ">") == 0) strsep();
  }
  parse_args
}

//Remember to close the files with close(filename);
