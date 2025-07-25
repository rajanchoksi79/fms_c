#define _DEFAULT_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/dir_op_one.h"
#include "../include/colors.h"


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

// reading and printing content of directory
int read_directory(char *path)
{
    if (access(path, F_OK) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        printf("Error occured, %s\n", strerror(errno));
        if (closedir(dir) == -1)
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
        return 1;
    }

    struct dirent *entry;
    struct stat file_detail;
    char full_path[PATH_MAX];
    
    int file_count = 0;
    int directory_count = 0; 

    // new line before printing any detail from below.
    printf("\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_detail) == 0)
        {
            if ((file_detail.st_mode & S_IFMT) == S_IFREG)
            {
                printf("|_ %s\n", entry->d_name);
                file_count += 1;
            }
            else if ((file_detail.st_mode & S_IFMT) == S_IFDIR)
            {
                printf(COLOR_CYAN "|_ %s\n" COLOR_RESET, entry->d_name);
                directory_count += 1;
            }
            else if ((file_detail.st_mode & S_IFMT) == S_IFLNK)
            {
                printf(COLOR_GREEN "|_ %s\n" COLOR_RESET, entry->d_name);
            }
            else
            {
                printf("|_ %s\n", entry->d_name);
            }
        }
        else 
        {
            printf("Error occured, %s\n", strerror(errno));
            return 1;
        }
    }

    printf("\n");
    printf(COLOR_YELLOW COLOR_BOLD "--> File count: %d, Directory count: %d\n\n" COLOR_RESET, file_count, directory_count);

    if (closedir(dir) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }
    return 0;
}

// to get present working directory
int get_current_directory() 
{
    char buffer[PATH_MAX];
    
    if (getcwd(buffer,sizeof(buffer)) == NULL) 
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    printf(COLOR_CYAN COLOR_BOLD "\n-> %s\n\n" COLOR_RESET, buffer);
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

    if (rmdir(path) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }

    printf("Directory removed successfully\n");
    return 0;
}