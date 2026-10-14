#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    printf("\nSIGINT Received\n");
}

int main()
{
    signal(SIGINT, handle_signal);

    while (1)
    {
        printf("Exam Server Running...\n");
        sleep(2);
    }

    return 0;
}
