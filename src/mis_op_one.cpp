#include <stdio.h>
#include <iostream>
#include "../include/mis_op_one.h"
#include "../include/colors.h"

int file_related_flag_subflag_details() 
{
    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> please provide appropriate subflag alongside file flag\n\n" << COLOR_RESET;
    std::cout << "Below are the list of flags and subflags for different files related operations with details\n\n";

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> File operation related flags: \n\n" << COLOR_RESET;
    printf("%-10s %-20s\n\n", "Flag: ", "Subflag:");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--createf", "for creating new file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--readf", "for reading file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--writef", "for writing in a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--removef", "for removing file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--detailf", "for knowing details of a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--copyf", "for copying a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--movef", "for moving a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--renamef", "for renaming a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--changeperf", "for changing permissions in a file");
    printf("\n\n");

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Usage Examples: \n\n" << COLOR_RESET;
    printf("fms -f --createf myfile.txt         # Create a new file named myfile.txt\n");
    printf("fms -f --readf myfile.txt           # Read contents of myfile.txt\n");
    printf("fms -f --writef myfile.txt          # Write content into myfile.txt\n");
    printf("\n");

    return 0;
}

int directory_related_flag_subflag_details() 
{
    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> please provide appropriate subflag alongside directory flag\n\n" << COLOR_RESET;
    std::cout << "Below are the list of flags and subflags for different directory related operations with details\n\n";

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Directory operation related flags: \n\n" << COLOR_RESET;
    printf("%-10s %-20s\n\n", "Flag: ", "Subflag:");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--createdir", "for creating new directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--readdir", "for reading contents of a directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--readdirr", "for reading contents of a directory recursively");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--removedir", "for removing an empty directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--removedirr", "for removing directory recursively");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--movedir", "for moving a directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--currentdir", "for getting current working directory");
    printf("\n\n");

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Usage Examples: \n\n" << COLOR_RESET;
    printf("fms -d --createdir myfolder         # Create a new directory named myfolder\n");
    printf("fms -d --removedir myfolder         # Remove a directory myfolder\n");
    printf("fms -d --currentdir                 # Info about current working directory\n");
    printf("\n\n");

    return 0;
}

int flag_subflag_details() 
{
    std::cout << COLOR_YELLOW COLOR_BOLD << "-> File operation related flags: \n\n" << COLOR_RESET;
    printf("%-10s %-20s\n\n", "Flag: ", "Subflag:");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--createf", "for creating new file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--readf", "for reading file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--writef", "for writing in a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--removef", "for removing file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--detailf", "for knowing details of a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--copyf", "for copying a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--movef", "for moving a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--renamef", "for renaming a file");
    printf("%-10s %-20s %-40s\n", "-f/--file", "--changeperf", "for changing permissions in a file");
    printf("\n\n");

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Directory operation related flags: \n\n" << COLOR_RESET;
    printf("%-10s %-20s\n\n", "Flag: ", "Subflag:");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--createdir", "for creating new directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--readdir", "for reading contents of a directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--readdirr", "for reading contents of a directory recursively");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--removedir", "for removing an empty directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--removedirr", "for removing directory recursively");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--movedir", "for moving a directory");
    printf("%-10s %-20s %-40s\n", "-d/--dir", "--currentdir", "for getting current working directory");
    printf("\n\n");

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Other flags: \n\n" << COLOR_RESET;
    printf("%-10s\n\n", "Flag: ");
    printf("%-20s %s\n", "--help", "for help to use this tool");
    printf("%-20s %s\n", "--about", "for knowing more about this tool");
    printf("%-20s %s\n", "--version", "for getting version of this tool");
    printf("\n\n");

    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Usage Examples: \n\n" << COLOR_RESET;
    std::cout << "File related operations: \n\n";
    printf("fms -f --createf myfile.txt         # Create a new file named myfile.txt\n");
    printf("fms -f --readf myfile.txt           # Read contents of myfile.txt\n");
    printf("fms -f --writef myfile.txt          # Write content into myfile.txt\n");
    printf("\n");

    std::cout << "Directory related operations: \n\n";
    printf("fms -d --createdir myfolder         # Create a new directory named myfolder\n");
    printf("fms -d --removedir myfolder         # Remove a directory myfolder\n");
    printf("fms -d --currentdir                 # Info about current working directory\n");
    printf("\n\n");

    return 0;
}

int help_user() 
{
    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> Welcome to fms - File Management System\n\n" << COLOR_RESET;
    std::cout << "An all in one tool to do all your file or directory related operations\n\n";

    flag_subflag_details();

    return 0;
}

int version() 
{
    std::cout << "\n";
    std::cout << "fms - File Management System\n";
    std::cout << "Version: 1.0\n";
    std::cout << "Build Date: " << __DATE__ << "\n";
    std::cout << "Build Time: " << __TIME__ << "\n";
    std::cout << "\n";
    return 0;
}

int about() 
{
    std::cout << "\n";
    std::cout << "fms - File Management System\n";
    std::cout << "Developed by Rajan Choksi | Version 2.0.0\n\n";

    std::cout << "This command-line tool is built to perform basic file and directory\n";
    std::cout << "operations easily and efficiently — like creating, reading, copying,\n";
    std::cout << "removing files or directories, and more.\n\n";

    std::cout << "Use '--help' to see available flags.\n";
    std::cout << "\n";
    return 0;
}

int appropriate_flag() 
{   
    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> please provide appropriate flag and subflag\n\n" << COLOR_RESET;
    std::cout << "Below are the list of flags and subflags for different files and directory related operations with details\n\n";
    
    flag_subflag_details();

    return 0;
}