#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 500
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ftw.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "../include/dir_op_two.h"
#include "../include/colors.h"

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

// this is kind of global variable, but if needed put it somewhere if this is not safer option.
int file_count = 0;
int directory_count = 0;

int print_directory_content(const char *rel_path, const struct stat *stat_buf, int typeflag, struct FTW *ftw_buf) 
{   
    // this is temp
    (void) stat_buf;

    for (int i = 0; i < ftw_buf->level; i++) 
    {
        printf("    ");
    }        

    switch (typeflag) 
    {
        case FTW_D:
            printf(COLOR_CYAN "|__ %s\n" COLOR_RESET, rel_path);
            directory_count++;
            break;
        case FTW_F:
            printf("|_ %s\n", rel_path);
            file_count++;
            break;        
        default:
            printf("|_ %s\n", rel_path);    
    }

    return 0;
}

int read_directory_rec(char *path) 
{

    if (access(path, F_OK) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    // for now i am keeping this 10, change it if you need to.
    int max_no_directory = 20;
    if (nftw(path, print_directory_content, max_no_directory, FTW_PHYS) == -1) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    printf("\n%d Directories, %d Files\n", directory_count, file_count);
    return 0;
}