#include <signal.h>
#include "sighandler.h"

void sighandler(int signo) {
  if(signo == SIGINT) printf("Terminating program\n");
}
