#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "../include/file_op_three.h"
#include "../include/colors.h"


int states_file(char *path)
{
    if (access(path, F_OK) == -1) 
    {   
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    // after understanding this sys call, update these details below with what you want to display.
    std::cout << COLOR_CYAN COLOR_BOLD << "\nFile info: \n" << COLOR_RESET << std::endl;
    
    // i have to see how output formatting works in C++, so will do below things later.
    
    // printf(COLOR_CYAN COLOR_BOLD "\nFile info: \n\n" COLOR_RESET);
    printf("%-20s %ld bytes\n", "File size:", file_details.st_size);
    printf("%-20s %d\n", "Owner UID:", file_details.st_uid);
    printf("%-20s %d\n", "Group UID:", file_details.st_gid);
    printf("%-20s %04o\n", "Permissions:", file_details.st_mode & 0777);
    printf("%-20s %s", "Last accessed:", ctime(&file_details.st_atime));
    printf("%-20s %s", "Last modified:", ctime(&file_details.st_mtime));
    printf("\n");
    return 0;
}

// this is basic version, i have to see more about this and also need to put filter or other things in mode or permission code that i receive.
int change_file_permission(char *path, mode_t per_code) 
{   
    if (access(path, F_OK) == -1) 
    {   
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    int fd;
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

    // test code
    printf("permission code: %04o\n", per_code);

    int change_permission = fchmod(fd, per_code);
    if(change_permission == -1) 
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        if (close(fd) == -1) 
        {
            std::cerr << "Error occured " << strerror(errno) << std::endl;
            return 1;
        }
        return 1;
    }

    std::cout << "-> File permission changed successfully" << std::endl;
    
    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        std::cerr << "Error occured " << strerror(errno) << std::endl;
        return 1;
    }
    mode_t file_permission = file_details.st_mode;
    printf("-> File permission code: %04o\n", file_permission & 0777);

    return 0;
}

mode_t parse_octal_mode(char *input) 
{
    char *end_ptr;
    errno = 0;

    long permission_code = strtol(input, &end_ptr, 8);

    if (*end_ptr != '\0' || errno != 0 || permission_code < 0000 || permission_code > 0777) 
    {
        std::cout << "Invalid permission code, it must be between 0000 to 0777" << strerror(errno) << std::endl;
        return (mode_t)-1;
    }

    return (mode_t)permission_code;
}
