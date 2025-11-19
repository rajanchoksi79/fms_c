#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <vector>
#include "../include/colors.h"

int line_count = 0;
int match_count = 0;

int comparing_line_with_pattern(std::string line, std::string pattern) 
{
    std::vector<std::string> line_array;
    std::string word;

    for (int i = 0; i < line.size(); i++) 
    {
        if (line[i] == ' ') 
        {
            line_array.push_back(word);
            word.clear();
        }
        else 
        {
            word.push_back(line[i]);
        }
    }

    for (int j = 0; j < line_array.size(); j++) 
    {
        if (pattern == line_array[j]) 
        {
            match_count++;
            std::cout << COLOR_YELLOW COLOR_BOLD << "Line: " << line_count << " -> " << COLOR_RESET << ' ';

            for (int k = 0; k < line_array.size(); k++) 
            {
                if (pattern == line_array[k]) 
                {
                    std::cout << COLOR_RED COLOR_BOLD << line_array[k] << " " << COLOR_RESET; 
                }  
                else 
                {
                    std::cout << line_array[k] << " ";
                }
            }

            std::cout << "\n";
        }
    }   

    return 0;
}

int pattern_matching(char *path, std::string pattern) 
{
    if ((access(path, F_OK) == -1) || (access(path, R_OK) == -1)) 
    {
        std::cerr << "-> Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1) 
    {
        std::cerr << "-> Error occured " << strerror(errno) << std::endl;
        return 1;
    }

    ssize_t buffer_read;
    char buffer[1024];
    std::string line;

    std::cout << '\n';
    std::cout << COLOR_CYAN COLOR_BOLD << "-> Searching for pattern: '" << pattern << "'\n"; 
    std::cout << "-> File: '" << path << "'\n\n" << COLOR_RESET;  

    while ((buffer_read = read(fd, buffer, sizeof(buffer))) > 0) 
    {
        for (ssize_t i = 0; i < buffer_read; i++) 
        {
            if (buffer[i] == '\n') 
            {
                line_count++;
                comparing_line_with_pattern(line, pattern);
                line.clear();
            }
            else 
            {
                line.push_back(buffer[i]);
            }
        }
    }

    if (buffer_read == -1) 
    {
        std::cerr << "~> Error occured, " << strerror(errno) << '\n';
        if (close(fd) == -1)
        {
            std::cerr << "~> Error occured, " << strerror(errno) << '\n';
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        std::cerr << "~> Error occured, " << strerror(errno) << '\n';
        return 1;
    }

    std::cout << COLOR_YELLOW COLOR_BOLD << "\n-> " << match_count << " match found\n"; 
    std::cout << '\n';

    return 0;

}

int count_details(char *path) 
{
    // checking file if it exist and also if it is readable
    if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
    {
        std::cerr << "-> Error occured, " << strerror(errno) << '\n';
        return 1;
    }

    // creating file descriptor for opening file to read it later
    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "-> Error occured, " << strerror(errno) << '\n';
        return 1;
    }

    std::cout << '\n';
    std::cout << COLOR_CYAN COLOR_BOLD << "-> Counting details: " << '\n'; 
    std::cout << "-> File: '" << path << "'\n\n" << COLOR_RESET;  

    ssize_t buffer_read;
    // for now i am keeping buffer upto 1024 chars, but if needed then set it to max value thing.
    char buffer[1024];
    std::string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    while ((buffer_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (ssize_t i = 0; i < buffer_read; i++) 
        {   
            // increasing character in every character even in new line character for now.
            character_count++;

            // so at every new line character there is new line so increasing line counter at that point.
            if (buffer[i] == '\n') 
            {
                line_count++;
            }
            else if (buffer[i] == ' ') 
            {
                word_count++;
            }
        }
    }

    if (buffer_read == -1)
    {
        std::cerr << "~> Error occured, " << strerror(errno) << '\n';
        if (close(fd) == -1)
        {
            std::cerr << "~> Error occured, " << strerror(errno) << '\n';
            return 1;
        }
        return 1;
    }

    if (close(fd) == -1)
    {
        std::cerr << "~> Error occured, " << strerror(errno) << '\n';
        return 1;
    }

    // displaying various counts
    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Character Count:  " << COLOR_RESET << character_count << '\n';
    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Word Count:       " << COLOR_RESET << word_count << '\n';
    std::cout << COLOR_YELLOW COLOR_BOLD << "-> Line Count:       " << COLOR_RESET << line_count << '\n';
 
    std::cout << '\n';
    return 0;
}