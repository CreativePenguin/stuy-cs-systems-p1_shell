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

		printf("We just failed outside the loop\n");

		if(pprocs(term_in)) {
			printf("The inside of the loop is reached\n");
			int f = fork();
			int status;
			int child;
			if (f == 0) {
				char ** to_exec = parse_args(term_in);
				child = wait(&status);
				printf("child: %d, status %d\n", child, status);
				execvp(to_exec[0], to_exec);
				return 0;
			}
			free(term_in);
		}
	}
	return 0;
}
