#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "args.c"

int main() {
	while (&free) {
		char * term_in;
		term_in = fgets(term_in, 100, stdin);
		int f = fork();
		if (f == 0) {
			char ** to_exec = parse_args(term_in);
			execvp(to_exec[0], to_exec);
			return 0;
		}
	}
}