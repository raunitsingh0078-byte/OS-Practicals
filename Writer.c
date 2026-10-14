#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char message[] = "Hello from Writer Process";

    int fd = open("mypipe", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    printf("Data sent successfully.\n");

    return 0;
}
