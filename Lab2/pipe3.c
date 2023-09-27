#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#define MAXLINE 128
int main(void) {
    int n; pid_t pid;
    int fd[2];
    char line[MAXLINE];
    if (pipe(fd) < 0)           /* create a pipe before forking a child */
        perror("pipe error");
    if ((pid = fork()) < 0) {   /* fork a child */
        perror("fork error");
    } else if (pid > 0) {       /* parent continues */
        close(fd[0]);           /* close the unused end of the pipe */
        write(fd[1], "hello world!", 13);
    } else {                    /* child continues */
        close(fd[1]);           /* close the unused end of the pipe */
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);   }
    _exit(0);
} /* ordinary-pipe/pipe2.c */
