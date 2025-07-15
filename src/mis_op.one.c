#include <stdio.h>
#include "../include/mis_op_one.h"

int help_user() 
{
    printf("\n");
    printf("Welcome to fms - File Management System\n");
    printf("An all in one tool to do all your file or directory related operations\n");
    printf("\n");

    printf("File operation related flags\n");
    printf("\n");
    printf("%-20s %s\n", "--createf", "for creating new file");
    printf("%-20s %s\n", "--readf", "for reading file");
    printf("%-20s %s\n", "--writef", "for writing in a file");
    printf("%-20s %s\n", "--removef", "for removing file");
    printf("%-20s %s\n", "--detailf", "for knowing details of a file");
    printf("%-20s %s\n", "--copyf", "for copying a file");
    printf("%-20s %s\n", "--movef", "for moving a file");
    printf("%-20s %s\n", "--renamef", "for renaming a file");
    printf("%-20s %s\n", "--changeperf", "for changing permissions in a file");
    printf("\n");

    printf("Directory operation related flags\n");
    printf("\n");
    printf("%-20s %s\n", "--createdir", "for creating new directory");
    printf("%-20s %s\n", "--readdir", "for reading contents of a directory");
    printf("%-20s %s\n", "--removedir", "for removing an empty directory");
    printf("%-20s %s\n", "--currentdir", "for getting current working directory");
    printf("\n");

    printf("Other flags\n");
    printf("\n");
    printf("%-20s %s\n", "--help", "for help to use this tool");
    printf("%-20s %s\n", "--about", "for knowing more about this tool");
    printf("%-20s %s\n", "--version", "for getting version of this tool");
    printf("\n");

    printf("Usage Examples: \n");
    printf("\n");
    printf("File operations: \n");
    printf("\n");
    printf("fms --createf myfile.txt         # Create a new file named myfile.txt\n");
    printf("fms --readf myfile.txt           # Read contents of myfile.txt\n");
    printf("fms --writef myfile.txt          # Write content into myfile.txt\n");
    printf("\n");

    printf("Directory operations: \n");
    printf("\n");
    printf("fms --createdir myfolder         # Create a new directory\n");
    printf("fms --removedir myfolder         # Remove a directory\n");
    printf("fms --currentdir myfolder        # Info about current working directory\n");
    printf("\n");

    return 0;
}

int version() 
{
    printf("\n");
    printf("fms - File Management System\n");
    printf("Version: 1.0\n");
    printf("Build Date: %s\n", __DATE__);
    printf("Build Time: %s\n", __TIME__);
    printf("\n");
    return 0;
}

int about() 
{
    printf("\n");
    printf("fms - File Management System\n");
    printf("Developed by Rajan Choksi | Version 1.0.0\n");
    printf("\n");

    printf("This command-line tool is built to perform basic file and directory\n");
    printf("operations easily and efficiently — like creating, reading, copying,\n");
    printf("removing files or directories, and more.\n");
    printf("\n");

    printf("Use '--help' to see available flags.\n");
    printf("\n");
    return 0;
}

int appropriate_flag() 
{
    printf("\n");
    printf("please provide appropriate flag\n");
    printf("Below are the list of flags for different files and directory related operations with details\n");
    printf("\n");
    
    printf("File operation related flags\n");
    printf("\n");
    printf("%-20s %s\n", "--createf", "for creating new file");
    printf("%-20s %s\n", "--readf", "for reading file");
    printf("%-20s %s\n", "--writef", "for writing in a file");
    printf("%-20s %s\n", "--removef", "for removing file");
    printf("%-20s %s\n", "--detailf", "for knowing details of a file");
    printf("%-20s %s\n", "--copyf", "for copying a file");
    printf("%-20s %s\n", "--movef", "for moving a file");
    printf("%-20s %s\n", "--renamef", "for renaming a file");
    printf("%-20s %s\n", "--changeperf", "for changing permissions in a file");
    printf("\n");

    printf("Directory operation related flags\n");
    printf("\n");
    printf("%-20s %s\n", "--createdir", "for creating new directory");
    printf("%-20s %s\n", "--readdir", "for reading contents of a directory");
    printf("%-20s %s\n", "--removedir", "for removing an empty directory");
    printf("%-20s %s\n", "--currentdir", "for getting current working directory");
    printf("\n");

    printf("Other flags\n");
    printf("\n");
    printf("%-20s %s\n", "--help", "for help to use this tool");
    printf("%-20s %s\n", "--about", "for knowing more about this tool");
    printf("%-20s %s\n", "--version", "for getting version of this tool");
    printf("\n");
    
    return 0;
}