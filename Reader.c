#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buffer[100];

    printf("Waiting for reader...\n");

    int fd = open("mypipe", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received:Hello from Writer process %s\n", buffer);

    close(fd);

    return 0;
}
