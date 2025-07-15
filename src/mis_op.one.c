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
    printf("please provide appropriate flag\n");
    printf("\n");
    
    printf("File operation related flags\n");
    printf("\n");
    printf("--createf:\tfor creating new file\n");
    printf("--readf:\tfor reading file\n");
    printf("--writef:\tfor writing in a file\n");
    printf("--removef:\tfor removing file\n");
    printf("--detailf:\tfor knowing details of a file\n");
    printf("--copyf:\tfor copying a file\n");
    printf("--movef:\tfor moving a file\n");
    printf("--renamef:\tfor renaming a file\n");
    printf("--changeperf:\tfor changing permissions in a file\n");
    
    printf("Directory operation related flags\n");
    printf("\n");
    printf("--createdir:\tfor creating new directory\n");
    printf("--readdir:\tfor reading contents of a directory\n");
    printf("--removedir:\tfor removing an empty directory\n");
    printf("--currentdir:\tfor getting current working directory\n");
    
    printf("Other flags\n");
    printf("\n");
    printf("--help:\tfor help to use this tool");
    printf("--about:\tfor knowing more about this tool");
    printf("--version:\tfor getting version of this tool");
    
    return 0;
}