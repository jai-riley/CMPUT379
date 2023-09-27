#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char msg[] = "Tester", buf[100];
    int p[2];

    pipe(p); // Two file descriptors – for r and for w

    write(p[1], msg, sizeof(msg));
    read(p[0], buf, sizeof(msg));
    printf("%s\n", buf);

    return 0;
}
