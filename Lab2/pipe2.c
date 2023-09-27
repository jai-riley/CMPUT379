#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#define MSG_SIZE 5
enum PipeSel {rd_pipe = 0, wt_pipe = 1};
char* first = "msg1"; char* second = "msg2";
int main(void) {
    int fd[2];
    char line[MSG_SIZE];
    if (pipe(fd) < 0)                 /* create a pipe */
        perror("pipe error");

    write(fd[wt_pipe], first, MSG_SIZE); /* write to the write end */
    write(fd[wt_pipe], second, MSG_SIZE); /* write to the write end */
    read(fd[rd_pipe], line, MSG_SIZE); /* read from the read end*/
    printf("%s\n", line);             /* print the first message */
    read(fd[rd_pipe], line, MSG_SIZE); /* read from the read end */
    printf("%s\n", line);             /* print the second message */
    return 0;
} /* ordinary-pipe/pipe1.c */
