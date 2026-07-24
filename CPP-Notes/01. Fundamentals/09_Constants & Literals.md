# Constants and Literals in C++

---

# Introduction

Programs often work with values that **should never change**, such as:

- Value of π
- Speed of light
- Number of days in a week

These values are called **Constants**.

Similarly, values written directly in code are called **Literals**.

Example:

```cpp
const double PI = 3.141592653589793;

int age = 20;
```

Here,

- `PI` is a constant.
- `20` is an integer literal.

---

# Constant

A **Constant** is a value that **cannot be modified** after it has been initialized.

Example:

```cpp
const int MAX_STUDENTS = 60;
```

Trying to modify it:

```cpp
MAX_STUDENTS = 100;
```

Produces a compilation error.

---

# Why Use Constants?

Constants make programs:

- Safer
- Easier to understand
- Easier to maintain

Instead of writing

```cpp
double area = 3.141592653589793 * r * r;
```

write

```cpp
const double PI = 3.141592653589793;

double area = PI * r * r;
```

If the value ever changes, only one place needs to be updated.

---

# const Keyword

The `const` keyword makes an object read-only.

Syntax:

```cpp
const datatype variable = value;
```

Example:

```cpp
const int MAX = 100;

const double PI = 3.14159;

const char GRADE = 'A';
```

---

# Rules

A const variable **must be initialized**.

Correct:

```cpp
const int x = 10;
```

Incorrect:

```cpp
const int x;
```

This results in a compilation error because a constant must have a value when it is created.

---

# Constant Variables

```cpp
const int DAYS = 7;

const float PI = 3.14f;

const bool DEBUG = false;
```

These values cannot be modified later.

---

# Compile-Time Constants

Some constants are known during compilation.

Example:

```cpp
const int SIZE = 100;
```

Compiler knows the value before the program starts.

---

# constexpr (Modern C++)

`constexpr` was introduced in **C++11**.

It creates constants that are guaranteed to be known at compile time.

Example:

```cpp
constexpr int SIZE = 100;
```

Unlike `const`, a `constexpr` variable **must** be initialized with a compile-time expression.

---

# const vs constexpr

| const | constexpr |
|--------|-----------|
| Read-only variable | Compile-time constant |
| May be evaluated at runtime | Must be evaluated at compile time |
| Introduced in C++98 | Introduced in C++11 |

Example:

```cpp
const int a = 10;

constexpr int b = 20;
```

---

# What is a Literal?

A **Literal** is a fixed value written directly in the source code.

Example:

```cpp
10

3.14

'A'

"Hello"

true
```

All of these are literals.

---

# Types of Literals

C++ provides several types of literals.

```
Literals
│
├── Integer
├── Floating Point
├── Character
├── String
├── Boolean
├── Null Pointer
└── User Defined (Advanced)
```

---

# Integer Literals

Represents whole numbers.

Examples:

```cpp
10

100

-25

0
```

Default datatype:

```
int
```

---

# Integer Bases

## Decimal

Base 10

```cpp
25
```

---

## Octal

Starts with

```
0
```

Example:

```cpp
025
```

---

## Hexadecimal

Starts with

```
0x
```

Example:

```cpp
0x2A
```

---

## Binary (C++14)

Starts with

```
0b
```

Example:

```cpp
0b1010
```

---

# Floating-Point Literals

Represents decimal numbers.

Examples:

```cpp
3.14

15.5

0.25

2E5
```

Default datatype:

```
double
```

---

# Float Literal

To create a float literal, use

```
f
```

or

```
F
```

Example:

```cpp
3.14f
```

Datatype:

```
float
```

---

# Long Double Literal

Use

```
L
```

Example:

```cpp
3.141592653589793L
```

Datatype:

```
long double
```

---

# Character Literals

Represents a single character.

Written inside **single quotes**.

Examples:

```cpp
'A'

'B'

'7'

'#'
```

Datatype:

```
char
```

---

# Wide Character Literals

Examples:

```cpp
L'A'

u'₹'

U'😀'
```

Prefixes:

```
L

u

U
```

---

# String Literals

Represents text.

Written inside **double quotes**.

Examples:

```cpp
"Hello"

"C++"

"Naman"
```

Important:

A string literal is **not** a `std::string`.

Its type is

```cpp
const char[]
```

---

# Boolean Literals

Only two values exist.

```cpp
true

false
```

Datatype:

```
bool
```

---

# Null Pointer Literal

Modern C++ uses

```cpp
nullptr
```

to represent a null pointer.

Example:

```cpp
int* ptr = nullptr;
```

Preferred over

```cpp
NULL

0
```

---

# Escape Sequences

Escape sequences represent special characters inside character and string literals.

| Escape | Meaning |
|---------|---------|
| `\n` | New Line |
| `\t` | Horizontal Tab |
| `\\` | Backslash |
| `\"` | Double Quote |
| `\'` | Single Quote |
| `\0` | Null Character |
| `\r` | Carriage Return |
| `\b` | Backspace |

Example:

```cpp
cout << "Hello\nWorld";
```

Output:

```
Hello
World
```

---

# Raw String Literals (C++11)

Normally,

```cpp
"C:\\Users\\Naman"
```

requires escaping.

Raw strings ignore escape sequences.

Example:

```cpp
R"(C:\Users\Naman)"
```

Useful when writing:

- File paths
- Regular expressions
- JSON
- SQL queries

---

# Literal Suffixes

| Suffix | Datatype |
|---------|----------|
| `u` | unsigned |
| `l` | long |
| `ll` | long long |
| `f` | float |
| `L` | long double |
| `u8` | UTF-8 string |
| `U` | char32_t |
| `u` | char16_t |

Examples:

```cpp
10U

10L

10LL

3.14f

3.14L
```

---

# Magic Numbers

A **Magic Number** is a literal written directly into the code without explanation.

Example:

```cpp
if(age >= 18)
```

Here,

```
18
```

is a magic number.

Better:

```cpp
const int VOTING_AGE = 18;

if(age >= VOTING_AGE)
```

Programs become easier to understand and maintain.

---

# Best Practices

- Use `const` whenever a value should not change.
- Prefer `constexpr` for compile-time constants.
- Avoid magic numbers.
- Use meaningful names for constants.
- Prefer `nullptr` instead of `NULL`.
- Use raw string literals for file paths and regular expressions.

---

# Important Points

- Constants cannot be modified after initialization.
- `const` creates read-only variables.
- `constexpr` creates compile-time constants.
- Literals are fixed values written directly in code.
- Integer literals are `int` by default.
- Decimal literals are `double` by default.
- String literals are stored as `const char[]`.
- Escape sequences represent special characters.
- `nullptr` is the modern null pointer literal.

---

# Summary

- Constants improve readability, maintainability, and program safety.
- Literals represent fixed values directly written into the source code.
- C++ supports integer, floating-point, character, string, boolean, and null pointer literals.
- Modern C++ encourages using `constexpr`, `nullptr`, and named constants instead of magic numbers.
