// process-control/p1.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("hello world (pid:%d)\n", (int) getpid());
    int shared_int = 0;
    int rc = fork();

    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        _exit(1);
    }
    else if (rc == 0)
    { // child (new process)
        printf("Child (pid:%d), shared_int = %d\n", (int) getpid(), shared_int);
        ++shared_int;
    }
    else
    { // parent goes down this path (original process)
        printf("Parent of %d (pid:%d), shared_int = %d\n", rc, (int) getpid(), shared_int);
        --shared_int;
    }
    printf("Pid %d, shared_int = %d\n", (int) getpid(), shared_int);
    return 0;

}