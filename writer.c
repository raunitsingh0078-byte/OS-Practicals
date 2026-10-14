#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *fifo = "mypipe";
    char message[] = "Hello from Writer Process";

    // Create named pipe
    if (mkfifo(fifo, 0666) == -1 && errno != EEXIST)
    {
        perror("mkfifo");
        return 1;
    }

    printf("Writer: Starting...\n");

    // Open FIFO for writing
    int fd = open(fifo, O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Send message
    write(fd, message, strlen(message) + 1);

    printf("Writer: Message sent: %s\n", message);

    // Close FIFO
    close(fd);

    return 0;
}
