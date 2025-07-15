#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/file_op_one.h"
#include "../include/file_op_two.h"
#include "../include/file_op_three.h"
#include "../include/dir_op_one.h"
#include "../include/mis_op_one.h"


int main(int argc, char *argv[])
{

    char *flag, *path_one, *path_two, *text;
    mode_t permission_code;

    if (argc < 2) 
    {
        help_user();
    }
    else if (argc < 3) 
    {
        flag = argv[1];

        if (strcmp(flag, "--currentdir") == 0) 
        {
            get_current_directory();
        }
        else if (strcmp(flag, "--help") == 0) 
        {
            help_user(); 
        }
        else if (strcmp(flag, "--about") == 0) 
        {
            about();
        }
        else if (strcmp(flag, "--version") == 0) 
        {
            version();
        }
        else
        {
            appropriate_flag();
        }
    }
    else if (argc < 4) 
    {
        flag = argv[1];
        path_one = argv[2];

        if (strcmp(flag, "--createf") == 0)
        {
            create_file(path_one);
        }
        else if (strcmp(flag, "--readf") == 0)
        {
            read_file(path_one);
        }
        else if (strcmp(flag, "--removef") == 0)
        {
            remove_file(path_one);
        }
        else if (strcmp(flag, "--detailf") == 0)
        {
            states_file(path_one);
        }
        else if (strcmp(flag, "--createdir") == 0) 
        {
            create_directory(path_one);
        }
        else if (strcmp(flag, "--readdir") == 0) 
        {
            read_directory(path_one);
        }
        else if (strcmp(flag, "--removedir") == 0) 
        {
            remove_directory(path_one);
        }
        else
        {
            printf("please provide appropriate flag\n");
            // add flag details to display to user.
        }
    }
    else if (argc < 5) 
    {
        flag = argv[1];
        path_one = argv[2];

        if (strcmp(flag, "--writef") == 0)
        {
            if (argv[3] == NULL)
            {
                printf("Error occured, %s\n", strerror(errno));
                return 1;
            }
            text = argv[3];
            write_file(path_one, text);
        }
        else if (strcmp(flag, "--copyf") == 0 || strcmp(flag, "--movef") == 0 || strcmp(flag, "--renamef") == 0)
        {
            if (argv[3] == NULL)
            {
                printf("Error occured, %s\n", strerror(errno));
                return 1;
            }
            path_two = argv[3];

            if (strcmp(flag, "--copyf") == 0)
            {
                copy_file(path_one, path_two);
            }
            else if (strcmp(flag, "--movef") == 0)
            {
                move_file(path_one, path_two);
            }
            else if (strcmp(flag, "--renamef") == 0)
            {
                rename_file(path_one, path_two);
            }
        }
        // refactore and fix this, this is temp.
        else if (strcmp(flag, "--changeperf") == 0) 
        {   
            if (argv[3] == NULL) 
            {
                printf("Error occured, %s\n", strerror(errno));
                return 1;
            }
            permission_code = parse_octal_mode(argv[3]);
            if (permission_code == (mode_t)-1) 
            {   
                // i already handled error in parse octal function, here i am just returning in case of error
                return 1;
            }

            change_file_permission(path_one, permission_code);
        }
    }    

    return 0;
}