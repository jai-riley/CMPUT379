#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define LINESIZE 20

int main (int argc, char *argv[]) {
    char buf[LINESIZE];
    FILE *fp;

    fp = popen("ls -l", "r");

    while (fgets(buf, LINESIZE, fp) != NULL)
        printf("%s\n", buf);
    pclose(fp);
    return 0;
}
