#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "args.h"

int main() {
  // @max, please add a comment about what line 9 does, I don't get it
	while(&free) {
		char * term_in = malloc(100 * sizeof(char));
    printf("$ ");
		term_in = fgets(term_in, 100, stdin);
		int f = fork();
    int status;
    int child;
		if (f == 0) {
			char ** to_exec = parse_args(term_in);
			execvp(to_exec[0], to_exec);
      child = wait(&status);
      printf("child: %d, status %d", child, status);
			return 0;
		}
    free(term_in);
	}
}
