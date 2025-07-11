#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
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
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        
        // remove \n from below when you use that switch case below line below
        printf("%s\n", entry->d_name);

        // switch (entry->d_type)
        // {
        // case DT_REG:
        //     printf(" [File]\n");
        //     break;
        // case DT_DIR:
        //     printf(" [Directory]\n");
        //     break;
        // case DT_LINK:
        //     printf(" [Link]\n");
        //     break;
        // default:
        //     printf(" [Other]");
        //     break;
        // }
    }

    if (closedir(dir) == -1)
    {
        printf("Error occured, %s\n", strerror(errno));
        return 1;
    }
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