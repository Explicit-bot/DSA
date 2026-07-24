# Data Types in C++

---

# What is a Data Type?

A **Data Type** specifies:

- What kind of data a variable can store.
- How much memory should be allocated.
- The range of values that can be stored.
- The operations that can be performed on the data.

Example:

```cpp
int age = 20;
```

Here,

- `int` tells the compiler that the variable stores an integer.

---

# Why Do We Need Data Types?

Computers store everything as **binary (0s and 1s)**.

The compiler must know:

- How many bytes to allocate.
- How to interpret those bits.
- What operations are allowed.

For example:

```cpp
int x = 10;
```

needs different memory than

```cpp
char ch = 'A';
```

---

# Classification of Data Types

```
Data Types
│
├── Fundamental (Built-in)
│   ├── Integer
│   ├── Character
│   ├── Floating Point
│   ├── Boolean
│   └── Void
│
├── Derived
│   ├── Array
│   ├── Pointer
│   ├── Reference
│   ├── Function
│   └── std::string
│
└── User Defined
    ├── struct
    ├── class
    ├── union
    ├── enum
    ├── typedef
    └── using
```

---

# 1. Fundamental (Built-in) Data Types

These are predefined by the C++ language.

---

# Integer Type

Used to store **whole numbers**.

Examples:

```cpp
int age = 20;

int temperature = -5;
```

Typical Size:

```
4 Bytes
```

Typical Range:

```
-2,147,483,648

to

2,147,483,647
```

---

# Character Type

Used to store **a single character**.

Example:

```cpp
char grade = 'A';
```

Characters are always enclosed in **single quotes**.

```
'A'

'B'

'7'

'#'
```

Typical Size:

```
1 Byte
```

---

# How Characters are Stored

Characters are stored internally using their **ASCII values**.

Example:

| Character | ASCII |
|-----------|------:|
| A | 65 |
| B | 66 |
| a | 97 |
| z | 122 |
| 0 | 48 |
| 9 | 57 |

Example:

```cpp
char ch = 'A';
```

Internally stores:

```
65
```

---

# Character Data Types

## char

Stores regular characters.

```cpp
char ch = 'A';
```

---

## wchar_t

Wide character type.

Example:

```cpp
wchar_t ch = L'अ';
```

Prefix:

```
L
```

---

## char16_t

Stores UTF-16 characters.

```cpp
char16_t ch = u'ह';
```

Prefix:

```
u
```

---

## char32_t

Stores UTF-32 characters.

```cpp
char32_t ch = U'😀';
```

Prefix:

```
U
```

---

# Floating Point Types

Used to store decimal numbers.

Examples:

```cpp
float price = 10.5f;

double pi = 3.1415926535;
```

---

## float

Typical Size:

```
4 Bytes
```

Precision:

```
Approximately 6–7 decimal digits
```

---

## double

Typical Size:

```
8 Bytes
```

Precision:

```
Approximately 15–16 decimal digits
```

---

# Why Prefer double?

Example:

```cpp
float x = 3.1415926535f;
```

Stores approximately:

```
3.14159
```

Whereas,

```cpp
double y = 3.1415926535;
```

stores much higher precision.

Unless memory is critical,

**prefer `double` over `float`.**

---

# Float Suffix

Floating-point literals are treated as `double` by default.

Example:

```cpp
3.14
```

is

```
double
```

To create a float literal:

```cpp
3.14f
```

or

```cpp
3.14F
```

---

# Scientific Notation

Floating-point numbers may also be written in exponential form.

Examples:

```cpp
double x = 5E3;
```

means

```
5 × 10³
```

```cpp
double y = 5E-3;
```

means

```
5 × 10⁻³
```

---

# Boolean Type

Used to store logical values.

Possible values:

```cpp
true

false
```

Example:

```cpp
bool isPassed = true;
```

Typical Size:

```
1 Byte
```

Internally,

| Value | Stored As |
|--------|----------:|
| true | 1 |
| false | 0 |

---

# Void Type

`void` means

> No value

Commonly used in functions.

Example:

```cpp
void display()
{
    cout << "Hello";
}
```

The function returns nothing.

---

# 2. Derived Data Types

Derived data types are created using fundamental data types.

---

## Array

Stores multiple values of the same type.

Example:

```cpp
int arr[5] = {1,2,3,4,5};
```

Memory Layout:

```
+---+---+---+---+---+
| 1   | 2   | 3  | 4   | 5  |
+---+---+---+---+---+
```

Arrays store elements in **contiguous memory**.

---

## Pointer

Stores the **address** of another variable.

Example:

```cpp
int x = 10;

int* ptr = &x;
```

Pointers are heavily used in:

- Dynamic Memory
- Linked Lists
- Trees
- System Programming

Modern 64-bit systems generally use **8-byte pointers**.

---

## Reference

A reference is another name (alias) for an existing variable.

Example:

```cpp
int x = 10;

int& ref = x;
```

Changing one changes the other.

```cpp
ref = 50;

cout << x;
```

Output:

```
50
```

---

## Function

Functions are also considered derived data types.

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

---

## std::string

Used to store text.

Example:

```cpp
string name = "Naman";
```

Unlike character arrays, `std::string` automatically manages memory and provides many useful operations.

---

# 3. User Defined Data Types

These are created by programmers.

Main user-defined types:

- struct
- class
- union
- enum
- typedef
- using

---

# typedef

Creates an alias for an existing type.

Example:

```cpp
typedef unsigned long long ull;
```

Now,

```cpp
ull x;
```

is equivalent to

```cpp
unsigned long long x;
```

Used for readability.

---

# using

Modern C++ replacement for `typedef`.

Example:

```cpp
using ull = unsigned long long;
```

Preferred in Modern C++.

---

# enum

An enumeration assigns meaningful names to integral constants.

Example:

```cpp
enum Day
{
    Monday,
    Tuesday,
    Wednesday
};
```

Internally:

```
Monday    → 0

Tuesday   → 1

Wednesday → 2
```

Custom values are also allowed.

```cpp
enum Grade
{
    A = 1,
    B,
    C
};
```

---

# struct

Groups related data together.

Example:

```cpp
struct Student
{
    string name;
    int roll;
    float cgpa;
};
```

Members are **public by default**.

---

# class

Advanced version of `struct` used in Object-Oriented Programming.

Example:

```cpp
class Student
{
public:

    string name;

    void display()
    {

    }
};
```

Members are **private by default**.

---

# union

All members share the same memory.

Example:

```cpp
union Data
{
    int x;

    char ch;
};
```

Only one member should be used at a time.

Used for:

- Memory optimization
- Embedded Systems
- Hardware Programming

---

# Data Type Sizes

Data type sizes depend on:

- Compiler
- Operating System
- Architecture (32-bit / 64-bit)

Never assume sizes.



# sizeof Operator

Returns the size of a data type or variable.

Example:

```cpp
cout << sizeof(int);
```

---

# Strongly Typed Language

C++ is a **Strongly Typed Language**.

Every variable must have a data type.

The datatype determines:

- Memory Allocation
- Range
- Allowed Operations
- Performance

---
