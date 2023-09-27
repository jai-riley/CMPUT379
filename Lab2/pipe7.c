#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main (int argc, char *argv[]) {
    int ffd;
    if((ffd = open("a.txt", O_CREAT | O_RDONLY, 0644)) < 0)
        perror("open failed!");

    dup2(ffd, STDIN_FILENO);    // stdin = ffd
    close(ffd);                 // stdin is still open
    if (execl("/usr/bin/wc", "wc", "-w", (char *) 0) < 0)
        perror("execl error!");

    return 0;
}
