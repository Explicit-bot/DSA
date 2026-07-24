# Variables in C++

A **variable** is a named memory location used to store data.

When a program runs, memory (RAM) is allocated to store data. A variable provides a meaningful name to that memory location so that we can access and modify its value.

Example:

```cpp
int age = 20;
```

Here,

- `int` → Datatype
- `age` → Variable Name (Identifier)
- `=` → Assignment Operator
- `20` → Value

Meaning:

> Create a memory location capable of storing an integer, name it **age**, and store the value **20**.

---

# What Happens Internally?

When the compiler sees:

```cpp
int age = 20;
```

It performs the following steps:

1. Checks whether the datatype is valid.
2. Allocates memory.
3. Associates the variable name with that memory.
4. Stores the binary representation of the value.

---

# Identifier

An **Identifier** is the name given to a program entity.

Examples:

- Variable
- Function
- Class
- Structure
- Array
- Namespace

Example:

```cpp
int marks = 95;
```

Here,

```
marks
```

is an identifier.

---

# Rules for Naming Variables

A variable name:

- Can contain alphabets (`A-Z`, `a-z`)
- Can contain digits (`0-9`)
- Can contain underscore (`_`)
- Cannot begin with a digit
- Cannot contain spaces
- Cannot contain special characters except `_`
- Cannot be a C++ keyword
- Is case-sensitive

Valid:

```cpp
age
studentName
_marks
roll123
```

Invalid:

```cpp
2age
student-name
my age
class
```

---

# Keywords

Keywords are reserved words that already have a predefined meaning in C++.

Examples:

```cpp
int
float
return
while
if
class
public
private
```

Invalid:

```cpp
int while = 10;
```

---

# Declaration

Declaration creates a variable.

Syntax:

```cpp
datatype variableName;
```

Example:

```cpp
int age;
```

Memory is allocated, but no value is assigned.

---

# Initialization

Initialization means assigning the **first value** during declaration.

Example:

```cpp
int age = 20;
```

---

# Assignment

Assignment means changing the value **after** the variable has been created.

Example:

```cpp
int age = 20;

age = 25;
```

Now,

```
age = 25
```

---

# Declaration vs Initialization vs Assignment

```cpp
int x;      // Declaration

int y = 10; // Initialization

x = 50;     // Assignment
```

---

# Declaration vs Definition

A **Declaration** tells the compiler that a variable exists.

A **Definition** actually allocates memory.

Example:

```cpp
extern int x;      // Declaration

int x = 10;        // Definition
```

Usually both happen together.

```cpp
int x;
```

---

# Types of Initialization

## 1. Copy Initialization

```cpp
int x = 10;
```

Looks like copying the value.

---

## 2. Direct Initialization

```cpp
int x(10);
```

Uses parentheses.

---

## 3. Brace Initialization (Uniform Initialization)

```cpp
int x{10};
```

or

```cpp
int x = {10};
```

This is the preferred initialization style in Modern C++.

---

# Why Brace Initialization?

Brace initialization prevents **Narrowing Conversion**.

Example:

```cpp
int x{3.5};
```

Compiler Error.

Because storing `3.5` in an integer loses data.

Whereas,

```cpp
int x = 3.5;
```

is allowed.

Stored value:

```
3
```

---

# Narrowing Conversion

Converting a larger or more precise datatype into a smaller datatype that may lose information.

Examples:

```cpp
double → int

double → float

long long → int
```

---

# Default Initialization

```cpp
int x;
```

Local variables are **not initialized automatically**.

Their value is unpredictable.

Such values are called **Garbage Values**.

Example:

```cpp
int x;

cout << x;
```

Output may be anything.

---

# Garbage Value

A garbage value is the random value present inside an uninitialized local variable.

Never rely on it.

Always initialize variables before use.

---

# Value Initialization

```cpp
int x{};
```

Automatically initializes the variable.

Examples:

| Datatype | Default Value |
|----------|---------------|
| int | 0 |
| float | 0.0 |
| double | 0.0 |
| bool | false |
| char | '\0' |

---

# Initialization Summary

```cpp
int a = 10;      // Copy Initialization

int b(10);       // Direct Initialization

int c{10};       // Brace Initialization

int d = {10};    // Brace Copy Initialization

int e;           // Default Initialization

int f{};         // Value Initialization
```

---

# Dynamic Initialization

Variables can also be initialized using expressions.

Example:

```cpp
int a = 10;

int b = a + 5;
```

The value depends on runtime calculations.

---

# auto Keyword

Modern C++ allows the compiler to determine the datatype automatically.

Example:

```cpp
auto x = 10;

auto pi = 3.14159;

auto ch = 'A';
```

Compiler deduces:

```
x  → int

pi → double

ch → char
```

---

# Constants

Sometimes a value should never change.

Use:

```cpp
const
```

Example:

```cpp
const double PI = 3.1415926535;
```

Trying to modify it:

```cpp
PI = 4;
```

Produces a compilation error.

---

# Variable Address

Every variable has a unique memory address.

Example:

```cpp
int age = 20;

cout << &age;
```

The address operator (`&`) returns the memory location of the variable.

Pointers will use these addresses later.

---

# Best Practices

- Always initialize variables.
- Prefer brace initialization `{}`.
- Use meaningful variable names.
- Keep variable names descriptive.
- Avoid single-letter names except in loops.
- Declare variables as close as possible to where they are used.
- Use `const` whenever a value should not change.
- Prefer `auto` only when the type is obvious.

---
