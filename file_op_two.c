#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


int delete_file(char *path)
{
    if (unlink(path) == -1)
    {
        perror("Error occured while removing file");
        return 1;
    }

    printf("Success: file removed\n");
    return 0;
}

int rename_file(char *path_one, char *path_two)
{
    if (path_one != path_two)
    {
        perror("Error, rename do not work when both directory are not the same with different file name");
        return 1;
    }
    else
    {
        if (rename(path_one, path_two) == -1)
        {
            perror("Error occured while renaming file");
            return 1;
        }

        printf("File renamed successfully");
        return 0;
    }
}

int move_file(char *path_one, char *path_two)
{
    if (path_one == path_two)
    {
        perror("Error, move do not work when both directory are the same");
        return 1;
    }
    else
    {
        if (rename(path_one, path_two) == -1)
        {
            perror("Error occured while moving file");
            return 1;
        }

        printf("File moved successfully");
        return 0;
    }
}

int copy_file(char *path_one, char *path_two)
{
    int fd_one;
    fd_one = open(path_one, O_RDONLY);
    if (fd_one == -1)
    {
        perror("error occured while opening file one");
        if (close(fd_one) == -1)
        {
            perror("error closing file one, after failed to open it");
            return 1;
        }
        return 1;
    }

    int fd_two;
    fd_two = creat(path_two, 0644);
    if (fd_two == -1)
    {
        perror("error occured while opening file two");
        if (close(fd_two) == -1)
        {
            perror("error closing file two, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_read, byte_write;
    char buffer[128];
    while ((byte_read = read(fd_one, buffer, sizeof(buffer))) > 0)
    {
        byte_write = write(fd_two, buffer, byte_read);
        if (byte_write == -1)
        {
            perror("error occured while writing file two");
            if (close(fd_two) == -1)
            {
                perror("error closing file, after failed to write it");
                return 1;
            }
            // i need to know whether return can break the loop here because here i have to break the loop because of error, so i need to know that otherwise i have to use break;
            return 1;
        }
    }

    if (close(fd_one) == -1)
    {
        perror("error closing file, after reading from it");
        return 1;
    }

    if (close(fd_two) == -1)
    {
        perror("error closing file, after writing in it");
        return 1;
    }

    printf("Success: content copied from file one to file two\n");
    return 0;
}
