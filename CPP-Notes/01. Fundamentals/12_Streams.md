# Streams in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Input & Output
- `cin`
- `cout`
- Header Files

---

# Introduction

A **Stream** is a flow of data between a program and an input/output device.

Examples:

```
Keyboard  → Input Stream

Monitor   → Output Stream

File      → File Stream
```

Streams provide a uniform way to perform input and output regardless of the source or destination.

---

# Why Do We Need Streams?

Instead of learning different methods for:

- Keyboard Input
- File Input
- Network Input

C++ uses the concept of **Streams**.

Everything becomes:

```
Read from Stream

Write to Stream
```

This makes input and output consistent throughout the language.

---

# Data Flow

```
Keyboard
    │
    ▼
 Input Stream
    │
    ▼
 Program
    │
    ▼
Output Stream
    │
    ▼
 Monitor
```

---

# Stream Hierarchy

```
                 Streams
                    │
        ┌───────────┴───────────┐
        │                       │
 Input Streams           Output Streams
        │                       │
      cin             cout
                      cerr
                      clog
```

---

# Standard Streams

C++ provides four standard streams.

| Stream | Wide Version | Purpose |
|--------|--------------|----------|
| cin | wcin | Standard Input |
| cout | wcout | Standard Output |
| cerr | wcerr | Error Output |
| clog | wclog | Logging Output |

---

# Input Stream

An **Input Stream** carries data **into** the program.

Example:

```
Keyboard

↓

cin

↓

Variable
```

Example:

```cpp
int age;

cin >> age;
```

---

# Output Stream

An **Output Stream** carries data **out of** the program.

Example:

```
Program

↓

cout

↓

Monitor
```

Example:

```cpp
cout << "Hello";
```

---

# Buffer

A **Buffer** is a temporary memory area used to store data before it is processed.

Instead of sending data immediately,

the operating system temporarily stores it inside a buffer.

```
Program

↓

Buffer

↓

Screen
```

Buffering improves performance because multiple small operations can be combined into one larger operation.

---

# Buffered Stream

A **Buffered Stream** stores output temporarily before displaying it.

Advantages:

- Faster
- Fewer system calls
- Better performance

Example:

```
Program

↓

Buffer

↓

Screen
```

---

# Unbuffered Stream

An **Unbuffered Stream** displays output immediately.

```
Program

↓

Screen
```

No temporary storage is used.

---

# cout

`cout` stands for

```
Character Output Stream
```

Purpose:

- Display normal program output

Example:

```cpp
cout << "Hello";
```

Output:

```
Hello
```

`cout` is **buffered**.

---

# Why is cout Buffered?

Suppose a program prints:

```cpp
cout << "A";
cout << "B";
cout << "C";
```

Without buffering,

the operating system would perform three separate output operations.

Buffering combines them, reducing overhead and improving performance.

---

# cerr

`cerr` stands for

```
Character Error Stream
```

Purpose:

- Error messages
- Runtime failures
- Critical warnings
- Debugging

Example:

```cpp
cerr << "File not found";
```

---

# Why Does cerr Exist?

Normal program output and error messages serve different purposes.

Example:

```cpp
cout << "Welcome User";

cerr << "Database Connection Failed";
```

The user output and the error message should remain separate.

---

# cerr is Unbuffered

Unlike `cout`,

`cerr` is **unbuffered**.

Meaning:

Output appears immediately.

Example:

```cpp
cerr << "Fatal Error";
```

The message is displayed instantly.

---

# Why is cerr Unbuffered?

Suppose a program crashes immediately after detecting an error.

If the error message were still waiting inside a buffer,

it might never appear.

Example:

```cpp
cerr << "Memory Corruption Detected";
```

This message must be displayed before the program terminates.

---

# Real Use Cases of cerr

## File Opening Failure

```cpp
ifstream file("data.txt");

if(!file)
{
    cerr << "Cannot open file";
}
```

---

## Invalid Input

