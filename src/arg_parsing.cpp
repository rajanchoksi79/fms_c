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
#include "../include/file_op_four.h"
#include "../include/file_op_five.h"

int arg_parser(int argc, char *argv[]) 
{
    std::string flag;
    std::string sub_flag;
    bool file_operation = false;
    bool dir_operation = false;
    char *path_one, *path_two, *text;

    mode_t permission_code;

    if (argc < 2) 
    {
        help_user();
    }
    else if (argc < 3) 
    {
        flag = argv[1];

        if (flag == "-f" || flag == "--file") 
        {
            file_operation = true;
            file_related_flag_subflag_details();
            return 1;
        } 
        else if (flag == "-d" || flag == "--dir") 
        {
            dir_operation = true;
            directory_related_flag_subflag_details();
            return 1;
        }
        else if (flag == "-h" || flag == "--help") 
        {
            help_user(); 
        }
        else if (flag == "-a" || flag == "--about") 
        {
            about();
        }
        else if (flag == "-v" || flag == "--version") 
        {
            version();
        }
        else
        {
            appropriate_flag();
            return 1;
        }
    }
    else if (argc < 4) 
    {
        flag = argv[1];
        sub_flag = argv[2];

        if (flag == "-f" || flag == "--file") 
        {
            file_operation = true;
        } 
        else if (flag == "-d" || flag == "--dir") 
        {
            dir_operation = true;
        }
        else 
        {
            appropriate_flag();
            return 1;
        }

        if (dir_operation && sub_flag == "--current") 
        {
            get_current_directory();
        }
        else
        {
            appropriate_flag();
            return 1;
        }
    }
    else if (argc < 5) 
    {
        flag = argv[1];
        sub_flag = argv[2];
        path_one = argv[3];

        if (flag == "-f" || flag == "--file") 
        {
            file_operation = true;
        } 
        else if (flag == "-d" || flag == "--dir") 
        {
            dir_operation = true;
        }
        else 
        {
            appropriate_flag();
            return 1;
        }

        if (file_operation && sub_flag == "--create")
        {
            create_file(path_one);
        }
        else if (file_operation && sub_flag == "--read")
        {
            read_file(path_one);
        }
        else if (file_operation && sub_flag == "--remove")
        {
            remove_file(path_one);
        }
        else if (file_operation && sub_flag == "--detail")
        {
            states_file(path_one);
        }
        else if (file_operation && sub_flag == "--count") 
        {
            count_details(path_one);
        }
        else if (dir_operation && sub_flag == "--create") 
        {
            create_directory(path_one);
        }
        else if (dir_operation && sub_flag == "--read") 
        {
            read_directory(path_one);
        }
        else if (dir_operation && sub_flag == "--remove") 
        {
            remove_directory(path_one);
        }
        else if (dir_operation && sub_flag == "--move") 
        {
            move_directory(path_one);
        }
        else if (dir_operation && sub_flag == "--readrec") 
        {
            read_directory_rec(path_one);
        }
        else if (dir_operation && sub_flag == "--remove") 
        {
            remove_directory_rec(path_one);
        }
        else
        {
            appropriate_flag();
            return 1;
        }
    }
    else if (argc < 6) 
    {
        flag = argv[1];
        sub_flag = argv[2];
        path_one = argv[3];

        if (flag == "-f" || flag == "--file") 
        {
            file_operation = true;
        } 
        else if (flag == "-d" || flag == "--dir") 
        {
            dir_operation = true;
        }
        else 
        {
            appropriate_flag();
            return 1;
        }

        if (file_operation && sub_flag == "--write")
        {
            if (argv[4] == NULL)
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            text = argv[4];
            write_file(path_one, text);
        }
        else if (file_operation && (sub_flag == "--copy" || sub_flag == "--move" || sub_flag == "--rename"))
        {
            if (argv[4] == NULL)
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            path_two = argv[4];

            if (sub_flag == "--copy")
            {
                copy_file(path_one, path_two);
            }
            else if (sub_flag == "--move")
            {
                move_file(path_one, path_two);
            }
            else if (sub_flag == "--rename")
            {
                rename_file(path_one, path_two);
            }
        }
        // refactore and fix this, this is temp.
        else if (file_operation && sub_flag == "--changeper") 
        {   
            if (argv[4] == NULL) 
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            permission_code = parse_octal_mode(argv[4]);
            if (permission_code == (mode_t)-1) 
            {   
                // i already handled error in parse octal function, here i am just returning in case of error
                return 1;
            }

            change_file_permission(path_one, permission_code);
        }
        else if (file_operation && sub_flag == "--pattern") 
        {
            if (argv[4] == NULL) 
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            std::string pattern = argv[4];
            pattern_matching(path_one, pattern);
        }
        else if (file_operation && sub_flag == "--encrypt") 
        {
            if (argv[4] == NULL) 
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            std::string key = argv[4];
            encrypt_file(path_one, key);
        }
        else if (file_operation && sub_flag == "--decrypt") 
        {
            if (argv[4] == NULL) 
            {
                std::cerr << "-> Error occured " << strerror(errno) << std::endl;
                return 1;
            }
            std::string key = argv[4];
            decrypt_file(path_one, key);
        }
        else 
        {
            appropriate_flag();
            return 1;
        }
    }    

    return 0;
}