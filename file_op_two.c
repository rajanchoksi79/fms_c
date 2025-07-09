#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


int delete_file(char *path)
{

    if (access(path, F_OK) == -1) 
    {   
        perror("Error occured, file do not exists on given path");
        return 1;
    }

    if (unlink(path) == -1)
    {
        perror("Error occured while removing file");
        return 1;
    }

    printf("File removed successfully\n");
    return 0;
}

int rename_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1) 
    {   
        perror("Error occured, file do not exists on given source path");
        return 1;
    }

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
    if (access(path_one, F_OK) == -1) 
    {   
        perror("Error occured, file do not exists on given source path");
        return 1;
    }

    if (access(path_two, F_OK) == -1) 
    {   
        perror("Error occured, given destination path do not exists");
        return 1;
    }

    if (path_one == path_two)
    {
        perror("Error, file moving do not work when both directory are the same");
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

// what if both file are created already.
int copy_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1) 
    {   
        perror("Error occured, file do not exists on given source path");
        return 1;
    }

    if (access(path_two, F_OK) == -1) 
    {   
        perror("Error occured, given destination path do not exists");
        return 1;
    }

    int fd_one;
    fd_one = open(path_one, O_RDONLY);
    if (fd_one == -1)
    {
        perror("Error occured while opening file one");
        if (close(fd_one) == -1)
        {
            perror("Error closing file one, after failed to open it");
            return 1;
        }
        return 1;
    }

    int fd_two;
    fd_two = creat(path_two, 0644);
    if (fd_two == -1)
    {
        perror("Error occured while opening file two");
        if (close(fd_two) == -1)
        {
            perror("Error closing file two, after failed to open it");
            return 1;
        }
        return 1;
    }

    if (access(path_one, R_OK) == -1) 
    {
        perror("Error occured, file on source path is not readable");
        return 1;
    }
    
    ssize_t byte_read, byte_write;
    char buffer[128];
    while ((byte_read = read(fd_one, buffer, sizeof(buffer))) > 0)
    {
        byte_write = write(fd_two, buffer, byte_read);
        if (byte_write == -1)
        {
            perror("Error occured while writing file two");
            if (close(fd_two) == -1)
            {
                perror("Error closing file, after failed to write it");
                return 1;
            }
            // i need to know whether return can break the loop here because here i have to break the loop because of error, so i need to know that otherwise i have to use break;
            return 1;
        }
    }

    if (close(fd_one) == -1)
    {
        perror("Error closing file, after reading from it");
        return 1;
    }

    if (close(fd_two) == -1)
    {
        perror("Error closing file, after writing in it");
        return 1;
    }

    printf("Content copied from file one to file two successfully\n");
    return 0;
}
