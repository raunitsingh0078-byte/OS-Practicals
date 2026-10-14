#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    else if (rc == 0) {
        // Child process

        char *myargs[3];

        myargs[0] = strdup("wc");      // program to execute
        myargs[1] = strdup("p4.c");    // file whose words/lines are counted
        myargs[2] = NULL;              // end of argument array

        execvp(myargs[0], myargs);

        // This runs only if execvp fails
        perror("execvp failed");
        exit(1);
    }

    else {
        // Parent process
        int rc_wait = wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}
