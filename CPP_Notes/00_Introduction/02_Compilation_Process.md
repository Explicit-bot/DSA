# 02_Compilation_Process.md

# The C++ Compilation Process

In the previous chapter, we saw the complete journey of a C++ program.

```
Write Code
      ↓
Preprocessor
      ↓
Compiler
      ↓
Assembler
      ↓
Linker
      ↓
Executable
      ↓
Loader
      ↓
Execution
```

In this chapter, we're going to study every stage in much greater depth.

By the end of this chapter, you'll understand exactly how a C++ source file becomes a running program.

---

# Why Should You Learn the Compilation Process?

Many beginners ignore this topic because it seems theoretical.

However, almost every professional C++ developer encounters problems related to compilation.

For example,

- Why does this header file cause an error?
- What is an undefined reference?
- Why is compilation taking so long?
- Why do object files exist?
- Why do we need libraries?
- Why is this function declared but "not found"?

All these questions are answered by understanding the compilation process.

---

# Before We Begin

Suppose we have a very small project.

```
Project/

│

├── main.cpp

└── math.cpp
```

Contents of **main.cpp**

```cpp
#include <iostream>

int add(int,int);

int main()
{
    std::cout << add(5,7);
}
```

Contents of **math.cpp**

```cpp
int add(int a,int b)
{
    return a+b;
}
```

When you press **Run**, does the compiler simply convert everything into machine code?

No.

There are several independent stages.

Let's study them one by one.

---

# Stage 1 : Preprocessing

The first stage is called **Preprocessing**.

The program responsible for this stage is called the **Preprocessor**.

The preprocessor works on lines beginning with

```
#
```

These are called **Preprocessor Directives**.

Examples

```cpp
#include

#define

#ifdef

#ifndef

#if

#pragma
```

Notice something.

These are **not C++ statements.**

They are instructions for the preprocessor.

The compiler never sees them directly.

---

## Example

Suppose we write

```cpp
#include <iostream>

int main()
{
}
```

The preprocessor replaces

```cpp
#include <iostream>
```

with the contents of the iostream header.

Conceptually,

Before preprocessing

```cpp
#include <iostream>

int main()
{
}
```

After preprocessing

```cpp
// thousands of lines

class ostream
{
    ...
};

class istream
{
    ...
};

...

int main()
{
}
```

The actual expansion is much larger, but this gives you the idea.

The compiler receives the expanded source code.

---

# What Else Does the Preprocessor Do?

Besides including files,

it also

- Expands macros
- Removes comments
- Handles conditional compilation

For example

```cpp
#define PI 3.14159
```

becomes

```cpp
3.14159
```

everywhere PI is used.

We'll study macros later.

---

# Stage 2 : Compilation

After preprocessing,

the compiler starts its work.

This is where actual C++ language analysis begins.

The compiler checks

- Syntax
- Types
- Variables
- Functions
- Classes
- Templates
- Namespaces

Everything related to C++ grammar.

---

## Example

Correct

```cpp
int x = 5;
```

Incorrect

```cpp
int x = ;
```

Compiler

```
Error:
expected expression
```

---

Another example

```cpp
int age = "Naman";
```

Compiler

```
cannot convert
```

This is called a

**Compile-Time Error**

---

# What Does the Compiler Produce?

Many beginners think

Compiler

↓

Executable

This is not true.

The compiler actually generates

**Assembly Language**

Example

```
MOV

CALL

PUSH

POP

ADD
```

This language is much closer to the CPU.

---

# Stage 3 : Assembling

The assembler converts assembly language into machine language.

Example

Assembly

```
MOV AX,5
```

↓

Machine Language

```
101011010101001010
```

This output is stored inside an

**Object File**

Examples

Windows

```
main.obj
```

Linux/macOS

```
main.o
```

---

# What is an Object File?

An object file is **not a complete program.**

Instead,

it contains

- Machine code
- Symbol information
- Relocation information

Think of it as one piece of the final puzzle.

---

## Example

Suppose we have

