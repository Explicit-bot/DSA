# Comilation Process

When we write a C++ program, the computer **cannot understand it directly**.Computers only understand **machine language (0s and 1s)**.Therefore, our C++ source code must go through several stages before it becomes an executable program.This entire process is called the **Compilation Process** or **Build Process**.

---

# Overview

```
Source Code (.cpp)
        │
        ▼
Preprocessor
        │
        ▼
Compiler
        │
        ▼
Assembler
        │
        ▼
Object File (.o/.obj)
        │
        ▼
Linker
        │
        ▼
Executable (.exe / a.out)
```

---

# Step 1 : Source Code

This is the code written by the programmer.

Example:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World";
    return 0;
}
```

Extension:

```
.cpp
```

Examples:

```
main.cpp
program.cpp
calculator.cpp
```

This file is called the **Source File**.

---

# Step 2 : Preprocessor

Before actual compilation begins, the source file is processed by the **Preprocessor**.

It handles:

- `#include`
- `#define`
- Conditional Compilation
- Macros

Example:

```cpp
#include <iostream>
```

The preprocessor replaces it with the contents of the `<iostream>` header file.

Similarly,

```cpp
#define PI 3.14
```

becomes

```cpp
3.14
```

wherever `PI` appears.

The output of the preprocessor is called the **Expanded Source Code**.

---

# Step 3 : Compiler

The compiler translates C++ code into **Assembly Language**.

During this stage it:

- Checks syntax
- Checks data types
- Detects compile-time errors
- Performs optimizations
- Generates assembly code

Example:

```cpp
int x = "Hello";
```

Produces:

```
Compilation Error
```

because a string cannot be assigned to an integer.

---

# Compile-Time Errors

Errors detected during compilation are called **Compile-Time Errors**.

Examples:

```cpp
int x = "Hello";
```

```cpp
cout << y;
```

```cpp
if(x >)
```

The executable file is **not created** until these errors are fixed.

---

# Step 4 : Assembler

Assembly language is still not machine language.

The **Assembler** converts assembly code into **Machine Code**.

The output is called an **Object File**.

Extensions:

Windows:

```
.obj
```

Linux/macOS:

```
.o
```

Object files contain machine code, but the program is **not complete yet**.

---

# Step 5 : Linker

A program usually uses external libraries.

Example:

```cpp
#include <iostream>
```

The functions inside `<iostream>` are **not present** in your source file.

The **Linker** combines:

- Your object files
- Standard library files
- Other object files
- External libraries

into one executable program.

---

# Linking Example

Suppose:

```
main.cpp
math.cpp
```

Both are compiled separately.

The linker combines them into:

```
program.exe
```

or

```
a.out
```

---

# Linker Errors

Sometimes compilation succeeds but linking fails.

Example:

```cpp
int add(int, int);

int main() {
    add(2,3);
}
```

If the definition of `add()` is missing:

```cpp
int add(int,int);
```

the linker reports an error because it cannot find the function implementation.

These are called **Linker Errors**.

---

# Step 6 : Executable File

After successful linking, the final executable is created.

Examples:

Windows

```
program.exe
```

Linux

```
a.out
```

or

```
program
```

Running the executable starts the program.

---

# Why is C++ Called a Compiled Language?

Because the **entire program is translated into machine code before execution**.

The executable can then run directly on the operating system.

---

# Compiler vs Interpreter

| Compiler | Interpreter |
|-----------|-------------|
| Translates entire program | Translates line by line |
| Produces executable | No separate executable |
| Faster execution | Slower execution |
| Errors shown after compilation | Errors shown during execution |
| Example: C++, C | Example: Python, JavaScript |

---

# Popular C++ Compilers

- GCC (g++)
- Clang++
- MSVC (Microsoft Visual C++)

To compile successfully, the system needs:
- A compiler
- A linker
- The C++ Standard Library
- Header files (iostream, vector, etc.)
- Startup code
- Runtime libraries

Together, these form a toolchain(E.g MinGW(gcc) , Xcode(clang), Visual studio(MSVC))

---

# Basic Compilation Command

Using **g++**

Compile:

```bash
g++ main.cpp
```

Creates:

```
a.out
```

Compile with output name:

```bash
g++ main.cpp -o program
```

Run (Linux/macOS):

```bash
./program
```

Run (Windows):

```bash
program.exe
```

---

# Common Types of Errors

## 1. Compile-Time Error

Detected by compiler.

Example:

```cpp
int x = "Hello";
```

---

## 2. Linker Error

Occurs while linking.

Example:

```cpp
Undefined reference to add()
```

---

## 3. Runtime Error

Occurs while program is running.

Examples:

- Division by zero
- Null pointer dereference
- Stack overflow

---

## 4. Logical Error

Program runs successfully but produces incorrect output.

Example:

```cpp
int area = length + width;
```

instead of

```cpp
int area = length * width;
```

# Note
- GNU = GNU's Not Unix
- GCC = GNU Compiler Collection

---
