# Introduction to C++

---

# What is Programming?

Programming is the process of giving instructions to a computer so that it performs a specific task.

A computer **cannot think, make decisions, or understand human language** on its own. It simply follows instructions exactly as they are given.

These instructions are called a **program**.

### Examples

- A calculator adds two numbers because someone programmed it.
- A web browser loads websites because someone programmed it.
- Games respond to keyboard input because someone programmed them.
- Chat applications send messages because someone programmed them.

Without programs, a computer is just an electronic machine capable of executing instructions—it doesn't know what to do.

---

# What is a Program?

A **program** is a collection of instructions written in a programming language to solve a problem or perform a task.

Examples of programs include:

- Calculator
- Chrome Browser
- Microsoft Word
- Photoshop
- VS Code
- WhatsApp
- Spotify

Each of these is simply a very large collection of instructions.

---

# Think 🤔

Suppose you ask a friend:

> "Please make me a cup of tea."

Your friend already knows how to make tea.

Now suppose you ask a computer:

> "Make me a cup of tea."

Can it do it?

No.

The computer doesn't understand what "tea" means.

It only understands instructions like

1. Turn on the machine.
2. Heat water.
3. Wait 3 minutes.
4. Add tea leaves.
5. Stir.

A computer only follows instructions that have been explicitly programmed.

---

# What is a Programming Language?

A programming language is a language used to write programs that computers can execute.

Just as humans use languages like

- English
- Hindi
- Spanish

to communicate with each other,

programmers use programming languages such as

- C++
- Python
- Java
- JavaScript
- C#
- Go
- Rust

to communicate with computers.

However...

There is an important difference.

Humans understand natural languages.

Computers **do not.**

---

# Does a Computer Understand C++?

No.

This is one of the biggest misconceptions beginners have.

A computer **does not understand C++.**

It also does not understand

- Python
- Java
- JavaScript
- C
- Rust

It only understands one language.

---

# Machine Language

The only language a computer understands is **Machine Language** (also called **Machine Code**).

Machine language consists entirely of binary digits:

```text
10110100
00101011
11100010
00010011
```

Every instruction executed by your processor eventually becomes binary.

For example,

Something as simple as

```cpp
int sum = a + b;
```

will eventually be converted into several machine instructions before your CPU executes it.

---

# Then Why Don't We Write Binary?

Imagine writing a calculator like this:

```text
101001010010101011001010101010
110010101001010101001010100101
001010101001010100101010101001
```

Now imagine writing WhatsApp.

Or Instagram.

Or Windows.

It would be almost impossible.

Writing software directly in binary would be:

- Extremely difficult
- Very slow
- Error-prone
- Nearly impossible to maintain

Humans need a language that is easier to read and write.

Programming languages solve this problem.

---

# High-Level vs Low-Level Languages

Programming languages can be broadly divided into two categories.

## Low-Level Languages

Low-level languages are closer to the computer's hardware.

Examples:

- Machine Language
- Assembly Language

Characteristics:

- Very fast
- Difficult to read
- Hardware dependent
- Requires detailed knowledge of the computer

Example (Assembly):

```asm
MOV AX, 5
ADD AX, 10
```

---

## High-Level Languages

High-level languages are closer to human language.

Examples:

- C++
- Python
- Java
- JavaScript
- C#
- Kotlin

Characteristics:

- Easy to read
- Easier to write
- Easier to debug
- More portable
- More productive

Example:

```cpp
int sum = a + b;
```

This is much easier to understand than binary or assembly.

---

# Where Does C++ Fit?

C++ is considered a **high-level programming language**, but it also gives programmers low-level control over memory and hardware.

This is one of the reasons C++ is so powerful.

It allows you to write code that is both:

- Easy for humans to understand.
- Efficient enough to interact closely with hardware when needed.

This balance between abstraction and control makes C++ suitable for everything from small applications to operating systems, game engines, and embedded systems.

---

# Why Was C++ Created?

To answer this, we need to look briefly at the history of programming languages.

Early programmers mostly used Assembly Language.

Assembly gave excellent control over hardware, but writing large programs was extremely difficult.

Then came the C programming language.

C made programming much easier while still being fast and efficient.

However, as software projects became larger, C had limitations:

- No classes
- No objects
- Limited support for code reuse
- Difficult to manage very large projects

To solve these problems, **Bjarne Stroustrup** extended the C language by adding features such as classes and object-oriented programming.

The result was **C++**.

Initially, it was called **"C with Classes."**

Later, it became known as **C++**.

---

# Why is it Called "C++"?

The `++` operator in C increments a value by one.

Example:

```cpp
int x = 5;

x++;
```

Now,

```
x = 6
```

The name **C++** suggests:

> "An improved version of C."

It is a clever play on the increment operator.

---

# Features of C++

Some of the most important features of C++ are:

- Fast execution
- High performance
- Object-Oriented Programming
- Procedural Programming
- Generic Programming (Templates)
- Standard Template Library (STL)
- Direct memory management
- Rich standard library
- Cross-platform support
- Large community
- Suitable for both low-level and high-level programming

Don't worry if you don't understand some of these terms yet—we'll cover each of them in detail later.

---

# Where is C++ Used?

C++ is widely used in areas where performance and control over system resources are important.

Some common applications include:

- Operating Systems
- Game Engines (Unreal Engine)
- Browsers
- Database Systems
- Embedded Systems
- Robotics
- Compilers
- Financial Trading Software
- AI/ML libraries
- Device Drivers
- Simulation Software

---

# Why Should You Learn C++ Today?

Even after several decades, C++ remains one of the most valuable programming languages because it teaches:

- Programming fundamentals
- Memory management
- Problem-solving
- Data Structures and Algorithms
- Object-Oriented Programming
- Generic Programming
- Performance optimization

It is widely used in:

- Software engineering interviews
- Competitive programming
- Systems programming
- Game development
- Embedded development
- High-performance applications

Learning C++ also makes it easier to learn many other programming languages because you gain a deep understanding of how computers execute programs.

---

# Summary

After completing this chapter, you should understand:

- What programming is.
- What a program is.
- What a programming language is.
- Why computers cannot understand C++ directly.
- What machine language is.
- Why high-level languages exist.
- Where C++ fits among programming languages.
- Why C++ was created.
- Where C++ is used today.
- Why it remains one of the best languages to learn.

---

# What's Next?

In the next chapter, we'll answer one of the most important questions in computer science:

> **How does a C++ program actually run?**

We'll follow a C++ program from the moment you save a `.cpp` file until it becomes a running application, covering concepts like source code, compiler, linker, executable files, and the role of the operating system.
