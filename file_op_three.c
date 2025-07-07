#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


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
    printf("Permissions: %o\n", file_details.st_mode & 0777);
    printf("Last modified: %ld\n", file_details.st_mtime);
    return 0;
}

int help_user() 
{
    printf("here i will print all the help related things like kind of guide to user about how to use app and different flags");
}