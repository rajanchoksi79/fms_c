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
#include "../include/dir_op_two.h"
#include "../include/mis_op_one.h"
#include "../include/arg_parsing.h"

int main(int argc, char *argv[])
{
    arg_parser(argc, argv);
    return 0;
}