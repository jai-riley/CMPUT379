#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    fork();
    fork();
    fork();
    printf("hello \n");
    //printf("hello %d\n",getpid());
    return 0;
}