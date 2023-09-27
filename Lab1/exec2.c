#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int pid;
    char *argvv[]={"echo", "-al", NULL};
    char *env[]={NULL};

    if ((pid = fork()) ==-1)
    {
        perror("fork error");
    }
    else if (pid == 0)
    {
        if (execve("/bin/echo", argvv, env) == -1){
            perror("execve");
        }
    }
    /*else
    {
       wait(NULL);
    }*/

    return 0;
}