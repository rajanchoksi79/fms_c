#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <errno.h>
#include "../include/file_op_one.h"
#include "../include/file_op_two.h"
#include "../include/file_op_three.h"
#include "../include/dir_op_one.h"
#include "../include/dir_op_two.h"
#include "../include/mis_op_one.h"
#include "../include/arg_parsing.h"

int arg_parser(int argc, char *argv[]) 
{
    std::string flag;
    char *path_one, *path_two, *text;

    mode_t permission_code;

    if (argc < 2) 
    {
        help_user();
    }
    else if (argc < 3) 
    {
        flag = argv[1];

        if (flag == "--currentdir") 
        {
            get_current_directory();
        }
        else if (flag == "--help") 
        {
            help_user(); 
        }
        else if (flag == "--about") 
        {
            about();
        }
        else if (flag == "--version") 
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

        if (flag == "--createf")
        {
            create_file(path_one);
        }
        else if (flag == "--readf")
        {
            read_file(path_one);
        }
        else if (flag == "--removef")
        {
            remove_file(path_one);
        }
        else if (flag == "--detailf")
        {
            states_file(path_one);
        }
        else if (flag == "--createdir") 
        {
            create_directory(path_one);
        }
        else if (flag == "--readdir") 
        {
            read_directory(path_one);
        }
        else if (flag == "--removedir") 
        {
            remove_directory(path_one);
        }
        else if (flag == "--mvdir") 
        {
            move_directory(path_one);
        }
        else if (flag == "--readdirr") 
        {
            read_directory_rec(path_one);
        }
        else if (flag == "--removedirr") 
        {
            remove_directory_rec(path_one);
        }
        else
        {
            appropriate_flag();
        }
    }
    else if (argc < 5) 
    {
        flag = argv[1];
        path_one = argv[2];

        if (flag == "--writef")
        {
            if (argv[3] == NULL)
            {
                std::cerr << "Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            text = argv[3];
            write_file(path_one, text);
        }
        else if (flag == "--copyf" || flag == "--movef" || flag == "--renamef")
        {
            if (argv[3] == NULL)
            {
                std::cerr << "Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            path_two = argv[3];

            if (flag == "--copyf")
            {
                copy_file(path_one, path_two);
            }
            else if (flag == "--movef")
            {
                move_file(path_one, path_two);
            }
            else if (flag == "--renamef")
            {
                rename_file(path_one, path_two);
            }
        }
        // refactore and fix this, this is temp.
        else if (flag == "--changeperf") 
        {   
            if (argv[3] == NULL) 
            {
                std::cerr << "Error occured " << strerror(errno) << std::endl;
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
        else 
        {
            appropriate_flag();
        }
    }    

    return 0;
}