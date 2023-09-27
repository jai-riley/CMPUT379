#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        if (fork() == 0)
        {
            printf("hello, I am child (pid:%d)\n", (int) getpid());
            char *myargs[4]; char *env[] = {NULL};
            myargs[0] = strdup("/bin/echo"); // program: "wc" (word count)
            myargs[1] = strdup("-w"); // argument: print the word counts
            myargs[2] = strdup("p3.c"); // argument: file to count
            myargs[3] = NULL; // marks end of array
            if (execve(myargs[0], myargs, env) < 0) // runs word count
                perror("execve");
        }
    }
    while(wait(NULL)> 0);
    printf("hello\n");
    return 0;
}