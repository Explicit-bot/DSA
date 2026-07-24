# Type Conversion in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Variables
- Data Types
- Operators

---

# Introduction

A program often needs to convert one data type into another.

Examples:

- `int` → `double`
- `double` → `int`
- `char` → `int`

This process is called **Type Conversion**.

Example:

```cpp
int x = 10;

double y = x;
```

Here,

```
10

↓

10.0
```

The integer is converted into a double.

---

# Types of Type Conversion

C++ supports two types of conversions.

```
Type Conversion
│
├── Implicit Conversion
│
└── Explicit Conversion (Type Casting)
```

---

# 1. Implicit Type Conversion

Also called:

- Automatic Conversion
- Implicit Casting

The compiler automatically converts one datatype into another whenever required.

Example:

```cpp
int num = 10;

double value = num;
```

Output:

```
10.0
```

The compiler performs the conversion automatically.

---

# Why Does Implicit Conversion Exist?

Without implicit conversion,

operations involving different datatypes would become difficult.

Example:

```cpp
int a = 5;

double b = 2.5;

double c = a + b;
```

Internally,

```
5

↓

5.0
```

Then,

```
5.0 + 2.5

↓

7.5
```

---

# Widening Conversion

A **Widening Conversion** converts a smaller datatype into a larger datatype.

Usually,

no information is lost.

Examples:

```
char

↓

int

↓

long

↓

long long

↓

float

↓

double
```

---

## Example

```cpp
int x = 25;

double y = x;
```

Result:

```
25

↓

25.0
```

No data loss occurs.

---

# Examples of Widening Conversion

```cpp
char → int

int → long long

float → double

int → double
```

---

# Narrowing Conversion

A **Narrowing Conversion** converts a larger datatype into a smaller datatype.

This may cause:

- Data Loss
- Precision Loss
- Overflow
- Truncation

---

## Example

```cpp
double pi = 3.14159;

int x = pi;
```

Stored value:

```
3
```

The fractional part is lost.

---

# Precision Loss

Example:

```cpp
double x = 3.141592653589793;

float y = x;
```

Some decimal digits are lost because `float` has lower precision.

---

# Truncation

When converting a floating-point number to an integer,

the fractional part is discarded.

Examples:

```
3.99

↓

3
```

```
-8.75

↓

-8
```

This process is called **Truncation**.

---

# Overflow During Conversion

Example:

```cpp
int x = 300;

char ch = x;
```

Typical range of `char`:

```
-128

↓

127
```

Since

```
300
```

cannot fit,

overflow occurs and the stored value becomes implementation-dependent.

---

# Arithmetic Conversion

When different datatypes appear in the same expression,

C++ converts them to a common type before performing the operation.

Examples:

```
int + double

↓

double
```

```
char + int

↓

int
```

```
float + double

↓

double
```

---

# Integer Promotion

Smaller integer types are automatically promoted to `int` during arithmetic.

Example:

```cpp
char a = 10;

char b = 20;

cout << a + b;
```

Internally:

```
char

↓

int
```

Result datatype:

```
int
```

---

# Common Arithmetic Conversions

| Expression | Result |
|------------|--------|
| int + int | int |
| int + double | double |
| int + float | float |
| float + double | double |
| char + int | int |

---

# Explicit Type Conversion

Also called:

- Type Casting
- Explicit Casting

The programmer manually converts one datatype into another.

---

# Why Do We Need Explicit Casting?

Example:

```cpp
int a = 5;

int b = 2;

cout << a / b;
```

Output:

```
2
```

Because integer division occurs.

---

## Correct Version

```cpp
cout << (double)a / b;
```

Now,

```
5.0 / 2

↓

2.5
```

---

# Types of Explicit Casting

```
Explicit Casting
│
├── C-style Cast
├── Function-style Cast
└── Named Casts
      │
      ├── static_cast
      ├── dynamic_cast
      ├── const_cast
      └── reinterpret_cast
```

---

