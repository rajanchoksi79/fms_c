#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int states_file(char *path)
{
    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        perror("Error occured while capturing file states");
        return 1;
    }

    // after understanding this sys call, update these details below with what you want to display.
    printf("File info: \n\n");
    printf("File size: %ld bytes\n", file_details.st_size);
    printf("Owner UID: %d\n", file_details.st_uid);
    printf("Group UID: %d\n", file_details.st_gid);
    printf("Permissions: %o\n", file_details.st_mode & 0777);
    printf("Last accessed: %s", ctime(&file_details.st_atime));
    printf("Last modified: %s", ctime(&file_details.st_mtime));
    return 0;
}

// this is basic version, i have to see more about this and also need to put filter or other things in mode or permission code that i receive.
int change_file_permission(char *path, mode_t per_code) 
{
    int fd;
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

    // test code
    printf("permission code: %o\n", per_code);

    if (per_code < 0000 && per_code > 0777) 
    {
        perror("Invalid permission code, it must be between 0000 to 0777");
        return 1;
    }

    int change_permission = fchmod(fd, per_code);
    if(change_permission == -1) 
    {
        perror("error occured while changing permission of file");
        if (close(fd) == -1) 
        {
            perror("error closing file, after failed to change permission it");
            return 1;
        }
        return 1;
    }

    printf("File permission changed successfully\n");
    
    struct stat file_details;
    if (stat(path, &file_details) == -1)
    {
        perror("Error occured while capturing file permission code details");
        return 1;
    }
    mode_t file_permission = file_details.st_mode;
    printf("File permission code: %o\n", file_permission & 0777);

    return 0;
}

int help_user() 
{
    printf("here i will print all the help related things like kind of guide to user about how to use app and different flags");
}