#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "args.h"
#include "pprocs.h"

int main() {
	printf("$ ");
	while(&free) {
		char * term_in = malloc(100 * sizeof(char));
		term_in = fgets(term_in, 100, stdin);
		term_in[strlen(term_in) - 1] = NULL;

		int f = fork();
		int status;
		int child;
    pprocs(term_in);
    redirec(term_in);
		if (f == 0) {
			char ** to_exec = parse_args(term_in, " ");
      while(*to_exec) {
        printf("params: %s\n", *to_exec++);
      }
			//printf("child: %d, status %d\n", child, status);
			execvp(to_exec[0], to_exec);
      free(to_exec);
			return 0;
		}
    child = wait(&status);
    printf("$ ");
		free(term_in);
	}
	return 0;
}