```cpp
if(age < 0)
{
    cerr << "Invalid Age";
}
```

---

## Null Pointer

```cpp
if(ptr == nullptr)
{
    cerr << "Null Pointer";
}
```

---

## Debugging

```cpp
cerr << "x = " << x;
```

---

# stderr

Internally,

`cerr` is connected to

```
stderr
```

whereas

`cout`

is connected to

```
stdout
```

Although both usually appear on the terminal,

they are separate operating system streams.

---

# Error Redirection

On Linux,

```
./program 2> errors.txt
```

redirects

```
stderr
```

to

```
errors.txt
```

Normal program output still appears on the terminal.

---

# clog

`clog` stands for

```
Character Log Stream
```

Purpose:

- Logging
- Program history
- Monitoring
- Debugging
- Execution tracing

---

# What is Logging?

Logging means recording important events while the program executes.

Examples:

```
Program Started

User Logged In

Database Connected

Cache Updated

API Request Received
```

These are **not errors**.

They simply record what happened.

---

# Why Does clog Exist?

Programs generally produce three different types of output.

```
Normal Output

↓

cout
```

```
Errors

↓

cerr
```

```
Logs

↓

clog
```

Keeping them separate makes large applications easier to monitor and debug.

---

# clog is Buffered

Unlike `cerr`,

`clog` is buffered.

Messages are stored temporarily before being displayed.

This improves performance because logging can happen very frequently.

---

# Real Use Cases of clog

Program Start

```cpp
clog << "Program Started";
```

---

User Login

```cpp
clog << "User Authenticated";
```

---

Database

```cpp
clog << "Database Connected";
```

---

Debug Flow

```cpp
clog << "Reached Function A";
```

---

Performance

```cpp
clog << "Execution Time = " << time;
```

---

# Professional Logging

Professional logging systems usually include:

- Timestamp
- Log Level
- Thread ID
- Function Name
- File Name

Example:

```
[INFO] Program Started

[WARNING] High Memory Usage

[ERROR] Database Connection Failed

[FATAL] System Crash
```

---

# Log Levels

| Level | Meaning |
|--------|----------|
| INFO | General Information |
| DEBUG | Debugging Information |
| WARNING | Potential Problem |
| ERROR | Serious Problem |
| FATAL | Program Cannot Continue |

---

# Wide Streams

C++ also provides wide versions of standard streams.

| Normal | Wide |
|--------|------|
| cin | wcin |
| cout | wcout |
| cerr | wcerr |
| clog | wclog |

Used together with

```cpp
wchar_t
```

Example:

```cpp
wchar_t ch = L'अ';

wcout << ch;
```

---

# Summary of Standard Streams

| Stream | Buffered | Purpose |
|--------|----------|----------|
| cin | Yes | Input |
| cout | Yes | Normal Output |
| cerr | No | Errors |
| clog | Yes | Logs |

---

# Best Practices

- Use `cout` for normal program output.
- Use `cerr` for error messages.
- Use `clog` for logging and debugging.
- Never use `cout` for reporting critical errors.
- Keep logs, errors, and user output separate.

---

# Important Points

- A stream is a flow of data.
- `cin` performs input.
- `cout` performs normal output.
- `cerr` performs immediate error output.
- `clog` is used for logging.
- `cout` and `clog` are buffered.
- `cerr` is unbuffered.
- Buffering improves performance.
- Standard streams simplify input and output by providing a common interface.

---

# Summary

- Streams are the foundation of input and output in C++.
- C++ provides separate streams for user output, error reporting, and logging.
- Understanding buffering helps explain why `cout`, `cerr`, and `clog` behave differently.
- Streams are widely used throughout C++, including file handling, string processing, and networking.

---

## What's Next?

**Next Chapter:** Type Conversion

You'll learn:

- Implicit Type Conversion
- Explicit Type Conversion
- Widening & Narrowing Conversion
- Arithmetic Conversion Rules
- C-style Cast
- Functional Cast
- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`