# C-style Cast

Old C language syntax.

Syntax:

```cpp
(type) expression
```

Example:

```cpp
double x = 3.14;

int y = (int)x;
```

Output:

```
3
```

---

# Function-style Cast

Looks like a function call.

Syntax:

```cpp
type(expression)
```

Example:

```cpp
double x = 3.14;

int y = int(x);
```

Produces the same result as a C-style cast.

---

# Problems with Old Casts

Old casts are:

- Less readable
- Less safe
- Harder to debug
- Allow dangerous conversions

Example:

```cpp
int x = 65;

char* ptr = (char*)x;
```

This compiles but is unsafe and may crash the program.

Modern C++ prefers **named casts**.

---

# static_cast

Used for safe compile-time conversions.

Syntax:

```cpp
static_cast<type>(expression)
```

Example:

```cpp
double x = 3.14;

int y = static_cast<int>(x);
```

Output:

```
3
```

Preferred for:

- Numeric conversions
- Related pointer conversions
- Enum conversions

---

# Why Prefer static_cast?

Compared to C-style casts,

`static_cast`

- Is more readable
- Is compiler checked
- Prevents many accidental conversions

Modern C++ recommends using `static_cast` whenever possible.

---

# dynamic_cast

Used with **Inheritance** and **Polymorphism**.

Performs safe runtime casting.

Example:

```cpp
Base* b = new Derived;

Derived* d = dynamic_cast<Derived*>(b);
```

If the conversion is invalid,

the result becomes:

```
nullptr
```

for pointers.

We'll study this in the OOP section.

---

# const_cast

Used to add or remove the `const` qualifier.

Example:

```cpp
const int x = 10;

int* p = const_cast<int*>(&x);
```

Be careful:

Modifying a truly constant object results in **Undefined Behavior**.

---

# reinterpret_cast

The lowest-level cast in C++.

It reinterprets raw memory without changing the actual bits.

Example:

```cpp
int x = 65;

char* p = reinterpret_cast<char*>(&x);
```

Used in:

- System Programming
- Embedded Systems
- Operating Systems
- Low-Level Memory Manipulation

Should be avoided unless absolutely necessary.

---

# Conversion Summary

| Conversion | Safe? | Recommended |
|------------|------|-------------|
| Implicit | Usually | ✔ |
| C-style Cast | No | ✖ |
| Function-style Cast | No | ✖ |
| static_cast | Yes | ✔ |
| dynamic_cast | Runtime Checked | ✔ |
| const_cast | Special Purpose | Use Carefully |
| reinterpret_cast | Dangerous | Avoid |

---

# Best Practices

- Prefer implicit conversion when no information is lost.
- Avoid unnecessary narrowing conversions.
- Prefer `static_cast` over C-style casts.
- Avoid `reinterpret_cast` unless working with low-level code.
- Be careful when removing `const`.
- Never assume conversions are always safe.

---

# Important Points

- Type Conversion changes one datatype into another.
- Implicit conversion is performed automatically by the compiler.
- Widening conversions are usually safe.
- Narrowing conversions may lose data.
- Integer promotion occurs automatically during arithmetic.
- Explicit conversion is performed by the programmer.
- `static_cast` is the preferred casting method in Modern C++.
- `dynamic_cast`, `const_cast`, and `reinterpret_cast` serve specialized purposes.

---

# Summary

- Type conversion allows different datatypes to work together.
- C++ performs many conversions automatically, but programmers can also force conversions using type casting.
- Modern C++ recommends using named casts because they are safer, more readable, and easier to maintain.
- Understanding type conversion is important for arithmetic operations, function calls, pointers, inheritance, and many advanced C++ concepts.

---

## What's Next?

**Next Chapter:** Operators

You'll learn:

- Arithmetic Operators
- Assignment Operators
- Relational Operators
- Logical Operators
- Bitwise Operators
- Ternary Operator
- Operator Precedence
- Operator Associativity
- Common Pitfalls
