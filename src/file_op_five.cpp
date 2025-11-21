#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char *get_filename(char *path) 
{
    char *filename = strrchr(path, '/');
    if (filename) 
    {
        // shifting pointer from last slash to first letter of filename
        filename++;
    }
    else 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        // i have to see what to return in case of error in char type function for now i am returning NULL
        return NULL;
    }
    
    return filename;
}

char *get_absolute_path(char *path) 
{
    char absolute_path[256];
    strcpy(absolute_path, path);

    char *last_char_absolute_path = strrchr(absolute_path, '/');
    if (last_char_absolute_path) 
    {
        *last_char_absolute_path = '\0';
    }
    else 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        // i have to see what to return in case of error in char type function for now i am returning NULL
        return NULL;
    }

    return absolute_path;
}

int encrypt_file(char *path, std::string key) 
{
    if ((access(path, F_OK) == -1) || (access(path, R_OK) == -1)) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    int input_fd;
    input_fd = open(path, O_RDONLY);
    if (input_fd == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    int output_fd;
    char *absolute_path = get_absolute_path(path); 
    char *file_name = get_filename(path); 
    
    output_fd = open(absolute_path, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (output_fd == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    ssize_t byte_read;
    char buffer[1024];
    int key_length = sizeof(key);    
    int i = 0;

    while ((byte_read = read(input_fd, buffer, sizeof(buffer))) > 0) 
    {
        for (int j = 0; j < byte_read; j++) 
        {
            buffer[j] ^= key[(i + j) % key_length];
        }

        write(output_fd, buffer, sizeof(buffer));
        i += byte_read;
    }



    return 0;
}

int decrypt_file(char *path, std::string key) 
{

}