#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    char buffer[100];

    // Create pipe
    pipe(pipefd);

    // Create child process
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        close(pipefd[0]);  // Close read end

        char message[] = "Hello Child";

        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]); // Close write end
        wait(NULL);
    }
    else if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close write end

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(pipefd[0]); // Close read end
    }
    else {
        printf("Fork failed\n");
    }

    return 0;
}
