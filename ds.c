#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        printf("[CHILD] PID: %d | Parent PID (PPID): %d\n",
               (int)getpid(), (int)getppid());
    }
    else {
        // Parent process
        wait(NULL);
        printf("[PARENT] PID: %d | Spawned Child PID: %d\n",
               (int)getpid(), (int)pid);
    }

    return 0;
}
