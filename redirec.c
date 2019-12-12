#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
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



int should_redirect(char *term_in) {
	char **exec = parse_args(term_in, " ");
  // The number 10 here is random, pick something more substantial alter
	char **input;
  int i = 0;
  input = calloc(strlen(exec), sizeof(char) * 10);
  int isRedirect = 0;
  *exec++;
	while(i < 10) {
		if(strcmp(*exec, ">") == 0) {
      isRedirect = 1;
      break;
    } else if(strcmp(*exec, "<") == 0) {
      isRedirect = 1;
      free(input);
      i = 0;
      while(*input) {
        input[i++] = calloc(strlen(exec), sizeof(char) * 10);
      }
      break;
    } else if(strcmp(*exec, "|") == 0) {
      //insert pipe function
    } else {
      *input++ = *exec++;
    }
	}
	free(input);
  for(int i = 0; i < 10; i++) {
    printf("%i, ", input[i]);
  }
  printf("\n");
  return isRedirect;
}

//Remember to close the files with close(filename);
