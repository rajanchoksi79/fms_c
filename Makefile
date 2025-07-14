CC = gcc
CFLANGS = -Iinclude -Wall -Wextra -g

SRC = src/main.c src/file_op_one.c src/file_op_two.c src/file_op_three.c src/dir_op_one.c 
OUT = build/fms

all:
    $(CC) $(CFLANGS) $(SRC) -o $(OUT)

clean:
    rm -f $(OUT)    