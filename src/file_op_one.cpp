#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/file_op_one.h"


int create_file(char *path)
{
    if (access(path, F_OK) == 0) 
    {   
        std::cerr << "Error occured " << strerror(errno) << std::endl; 
        return 1;
    }
    
    int fd;
    fd = creat(path, 0644);
    if (fd == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl; 
        if (close(fd) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl; 
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl; 
        return 1;
    }

    std::cout << "-> File created successfully" << std::endl;
    return 0;
}

int read_file(char *path)
{
    if (access(path, F_OK) == -1) 
    {   
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    if (access(path, R_OK) == -1) 
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
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
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    return 0;
}

// right now it is overwriting to file.
int write_file(char *path, char *text)
{

    if(access(path, F_OK) == -1) 
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    int fd;
    // for now i kept this as write only, if needed then change this to read and write.
    fd = open(path, O_WRONLY);
    if (fd == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    if (access(path, W_OK) == -1) 
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    ssize_t byte_write;
    byte_write = write(fd, text, strlen(text));
    if (byte_write == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd) == -1)
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "-> Given text written to file successfully" << std::endl;
    return 0;
}
