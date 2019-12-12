#include "args.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args(char * line, char *pat)
{
	char ** args = malloc(10 * sizeof(char *));
	char * curr = line;
	int i = 0;
	while (curr) {
		args[i] = strsep(&curr, pat);
		i++;
	}
  args[i] = NULL;
	return args;
}
