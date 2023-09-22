#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    printf("START");
    fflush(stdout);
    _exit(0);
    printf("End of program");

}