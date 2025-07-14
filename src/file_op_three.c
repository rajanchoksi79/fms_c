#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>


int states_file(char *path)
{
    if (access(path, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    // after understanding this sys call, update these details below with what you want to display.
    printf("File info: \n\n");
    printf("File size: %ld bytes\n", file_details.st_size);
    printf("Owner UID: %d\n", file_details.st_uid);
    printf("Group UID: %d\n", file_details.st_gid);
    printf("Permissions: %04o\n", file_details.st_mode & 0777);
    printf("Last accessed: %s", ctime(&file_details.st_atime));
    printf("Last modified: %s", ctime(&file_details.st_mtime));
    return 0;
}

// this is basic version, i have to see more about this and also need to put filter or other things in mode or permission code that i receive.
int change_file_permission(char *path, mode_t per_code) 
{   
    if (access(path, F_OK) == -1) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    int fd;
    fd = open(path, O_WRONLY);
    if (fd == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        if (close(fd) == -1) 
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
        return 1;
    }

    // test code
    printf("permission code: %04o\n", per_code);

    int change_permission = fchmod(fd, per_code);
    if(change_permission == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        if (close(fd) == -1) 
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
        return 1;
    }

    printf("File permission changed successfully\n");
    
    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }
    mode_t file_permission = file_details.st_mode;
    printf("File permission code: %04o\n", file_permission & 0777);

    return 0;
}

mode_t parse_octal_mode(char *input) 
{
    char *end_ptr;
    errno = 0;

    long permission_code = strtol(input, &end_ptr, 8);

    if (*end_ptr != '\0' || errno != 0 || permission_code < 0000 || permission_code > 0777) 
    {
        printf("Invalid permission code, it must be between 0000 to 0777, %s\n", strerror(errno));
        return (mode_t)-1;
    }

    return (mode_t)permission_code;
}

int help_user() 
{
    printf("here i will print all the help related things like kind of guide to user about how to use app and different flags\n");
}