#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void signal_callback_handler(int signum) {
    printf("Caught signal!\n");
}
int main() {
    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = signal_callback_handler;
    sigaction(SIGINT, &sa, NULL);
    // sigaction(SIGTSTP, &sa, NULL);
    while (1) {}
}
