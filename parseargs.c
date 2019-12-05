#include "parseargs.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args(char * line)
{
	char ** args = malloc(10 * sizeof(char *));
	char * curr = line;
	int i = 0;
	while (curr) {
		args[i] = strsep(&curr, " ");
		i++;
	}
	return args;
}