```
main.cpp

math.cpp

student.cpp
```

The compiler creates

```
main.o

math.o

student.o
```

Three separate object files.

They still need to be combined.

---

# Why Doesn't the Compiler Create One Executable Directly?

Imagine a project with

```
500

CPP files
```

Now suppose you modify

```
main.cpp
```

Should the compiler recompile all 500 files?

That would be extremely slow.

Instead,

only

```
main.cpp
```

is recompiled.

Its object file is recreated.

Then everything is linked again.

This makes development much faster.

---

# Stage 4 : Linking

Now the linker starts.

The linker combines

```
main.o

math.o

student.o
```

↓

```
program.exe
```

It also connects

- Standard Library
- User Libraries
- Third-party Libraries

to your program.

---

# Example

Suppose

main.cpp

contains

```cpp
int add(int,int);

int main()
{
    add(5,7);
}
```

math.cpp

contains

```cpp
int add(int a,int b)
{
    return a+b;
}
```

The compiler compiles both files independently.

Later,

the linker connects

```
add()
```

used in main.cpp

with

```
add()
```

defined inside math.cpp

---

# Linker Errors

Suppose we declare

```cpp
void print();
```

but never define it.

The compiler says

"No problem."

Because

the declaration exists.

Later

the linker searches for

```
print()
```

It cannot find it.

Result

```
Undefined Reference

or

Unresolved External Symbol
```

depending on the compiler.

This is **not** a compiler error.

It is a linker error.

---

# Compiler Error vs Linker Error

Compiler Error

↓

Problem inside one source file.

Examples

- Missing semicolon
- Wrong syntax
- Unknown variable
- Type mismatch

---

Linker Error

↓

Problem connecting multiple files.

Examples

- Undefined reference
- Duplicate symbols
- Missing library

---

# Translation Units

This is one of the most important concepts in C++.

A **Translation Unit** is

```
Source File

+

All Included Headers

↓

After Preprocessing
```

The compiler compiles one translation unit at a time.

Later,

the linker combines all translation units.

We'll revisit this when studying header files.

---

# Static Libraries

Suppose someone has already written

```
10000

functions
```

Should you copy all of them into your project?

No.

Instead,

they are packaged into

```
Static Library

(.lib)

(.a)
```

The linker copies only the required functions into your executable.

---

# Dynamic Libraries

Instead of copying library code,

the executable can use

```
DLL

Windows
```

or

```
Shared Library

.so

Linux
```

These libraries are loaded when the program starts.

Advantages

- Smaller executable
- Shared among many applications
- Easy updates

Disadvantages

- Program depends on external library

We'll study this in Multi-file Programming.

---

# Loader

After linking,

the operating system loads

```
program.exe
```

into RAM.

This job is done by the

Loader.

The loader

- Allocates memory
- Loads libraries
- Sets up the stack
- Sets up the heap
- Starts execution

Only after this does

```
main()
```

begin executing.

Notice something important.

The first function executed by **your code** is usually `main()`, but **the operating system and runtime perform setup work before `main()` is called**. We'll explore that later in the course.

---

# Complete Pipeline

```
Source Code

↓

Preprocessor

↓

Expanded Source Code

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

Every C++ application follows this pipeline.

---

# Key Takeaways

✔ Computers do not execute C++ code directly.

✔ The preprocessor handles directives beginning with `#`.

✔ The compiler checks C++ syntax and semantics and generates assembly.

✔ The assembler converts assembly into machine code.

✔ Object files are incomplete pieces of the final program.

✔ The linker combines object files and libraries into an executable.

✔ The loader prepares the program in memory before execution begins.

✔ `main()` is not literally the first instruction executed by the process; runtime initialization occurs first.

---

# What's Next?

Now that you understand **how C++ programs are built**, we're finally ready to write our first real C++ program and understand every line of it.

The next chapter is:

> **01_Basics → 00_Variables_DataTypes_Literals.md**

We'll begin with a fundamental question:

> **What is memory, and why do variables exist?**
