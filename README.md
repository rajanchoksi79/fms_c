
# 🔧 FMS - File Management System

A lightweight command-line utility written in C++ for basic file and directory management operations. Designed to be minimal, fast, and Unix-like.

---

## 📁 Features (So Far)

- ✅ Create, delete, rename files
- ✅ Create, delete directories
- ✅ Change file permissions
- ✅ Basic error handling with meaningful messages
- ✅ Uses low-level syscalls (`open`, `creat`, `chmod`, `unlink`, `rmdir`, etc.)
- ✅ Path and permission validation
- ✅ Access checks using `access()` before critical operations

---

## 📌 Planned Features

- 📂 Directory listing (like `ls`)
- 🔁 Recursive directory traversal
- 📋 File copy, move, rename support
- 🧠 Argument validation and better CLI parsing
- 📜 Logging (optional)
- 🌳 Possibly add recursive `mkdir` support
- 🛡️ Permission masking and safety guards

---

## 🚀 Getting Started

### 🔧 Compilation

```bash
g++ -o fms main.cpp file_op_one.cpp file_op_two.cpp file_op_three.cpp dir_op_one.cpp
````

> Adjust source files based on your structure.

### 🧪 Example Usage

```bash
./fms --createf /path/to/file.txt
./fms --removef /path/to/file.txt
./fms --createdir /path/to/new_folder
./fms --removedir /path/to/new_folder
./fms --changeperf /path/to/file.txt 0644
```

---

## 📁 Project Structure (WIP)

```
fms/
├── build
    ├── dir_op_one.o
    ├── file_op_one.o
    ├── file_op_two.o
    ├── file_op_three.o
    ├── fms
    ├── main.o
├── include
    ├── dir_op_one.h
    ├── file_op_one.h
    ├── file_op_two.h
    ├── file_op_three.h               
├── src 
    ├── dir_op_one.cpp                
    ├── file_op_one.cpp
    ├── file_op_two.cpp
    ├── file_op_three.cpp
├── .gitignore
├── Makefile
├── README.md
```

---

## 🛠️ Dependencies

* Standard C and C++ Library
* Unix/Linux system calls

---

## 💬 Notes

* This tool is currently **work-in-progress**.
* Intended as a personal learning + utility project.

---

## 👤 Author



* Rajan Choksi — Full Stack Developer diving into Rust & systems programming.

* 📢 Say hi on Twitter - https://x.com/Rajanchoksi_79 or check out more of my work on GitHub - https://github.com/rajanchoksi79

---

Made with ❤️ and C++.
---
