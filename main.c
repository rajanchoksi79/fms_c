#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include "file_op_one.h"
#include "file_op_two.h"
#include "file_op_three.h"


int main(int argc, char *argv[])
{
    char *flag = argv[1];
    char *path_one = argv[2];
    char *text, *path_two;
    mode_t permission_code;

    if (strcmp(flag, "--writef") == 0)
    {
        if (argv[3] == NULL)
        {
            perror("please provide text to write in given file");
            return 1;
        }
        text = argv[3];
    }

    if (strcmp(flag, "--copyf") == 0 || strcmp(flag, "--movef") == 0 || strcmp(flag, "--renamef") == 0)
    {
        if (argv[3] == NULL)
        {
            perror("please provide new path where you want to copy file one");
            return 1;
        }
        path_two = argv[3];
    }

    // refactore and fix this, this is temp.
    if (strcmp(flag, "--changeperf") == 0) 
    {   
        if (argv[3] == NULL) 
        {
            perror("please provide permission code to change permission of file");
            return 1;
        }
        permission_code = parse_octal_mode(argv[3]);
        printf("permission code in main: %o\n", permission_code);
        if (permission_code == (mode_t)-1) 
        {   
            // i already handled error in parse octal function, here i am just returning in case of error
            return 1;
        }
    }

    if (strcmp(flag, "--createf") == 0)
    {
        create_file(path_one);
    }
    else if (strcmp(flag, "--readf") == 0)
    {
        read_file(path_one);
    }
    else if (strcmp(flag,"--writef") == 0)
    {
        write_file(path_one, text);
    }
    else if (strcmp(flag, "--copyf") == 0)
    {
        copy_file(path_one, path_two);
    }
    else if (strcmp(flag, "--deletef") == 0)
    {
        delete_file(path_one);
    }
    else if (strcmp(flag, "--renamef") == 0)
    {
        rename_file(path_one, path_two);
    }
    else if (strcmp(flag, "--movef") == 0)
    {
        move_file(path_one, path_two);
    }
    else if (strcmp(flag, "--detailf") == 0)
    {
        states_file(path_one);
    }
    else if (strcmp(flag, "--changeperf") == 0) 
    {
        change_file_permission(path_one, permission_code);
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