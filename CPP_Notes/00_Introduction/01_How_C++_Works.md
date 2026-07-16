# 01_How_C++_Works.md

# How Does C++ Actually Work?

In the previous chapter, we learned that computers do **not** understand C++.

This naturally raises an important question:

> If computers only understand machine language (binary), how does a C++ program actually run?

This chapter answers that question.

By the end of this chapter, you'll understand the complete journey of a C++ program—from writing the code to seeing its output on the screen.

---

# The Journey of a C++ Program

Suppose we write the following program.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!";
    return 0;
}
```

At first glance, it looks simple.

However, before the computer can print

```
Hello, World!
```

your program goes through several stages.

```
Write Code
      │
      ▼
Save Source File (.cpp)
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
Object File (.o / .obj)
      │
      ▼
Linker
      │
      ▼
Executable (.exe / a.out)
      │
      ▼
Loader
      │
      ▼
Program Runs
```

Every C++ program follows this pipeline.

---

# Step 1 : Writing the Source Code

The first step is writing code.

Example:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello";
}
```

This file is called the **source file**.

Usually it has extensions like

```
.cpp
.cc
.cxx
```

Examples

```
main.cpp

program.cpp

calculator.cpp
```

Humans understand this code.

The computer does not.

---

# Step 2 : Saving the File

Once the file is saved,

```
main.cpp
```

becomes an ordinary text file.

It contains characters like

```
#

i

n

t

m

a

i

n

(
```

Your operating system simply stores these characters on disk.

Nothing has been translated into machine language yet.

---

# Think 🤔

If you rename

```
main.cpp
```

to

```
main.txt
```

does the code disappear?

No.

The contents remain exactly the same.

Only the extension changes.

The extension simply tells software how the file should be treated.

---

# Step 3 : The Preprocessor

Before the compiler starts translating your code,

the **Preprocessor** processes special instructions.

These instructions are called

**Preprocessor Directives**

Examples:

```cpp
#include

#define

#ifdef

#ifndef
```

Notice something interesting.

They all begin with

```
#
```

Example

```cpp
#include <iostream>
```

This line is **not** understood directly by the compiler.

Instead,

the preprocessor replaces it with the contents of the iostream header file.

Think of it as copying and pasting the required declarations into your source code before compilation begins.

So,

```
main.cpp
```

↓

becomes

```
Expanded Source Code
```

---

# What is a Header File?

A header file contains declarations that tell the compiler about available functions, classes, and other language features.

For example,

```
iostream
```

contains declarations related to

```
std::cout

std::cin

std::cerr
```

We'll study header files in detail later.

For now, just remember:

> A header file tells the compiler **what exists**, not necessarily **how it works**.

---

# Step 4 : Compilation

Now comes the Compiler.

The compiler translates C++ source code into assembly language.

During compilation it performs many important tasks.

Examples:

- Checks syntax
- Checks data types
- Detects undeclared variables
- Performs optimizations
- Generates assembly code

Suppose we write

```cpp
int x = "Hello";
```

The compiler immediately reports an error.

Why?

Because

```
int
```

cannot store

```
"Hello"
```

This is called a **compile-time error**.

No executable is created until these errors are fixed.

---

# Compiler Errors

Examples:

```cpp
int x = ;
```

Missing value.

---

```cpp
cout << x
```

Missing semicolon.

---

```cpp
int 5number;
```

Invalid identifier.

---

These are detected before the program runs.

---

# Step 5 : Assembly Code

After successful compilation,

your C++ code becomes Assembly Language.

Example

```
MOV

ADD

CALL

PUSH

POP
```

Assembly is much closer to machine language than C++.

It is still readable by humans.

Computers still do not execute assembly directly.

---

# Step 6 : The Assembler

The assembler converts assembly language into machine code.

Machine code looks something like

```
101010101001001

001010101010001

111010101001010
```

Now the instructions can finally be understood by the CPU.

The output of this stage is called an

**Object File**

Examples

Linux

```
main.o
```

Windows

```
main.obj
```

---

# What is an Object File?

An object file contains machine code.

However,

it is **NOT** a complete program yet.

Why?

Because it may still depend on code stored in libraries.

Example

```cpp
std::cout
```

Your own source file doesn't contain the implementation of `std::cout`.

It only knows that such an object exists.

The actual implementation lives inside the C++ Standard Library.

So another step is needed.

---

# Step 7 : Linking

This is the job of the **Linker**.

The linker combines

- Your object files
- Standard library files
- Other library files

into one executable program.

Suppose your program uses

```cpp
std::cout
```

The linker finds its implementation and connects it to your program.

If it cannot find it,

you get a

```
Linker Error
```

---

# Example of a Linker Error

Suppose you declare

```cpp
void display();
```

but never define it.

The compiler is happy because it knows the function exists.

Later,

the linker searches for its implementation.

It cannot find one.

Result:

```
Undefined Reference
```

This is a linker error.

---

# Step 8 : Executable File

After linking,

the final program is created.

Windows

```
program.exe
```

Linux/macOS

```
a.out
```

or any executable name you choose.

Now your program is complete.

---

# Step 9 : Loading

When you double-click

```
program.exe
```

or run

```
./a.out
```

the operating system loads the program into RAM.

This is done by a component called the

**Loader**.

The loader

- Allocates memory
- Loads instructions
- Loads required libraries
- Starts execution

---

# Step 10 : Execution

Finally,

the CPU begins executing instructions one by one.

```
Fetch

↓

Decode

↓

Execute
```

This process repeats millions or even billions of times every second.

Eventually,

your program prints

```
Hello, World!
```

---

# Complete Picture

```
You

↓

main.cpp

↓

Preprocessor

↓

Compiler

↓

Assembly Code

↓

Assembler

↓

Object File

↓

Linker

↓

Executable

↓

Loader

↓

RAM

↓

CPU

↓

Program Output
```

This is the complete life cycle of a C++ program.

---

# Why Should You Learn This?

Many beginners skip this topic because it seems theoretical.

However, understanding this process helps explain many things you'll encounter later:

- Why header files exist
- Why linker errors occur
- Why multiple source files work
- Why compilation takes time
- What object files are
- Why libraries are needed
- How executable files are created

Many advanced C++ concepts become much easier once this pipeline is clear.

---

# Summary

A C++ program does **not** run immediately after you write it.

It goes through several stages:

1. Write source code
2. Save source file
3. Preprocessing
4. Compilation
5. Assembly generation
6. Assembly to machine code
7. Linking
8. Executable creation
9. Loading into memory
10. Execution by the CPU

Every C++ application, from a simple calculator to a modern game engine, follows this process.

---

# What's Next?

In the next chapter, we'll study the **Compilation Process** in much greater depth.

We'll understand:

- Source Files
- Header Files
- Translation Units
- Object Files
- Static Libraries
- Dynamic Libraries
- Linkers
- Build Systems

These concepts are essential for understanding professional C++ projects.
