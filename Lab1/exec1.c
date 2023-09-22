#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]) {

    char *argv1[] = {"ls", "-al", NULL};
    char *envp[] = {NULL};

    if (execve("/bin/ls", argv1, envp) ==-1){
        perror("execve");
    }

    printf("End on demo");

    return 0;

}