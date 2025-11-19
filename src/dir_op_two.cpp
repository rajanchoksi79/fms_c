#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 500
#include <fcntl.h>
#include <iostream>
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
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    return 0;
}

// this is kind of global variable, but if needed put it somewhere if this is not safer option.
int file_count = 0;
int directory_count = 0;

const char *get_basename(const char *rel_path)
{
    const char *slash = strrchr(rel_path, '/');
    return slash ? slash + 1 : rel_path;
}

int print_directory_content(const char *rel_path, const struct stat *stat_buf, int typeflag, struct FTW *ftw_buf)
{
    // this is temp
    (void)stat_buf;

    for (int i = 0; i < ftw_buf->level; i++)
    {
        std::cout << "│  ";
    }

    switch (typeflag)
    {
    case FTW_D:
        std::cout << "├── " << COLOR_CYAN << get_basename(rel_path) << COLOR_RESET << std::endl;
        directory_count++;
        break;
    case FTW_F:
        std::cout << "├── " << get_basename(rel_path) << std::endl;
        file_count++;
        break;
    default:
        std::cout << "├── " << get_basename(rel_path) << std::endl;
    }

    return 0;
}

int read_directory_rec(char *path)
{

    if (access(path, F_OK) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    printf(COLOR_CYAN COLOR_BOLD "\n%s\n\n" COLOR_RESET, path);

    // for now i am keeping this 10, change it if you need to.
    int max_no_directory = 20;
    if (nftw(path, print_directory_content, max_no_directory, FTW_PHYS) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    std::cout << COLOR_YELLOW COLOR_BOLD << "\n-> " <<directory_count << (directory_count == 1 ? " Directory, " : " Directories, "); 
    std::cout << COLOR_YELLOW COLOR_BOLD << file_count << (file_count == 1 ? " File" : " Files") << COLOR_RESET << std::endl;
    std::cout << std::endl;

    // printf(COLOR_YELLOW COLOR_BOLD "\n-> %d %s, " COLOR_RESET, directory_count, directory_count == 1 ? "Directory" : "Directories");
    // printf(COLOR_YELLOW COLOR_BOLD "%d %s\n\n" COLOR_RESET, file_count, file_count == 1 ? "File" : "Files");
    return 0;
}

int remove_directory_content(const char *rel_path, const struct stat *stat_buf, int typeflag, struct FTW *ftw_buf)
{
    // this is temp
    (void)typeflag;
    (void)stat_buf;
    (void)ftw_buf;

    // because remove can call both unlink or rmdir based on being a file or a directory, so i am using it here.
    if (remove(rel_path) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    return 0;
}

int remove_directory_rec(char *path)
{
    if (access(path, F_OK) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    // for now i am keeping this 20 change it if you need more.
    int max_no_directory = 20;
    if (nftw(path, remove_directory_content, max_no_directory, FTW_PHYS) == -1)
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    // so this is temp i included this here, because inner files and things are removed from above function and with nfts alongside but the main directory is not removed so that is why.
    // if (remove(path) == -1) 
    // {
    //     printf("Error occured, %s\n", strerror(errno));
    //     return 1;
    // }

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> Directory and it's content removed successfully\n\n";
    return 0;
}