#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <cstdlib>
#include "../include/colors.h"

char *get_absolute_path_enc(char *path) 
{
    // for now i am just keeping length of memory as much as path, and adding 5 to that.
    char *absolute_path_enc = (char*)malloc(strlen(path) + 5);
    if (!absolute_path_enc) 
    {   
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return NULL;
    }

    strcpy(absolute_path_enc, path);
    
    char *last_char_absolute_path = strrchr(absolute_path_enc, '.');
    if (last_char_absolute_path) 
    {
        last_char_absolute_path++;
        strcpy(last_char_absolute_path, "enc");
    }
    else 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        // i have to see what to return in case of error in char type function for now i am returning NULL
        return NULL;
    }

    return absolute_path_enc;
}

char *get_absolute_path_dec(char *path) 
{
    char *absolute_path_dec = (char*)malloc(strlen(path) + 5);
    if (!absolute_path_dec) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return NULL;
    }

    strcpy(absolute_path_dec, path);

    char *last_char_absolute_path = strrchr(absolute_path_dec, '.');
    if (last_char_absolute_path) 
    {
        last_char_absolute_path++;
        strcpy(last_char_absolute_path, "txt"); 
    }
    else 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        // i have to see what to return in case of error in char type function for now i am returning NULL
        return NULL;
    }

    return absolute_path_dec;
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
        
        // test code
        std::cout << "error occured here in input fd" << std::endl;
        
        return 1;
    }

    int output_fd;
    char *new_path = get_absolute_path_enc(path); 
    
    output_fd = open(new_path, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (output_fd == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        
        // test code
        std::cout << "error occured here in output fd" << std::endl;
        std::cout << "absolute path in output fd is: " << new_path << std::endl;

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
            buffer[j] ^= key[i % key_length];
        }

        write(output_fd, buffer, sizeof(buffer));
        i += byte_read;
    }

    if (byte_read == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";

        // test code
        std::cout << "error occured in byte read" << std::endl;

    }

    if (close(input_fd) == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    if (close(output_fd) == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    free(new_path);

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> File encrypted successfully\n\n" << COLOR_RESET;    
    return 0;
}

int decrypt_file(char *path, std::string key) 
{
    // for now i just kept F_OK here, i am not sure about R_OK because it's enc file here so ...
    if (access(path, F_OK) == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    int input_fd;
    input_fd = open(path, O_RDONLY);
    if (input_fd == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        
        // test code
        std::cout << "error occured here in input fd" << std::endl;
        
        return 1;
    }

    int output_fd;
    char *new_path = get_absolute_path_dec(path);

    output_fd = open(new_path, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
    if (output_fd == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        
        // test code
        std::cout << "error occured here in output fd" << std::endl;
        std::cout << "absolute path in output fd is: " << new_path << std::endl;

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
            buffer[j] ^= key[i % key_length];
        }

        write(output_fd, buffer, sizeof(buffer));
        i += byte_read;
    }

    if (byte_read == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";

        // test code
        std::cout << "error occured in byte read" << std::endl;

    }

    if (close(input_fd) == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    if (close(output_fd) == -1) 
    {
        std::cerr << "\n⚠  Error occured " << strerror(errno) << "\n\n";
        return 1;
    }

    free(new_path);

    std::cout << COLOR_CYAN COLOR_BOLD << "\n-> File decrypted successfully\n\n" << COLOR_RESET;    
    return 0;
}