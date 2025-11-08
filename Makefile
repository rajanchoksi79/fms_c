# Compiler and flags
CC = g++
CFLAGS = -Iinclude -Wall -Wextra -g

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files and object files
SRC = $(SRC_DIR)/arg_parsing.cpp \
      $(SRC_DIR)/dir_op_one.cpp \
      $(SRC_DIR)/dir_op_two.cpp \
      $(SRC_DIR)/file_op_one.cpp \
      $(SRC_DIR)/file_op_three.cpp \
      $(SRC_DIR)/file_op_two.cpp \
      $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/mis_op_one.cpp
	  
# OBJ is now automatically derived from SRC
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

# Output binary
OUT = $(BUILD_DIR)/fms

# Default target
all: $(BUILD_DIR) $(OUT)

# Link object files into final binary
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Compile .cpp to .o (Generic Rule)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
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