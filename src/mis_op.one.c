#include <stdio.h>
#include "../include/mis_op_one.h"

int help_user() 
{
    printf("here i will print all the help related things like kind of guide to user about how to use app and different flags\n");
    return 0;
}

int version() 
{
    printf("here you get info about version of this tool\n");
    return 0;
}

int about() 
{
    printf("here you get info about this tool\n");
    return 0;
}

int appropriate_flag() 
{
    printf("\n");
    printf("please provide appropriate flag\n");
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