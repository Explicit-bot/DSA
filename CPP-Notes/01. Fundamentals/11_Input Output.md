# Input and Output in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Variables
- Data Types
- Character Encoding
- Constants & Literals

---

# Introduction

Programs interact with the outside world through **Input** and **Output (I/O)**.

- **Input** → Taking data from the user or another source.
- **Output** → Displaying data to the user or another destination.

Examples:

```
Keyboard  → Input

Monitor   → Output

File      → Input / Output
```

In C++, standard input and output are performed using **Streams**.

---

# Header File

To use standard input and output, include:

```cpp
#include <iostream>
```

Most I/O objects belong to the `std` namespace.

Example:

```cpp
#include <iostream>

using namespace std;
```

or

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello";
}
```

---

# What is a Stream?

A **Stream** is a flow of data between a program and an input/output device.

```
Keyboard
    │
    ▼
 Input Stream
    │
 Program
    │
 Output Stream
    ▼
Monitor
```

We'll study streams in detail in the next chapter.

---

# Standard Input and Output Objects

| Object | Purpose |
|---------|---------|
| `cin` | Standard Input |
| `cout` | Standard Output |
| `cerr` | Standard Error |
| `clog` | Standard Logging |

In this chapter, we'll focus on **cin** and **cout**.

---

# Output using cout

`cout` is used to display data on the screen.

Syntax:

```cpp
cout << data;
```

Example:

```cpp
cout << "Hello World";
```

Output:

```
Hello World
```

---

# Output Multiple Values

The insertion operator (`<<`) can be chained.

Example:

```cpp
int age = 20;

cout << "Age = " << age;
```

Output:

```
Age = 20
```

Another example:

```cpp
cout << "A = " << 10 << " B = " << 20;
```

Output:

```
A = 10 B = 20
```

---

# Insertion Operator (<<)

The symbol

```cpp
<<
```

is called the **Insertion Operator**.

It inserts data into the output stream.

Example:

```cpp
cout << 10;
```

---

# New Line

There are two common ways to move to the next line.

## Using '\n'

```cpp
cout << "Hello\n";
cout << "World";
```

Output:

```
Hello
World
```

---

## Using endl

```cpp
cout << "Hello" << endl;
cout << "World";
```

Output:

```
Hello
World
```

---

# '\n' vs endl

Both move the cursor to the next line.

Difference:

| `\n` | `endl` |
|------|---------|
| New line only | New line + Flushes buffer |
| Faster | Slightly slower |
| Preferred in Competitive Programming | Useful when immediate output is required |

For most programs,

prefer

```cpp
'\n'
```

unless flushing is required.

---

# Input using cin

`cin` is used to take input from the user.

Syntax:

```cpp
cin >> variable;
```

Example:

```cpp
int age;

cin >> age;
```

Input:

```
20
```

Now,

```
age = 20
```

---

# Extraction Operator (>>)

The symbol

```cpp
>>
```

is called the **Extraction Operator**.

It extracts data from the input stream.

Example:

```cpp
cin >> age;
```

---

# Taking Multiple Inputs

Example:

```cpp
int a, b;

cin >> a >> b;
```

Input:

```
5 10
```

Values:

```
a = 5

b = 10
```

---

# How cin Works

By default,

`cin`

automatically ignores leading whitespace.

It stops reading when it encounters:

- Space
- Tab
- Newline
- Carriage Return

Example:

```cpp
string name;

cin >> name;
```

Input:

```
Naman Mishra
```

Stored:

```
Naman
```

Only the first word is stored.

---

# Reading Full Lines

To read an entire line including spaces, use

```cpp
getline()
```

Syntax:

```cpp
getline(cin, variable);
```

Example:

```cpp
string name;

getline(cin, name);
```

Input:

```
Naman Mishra
```

Stored:

```
Naman Mishra
```

---

# cin and getline() Problem

Consider:

```cpp
int age;

string name;

cin >> age;

