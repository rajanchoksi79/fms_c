#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/file_op_two.h"

int remove_file(char *path)
{

    if (access(path, F_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    if (unlink(path) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "File removed successfully" << std::endl;
    return 0;
}

// there is error in rename that i need to solve.
int rename_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    if (rename(path_one, path_two) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "File renamed successfully" << std::endl;
    return 0;
}

int move_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    if (path_one == path_two)
    {
        std::cerr << "Error occured, file moving do not work when both directory are the same" << std::endl; 
        return 1;
    }
    else
    {
        if (rename(path_one, path_two) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        
        std::cout << "File moved successfully" << std::endl;
        return 0;
    }
}

// what if both file are created already.
int copy_file(char *path_one, char *path_two)
{
    if (access(path_one, F_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    if (access(path_two, F_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    int fd_one;
    fd_one = open(path_one, O_RDONLY);
    if (fd_one == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd_one) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    int fd_two;
    fd_two = creat(path_two, 0644);
    if (fd_two == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd_two) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    if (access(path_one, R_OK) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    ssize_t byte_read, byte_write;
    char buffer[128];
    while ((byte_read = read(fd_one, buffer, sizeof(buffer))) > 0)
    {
        byte_write = write(fd_two, buffer, byte_read);
        if (byte_write == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            if (close(fd_two) == -1)
            {
                std::cerr << "Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            // i need to know whether return can break the loop here because here i have to break the loop because of error, so i need to know that otherwise i have to use break;
            return 1;
        }
    }

    if (close(fd_one) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    if (close(fd_two) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "Content copied from file one to file two successfully" << std::endl;
    return 0;
}
