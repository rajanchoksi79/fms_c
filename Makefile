# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output binary
OUT = $(BUILD_DIR)/fms

# Default target
all: $(BUILD_DIR) $(OUT)

# Link object files into final binary
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Compile .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build
clean:
	rm -rf $(BUILD_DIR)

# Run the compiled binary
run: all
	./$(OUT)

# Debug with gdb
debug: all
	gdb ./$(OUT)
