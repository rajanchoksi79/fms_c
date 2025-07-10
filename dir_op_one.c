#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int create_directory(char *path)
{
    if (access(path, F_OK) == 0) 
    {   
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    int new_dir = mkdir(path, 0755);
    if (new_dir == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    printf("New directory created successfully\n");
    return 0;
}

// this works only on empty directory.
int remove_directory(char *path) 
{
    if (access(path, F_OK) == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    if(remove(path) == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
    }
    return 0;
}