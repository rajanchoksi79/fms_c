#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int create_file(char *path)
{
    int fd;
    fd = creat(path, 0644);
    if (fd == -1)
    {
        perror("error occured while creating file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to creating it");
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("error closing file, after creating it");
        return 1;
    }

    printf("file created successfully\n");
    return 0;
}

int read_file(char *path)
{
    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("error occured while opening file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_read;
    // i need to see if i need to increase or decrease this, the buffer size.
    char buffer[128];
    while ((byte_read = read(fd, buffer, sizeof(buffer))) > 0)
    {   
        // i haven't handled error that may occure in writing here.
        write(STDOUT_FILENO, buffer, byte_read);
    }
    printf("\n");

    if (byte_read == -1)
    {
        perror("failed to read file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to read it");
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("error closing file, after reading it");
        return 1;
    }

    return 0;
}

// right now it is overwriting to file.
int write_file(char *path, char *text)
{
    int fd;
    // for now i kept this as write only, if needed then change this to read and write.
    fd = open(path, O_WRONLY);
    if (fd == -1)
    {
        perror("error occured while opening file");
        if (close(fd) == -1)
        {
            perror("error closing file, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_write;
    byte_write = write(fd, text, strlen(text));
    if (byte_write == -1)
    {
        perror("error occured while writing file");
        if (close(fd) == -1) 
        {
            perror("error closing file, after failed to write it");
            return 1;
        }
        return 1;
    }
    
    if (close(fd) == -1)
    {
        perror("error closing file, after writing it");
        return 1;
    }

    printf("Success: text written to file successfully\n");
    return 0;
}

// void rename_file()
// {
// }

// void remove_file()
// {
// }

// void move_file()
// {
// }

int copy_file(char path_one, char path_two)
{
    int fd_one;
    fd_one = open(path_one, O_RDONLY);
    if (fd_one == -1)
    {
        perror("error occured while opening file one");
        if (close(fd_one) == -1)
        {
            perror("error closing file one, after failed to open it");
            return 1;
        }
        return 1;
    }

    int fd_two;
    fd_two = creat(path_two, 0644);
    if(fd_two == -1) 
    {
        perror("error occured while opening file two");
        if (close(fd_two) == -1)
        {
            perror("error closing file two, after failed to open it");
            return 1;
        }
        return 1;
    }

    ssize_t byte_read, byte_write;
    char buffer[128];
    while ((byte_read = read(fd_one, buffer, sizeof(buffer))) > 0) 
    {
        byte_write = write(fd_two, buffer, byte_read);
        if (byte_write == -1) 
        {
            perror("error occured while writing file two");
            if (close(fd_two) == -1) 
            {
                perror("error closing file, after failed to write it");
                return 1;
            }
            // i need to know whether return can break the loop here because here i have to break the loop because of error, so i need to know that otherwise i have to use break;
            return 1;
        }
    }

    if (close(fd_one) == -1) 
    {
        perror("error closing file, after reading from it");
        return 1;
    }

    if (close(fd_two) == -1) 
    {
        perror("error closing file, after writing in it");
        return 1;
    }

    printf("Success: content copied from file one to file two\n");
    return 0;
}

int main(int argc, char *argv[])
{
    char *flag = argv[1];
    char *path_one = argv[2];
    char *text, *path_two;

    if (*flag == 'w')
    {
        if (argv[3] == NULL)
        {
            perror("please provide text to write in given file");
            return 1;
        }
        text = argv[3];
    }
    
    if (*flag == 'p') 
    {
        if (argv[3] == NULL) 
        {
            perror("please provide new path where you want to copy file one");
        }
    } 

    switch (*flag)
    {
    case 'c':
        create_file(path_one);
        break;
    case 'r':
        read_file(path_one);
        break;
    case 'w':
        write_file(path_one, text);
        break;
    case 'p':
        copy_file(path_one, path_two);
        break;    
    default:
        printf("please provide appropriate flag\n");
        break;
    }

    return 0;
}