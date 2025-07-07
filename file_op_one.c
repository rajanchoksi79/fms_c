#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


int create_file(char *path)
{
    int fd;
    fd = creat(path, 0644);
    if (fd == -1)
    {
        perror("error occured while creating file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to creating it");
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("error closing file, after creating it");
        return 1;
    }

    printf("file created successfully\n");
    return 0;
}

int read_file(char *path)
{
    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("error occured while opening file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_read;
    // i need to see if i need to increase or decrease this, the buffer size.
    char buffer[128];
    while ((byte_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        // i haven't handled error that may occure in writing here.
        write(STDOUT_FILENO, buffer, byte_read);
    }
    printf("\n");

    if (byte_read == -1)
    {
        perror("failed to read file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to read it");
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("error closing file, after reading it");
        return 1;
    }

    return 0;
}

// right now it is overwriting to file.
int write_file(char *path, char *text)
{
    int fd;
    // for now i kept this as write only, if needed then change this to read and write.
    fd = open(path, O_WRONLY);
    if (fd == -1)
    {
        perror("error occured while opening file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_write;
    byte_write = write(fd, text, strlen(text));
    if (byte_write == -1)
    {
        perror("error occured while writing file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to write it");
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("error closing file, after writing it");
        return 1;
    }

    printf("Success: text written to file successfully\n");
    return 0;
}
