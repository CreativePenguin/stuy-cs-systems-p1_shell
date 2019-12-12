int my_open(char *file, int flag);
int my_new_file_open(char *filename, int flag, int permissions);
int my_write(int file, int *buffer, int size);
int should_redirect(char *term_in);
