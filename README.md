
# 🔧 FMS - File Management System

A lightweight command-line utility written in C for basic file and directory management operations. Designed to be minimal, fast, and Unix-like.

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
gcc -o fms main.c file_op_one.c file_op_two.c file_op_three.c dir_op_one.c
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
├── main.c             # Entry point, argument parsing
├── file_op_one.c/h    # File-related operations
├── file_op_two.c/h    # File-related operations
├── file_op_three.c/h  # File-related operations
├── dir_op_one.c/h        # Directory-related operations
├── README.md
```

---

## 🛠️ Dependencies

* Standard C Library
* Unix/Linux system calls

---

## 💬 Notes

* This tool is currently **work-in-progress**.
* Intended as a personal learning + utility project.
* Future plans may include porting to C++ or using CLI frameworks for better parsing.

---

## 👤 Author



* Rajan Choksi — Full Stack Developer diving into Rust & systems programming.

* 📢 Say hi on Twitter - https://x.com/Rajanchoksi_79 or check out more of my work on GitHub - https://github.com/rajanchoksi79

---

Made with ❤️ and C.
---
