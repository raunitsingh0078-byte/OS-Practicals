#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("NEW State: Creating a process...\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("READY State: Child process is ready.\n");
        printf("RUNNING State: Child process is executing.\n");
        printf("WAITING State: Simulating I/O operation...\n");

        sleep(3);

        printf("RUNNING State: Child process resumed execution.\n");
        printf("TERMINATED State: Child process exiting.\n");
    }
    else
    {
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}
