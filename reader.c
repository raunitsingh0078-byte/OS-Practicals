#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char *fifo = "mypipe";
    char buffer[100];

    printf("Reader: Opening FIFO...\n");

    // Open FIFO for reading
    int fd = open(fifo, O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Reader: Waiting for message...\n");

    // Read message from FIFO
    read(fd, buffer, sizeof(buffer));

    printf("Reader received: %s\n", buffer);

    // Close FIFO
    close(fd);

    return 0;
}
