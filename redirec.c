#include <stdio.h>

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
