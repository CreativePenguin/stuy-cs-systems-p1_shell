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

int my_new_file_open(char *filename, int flag, int permissions) {
  int ans = open(filename, flag, permissions);
  if(ans < 0) ans = my_open(filename, O_WRONLY);
  return ans;
}

int my_write(int file, int *buffer, int size) {
	int ans = write(file, buffer, size);
	if(ans < 0) printf("error %d: %s\n", errno, strerror(errno));
	return ans;
}

int redirect(char *term_in) {
	char **exec = parse_args(term_in, " ");
  // The number 10 here is random, pick something more substantial alter
	char *input[10] = (char*) calloc(strlen(exec), sizeof(char * 100));
	while(*exec) {
		if(strcmp(*parse_args++, ">") == 0) break;
	}
	free(input);
}

//Remember to close the files with close(filename);
