#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/file_op_two.h"


int remove_file(char *path)
{

    if (access(path, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (unlink(path) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    printf("File removed successfully\n");
    return 0;
}

int rename_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (path_one != path_two)
    {
        printf("Error occured, rename do not work when both directory are not the same with different file name\n");
        return 1;
    }
    else
    {
        if (rename(path_one, path_two) == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }

        printf("File renamed successfully\n");
        return 0;
    }
}

int move_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (access(path_two, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (path_one == path_two)
    {
        printf("Error occured, file moving do not work when both directory are the same\n");
        return 1;
    }
    else
    {
        if (rename(path_one, path_two) == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }

        printf("File moved successfully\n");
        return 0;
    }
}

// what if both file are created already.
int copy_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (access(path_two, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    int fd_one;
    fd_one = open(path_one, O_RDONLY);
    if (fd_one == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        if (close(fd_one) == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
        return 1;
    }

    int fd_two;
    fd_two = creat(path_two, 0644);
    if (fd_two == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        if (close(fd_two) == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
        return 1;
    }

    if (access(path_one, R_OK) == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }
    
    ssize_t byte_read, byte_write;
    char buffer[128];
    while ((byte_read = read(fd_one, buffer, sizeof(buffer))) > 0)
    {
        byte_write = write(fd_two, buffer, byte_read);
        if (byte_write == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            if (close(fd_two) == -1)
            {
                printf("Error occured, %s\n", strerror(errno));
                return 1;
            }
            // i need to know whether return can break the loop here because here i have to break the loop because of error, so i need to know that otherwise i have to use break;
            return 1;
        }
    }

    if (close(fd_one) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if (close(fd_two) == -1)
    {
        printf("Error ocuured, %s\n", strerror(errno));
        return 1;
    }

    printf("Content copied from file one to file two successfully\n");
    return 0;
}
