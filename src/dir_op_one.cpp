#define _DEFAULT_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/dir_op_one.h"
#include "../include/colors.h"


int create_directory(char *path)
{
    if (access(path, F_OK) == 0)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    int new_dir = mkdir(path, 0755);
    if (new_dir == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> New directory created successfully\n\n" << COLOR_RESET;
    return 0;
}

// reading and printing content of directory
int read_directory(char *path)
{
    if (access(path, F_OK) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        // i have to see do i need this closedir here, just like in open 
        if (closedir(dir) == -1)
        {
            std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
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
    std::cout << std::endl;    
    // printf("\n");

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
                std::cout << "├── " << entry->d_name << std::endl;
                file_count += 1;
            }
            else if ((file_detail.st_mode & S_IFMT) == S_IFDIR)
            {   
                std::cout << "├── " << COLOR_CYAN << entry->d_name << COLOR_RESET << std::endl;
                directory_count += 1;
            }
            else if ((file_detail.st_mode & S_IFMT) == S_IFLNK)
            {
                std::cout << "├── " << COLOR_GREEN << entry->d_name << COLOR_RESET << std::endl;
            }
            else
            {   
                std::cout << "|_ " << entry->d_name << std::endl;
            }
        }
        else 
        {
            std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
            return 1;
        }
    }

    std::cout << COLOR_YELLOW COLOR_BOLD << "\n-> " << directory_count << (directory_count == 1 ? " Directory, " : " Directories, "); 
    std::cout << COLOR_YELLOW COLOR_BOLD << file_count << (file_count == 1 ? " File" : " Files") << COLOR_RESET << std::endl;
    std::cout << std::endl;

    // printf(COLOR_YELLOW COLOR_BOLD "\n-> %d %s, " COLOR_RESET, directory_count, directory_count == 1  ? "Directory" : "Directories"); 
    // printf(COLOR_YELLOW COLOR_BOLD "%d %s\n\n" COLOR_RESET, file_count, file_count == 1 ? "File" : "Files");

    if (closedir(dir) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
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
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> " << buffer << "\n\n" COLOR_RESET;
    return 0;
}

// this works only on empty directory.
int remove_directory(char *path)
{
    if (access(path, F_OK) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    if (rmdir(path) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> Directory removed successfully\n\n" << COLOR_RESET;
    return 0;
}