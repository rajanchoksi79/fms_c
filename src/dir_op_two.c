#define _DEFAULT_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "../include/dir_op_two.h"

int move_directory(char *rel_path) 
{
    // so there is not need to add filter here, i am receiving relative or absolute path not absoute always but i can use getcwd() to get path and validate it through access() but this chdir() handles error so for now not added, if need then add one.
    if (chdir(rel_path) == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

int read_directory_rec() 
{
    return 0;
}