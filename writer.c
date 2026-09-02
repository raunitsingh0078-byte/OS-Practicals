#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd;
    char *message = "Hello from Writer Process";

    mkfifo("mypipe", 0666);

    fd = open("mypipe", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    return 0;
}







