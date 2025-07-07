#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *flag = argv[1];
    char *path_one = argv[2];
    char *text, *path_two;

    if (strcmp(flag, "--write") == 0)
    {
        if (argv[3] == NULL)
        {
            perror("please provide text to write in given file");
            return 1;
        }
        text = argv[3];
    }

    if (strcmp(flag, "--copy") == 0 || strcmp(flag, "--move") == 0 || strcmp(flag, "--rename") == 0)
    {
        if (argv[3] == NULL)
        {
            perror("please provide new path where you want to copy file one");
            return 1;
        }
        path_two = argv[3];
    }

    if (strcmp(flag, "--create") == 0)
    {
        create_file(path_one);
    }
    else if (strcmp(flag, "--read") == 0)
    {
        read_file(path_one);
    }
    else if (strcmp(flag,"--write") == 0)
    {
        write_file(path_one, text);
    }
    else if (strcmp(flag, "--copy") == 0)
    {
        copy_file(path_one, path_two);
    }
    else if (strcmp(flag, "--delete") == 0)
    {
        delete_file(path_one);
    }
    else if (strcmp(flag, "--rename") == 0)
    {
        rename_file(path_one, path_two);
    }
    else if (strcmp(flag, "--move") == 0)
    {
        move_file(path_one, path_two);
    }
    else if (strcmp(flag, "--detail") == 0)
    {
        states_file(path_one);
    }
    else if (strcmp(flag, "--help") == 0) 
    {
        help_user(); 
    }
    else
    {
        printf("please provide appropriate flag\n");
        // add flag details to display to user.
    }

    return 0;
}