getline(cin, name);
```

Input:

```
20
Naman Mishra
```

The second input is skipped.

---

# Why Does This Happen?

After reading

```
20
```

`cin` leaves the newline character

```
'\n'
```

inside the input buffer.

Then

```cpp
getline()
```

immediately reads that newline and finishes without waiting for user input.

---

# Solution

Remove the leftover newline before calling `getline()`.

Example:

```cpp
cin >> age;

cin.ignore();

getline(cin, name);
```

Now,

`getline()` works correctly.

---

# Input Buffer

Whenever the user types input,

it is first stored temporarily in an **Input Buffer**.

```
Keyboard

↓

Input Buffer

↓

cin

↓

Variable
```

Functions like

```cpp
cin.ignore()
```

help manage this buffer.

---

# Fast Input and Output

For programs with very large input/output (especially Competitive Programming), C++ provides faster I/O.

```cpp
ios::sync_with_stdio(false);

cin.tie(nullptr);
```

Always place these lines at the beginning of `main()`.

Example:

```cpp
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ...
}
```

---

# Why is Fast I/O Faster?

Normally,

C++ streams synchronize with C streams.

Disabling synchronization reduces overhead.

Also,

```cpp
cin.tie(nullptr);
```

prevents `cin` from automatically flushing `cout` before every input operation.

This improves performance.

---

# Output Formatting

The header

```cpp
#include <iomanip>
```

provides formatting utilities.

Example:

```cpp
#include <iomanip>

double pi = 3.14159265;

cout << fixed << setprecision(2) << pi;
```

Output:

```
3.14
```

---

# fixed

Displays floating-point numbers in normal decimal notation.

Example:

```cpp
cout << fixed << 3.14159265;
```

Output:

```
3.141593
```

---

# scientific

Displays floating-point numbers in scientific notation.

Example:

```cpp
cout << scientific << 32500.0;
```

Output:

```
3.250000e+04
```

---

# setprecision()

Controls floating-point precision.

Example:

```cpp
cout << setprecision(4);
```

Meaning depends on whether `fixed` is used.

Without `fixed`:

```
Total significant digits
```

With `fixed`:

```
Digits after decimal point
```

---

# Common Beginner Mistakes

### Forgetting `<<`

Wrong:

```cpp
cout "Hello";
```

Correct:

```cpp
cout << "Hello";
```

---

### Forgetting `>>`

Wrong:

```cpp
cin age;
```

Correct:

```cpp
cin >> age;
```

---

### Using getline() after cin

Wrong:

```cpp
cin >> age;

getline(cin, name);
```

Correct:

```cpp
cin >> age;

cin.ignore();

getline(cin, name);
```

---

### Using endl unnecessarily

Instead of

```cpp
cout << endl;
```

prefer

```cpp
cout << '\n';
```

unless immediate flushing is needed.

---

# Best Practices

- Use `'\n'` instead of `endl` unless flushing is required.
- Use `getline()` when reading complete lines.
- Always call `cin.ignore()` before `getline()` if `cin` was used previously.
- Enable Fast I/O only when handling large amounts of input/output.
- Keep prompts meaningful.

---

# Important Points

- `cin` performs input.
- `cout` performs output.
- `<<` is the insertion operator.
- `>>` is the extraction operator.
- `getline()` reads complete lines.
- `cin` stops reading at whitespace.
- `cin.ignore()` removes leftover characters from the input buffer.
- `'\n'` is generally faster than `endl`.
- `setprecision()`, `fixed`, and `scientific` help format floating-point output.

---

# Summary

- C++ performs standard input and output using streams.
- `cin` reads data, while `cout` displays it.
- `getline()` is used when input contains spaces.
- Understanding buffering and formatting helps write efficient and user-friendly programs.
- The next chapter explores **Streams** in detail, including `cerr`, `clog`, buffering, and stream internals.

---

## What's Next?

**Next Chapter:** Streams

You'll learn:

- What streams really are
- Input and Output stream hierarchy
- `cin`, `cout`, `cerr`, `clog`
- Buffered vs Unbuffered streams
- Error handling streams
- Logging streams
- Stream buffering
