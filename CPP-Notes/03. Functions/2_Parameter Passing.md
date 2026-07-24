# Parameter Passing in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Functions
- Variables
- References (basic idea)

---

# Introduction

Whenever a function is called, values must be passed from the caller to the function.

This process is called **Parameter Passing**.

Example

```cpp
add(10, 20);
```

Here,

```
10

20
```

are passed to the function.

---

# Types of Parameter Passing

```
Parameter Passing
│
├── Pass by Value
├── Pass by Reference
└── Pass by Address
```

Each method behaves differently.

---

# 1. Pass by Value

A **copy** of the argument is passed to the function.

The original variable remains unchanged.

---

# Memory Diagram

```cpp
int x = 10;

fun(x);
```

```
Before Call

main()

x
+----+
| 10 |
+----+

↓

Function Call

fun()

a
+----+
| 10 |
+----+
```

Notice:

```
x

and

a
```

are different variables.

---

# Example

```cpp
void increment(int x)
{
    x++;
}

int main()
{
    int a = 10;

    increment(a);

    cout << a;
}
```

Output

```
10
```

The original variable is unchanged.

---

# Advantages

- Safe
- Original data cannot be modified
- Simple to understand

---

# Disadvantages

- Copies data.
- Large objects become expensive to copy.

---

# 2. Pass by Reference

Instead of copying,

the function receives another name (alias) for the original variable.

---

# Syntax

```cpp
void increment(int& x)
```

Notice the

```
&
```

---

# Memory Diagram

```cpp
int a = 10;

increment(a);
```

```
main()

a
+----+
| 10 |
+----+
   ▲
   │
Reference
   │
   ▼

x
```

Both names refer to the same memory.

---

# Example

```cpp
void increment(int& x)
{
    x++;
}

int main()
{
    int a = 10;

    increment(a);

    cout << a;
}
```

Output

```
11
```

---

# Advantages

- No copying.
- Faster.
- Original variable can be modified.

---

# Disadvantages

- Function can accidentally modify data.

---

# const Reference

Sometimes we want the efficiency of references without allowing modification.

Syntax

```cpp
void print(const string& name)
```

Example

```cpp
void print(const string& name)
{
    cout << name;
}
```

Advantages

- No copying.
- Cannot modify original object.
- Preferred for large objects.

Modern C++ recommends passing large objects using **const references**.

---

# 3. Pass by Address

Instead of passing the variable,

its memory address is passed.

Syntax

```cpp
void increment(int* ptr)
```

---

# Memory Diagram

```
a
+----+
| 10 |
+----+
 ^
 |
ptr
```

---

# Example

```cpp
void increment(int* ptr)
{
    (*ptr)++;
}

int main()
{
    int a = 10;

    increment(&a);

    cout << a;
}
```

Output

```
11
```

---

# Why Use Pointers?

Pointers allow:

- Modifying original data.
- Working with dynamic memory.
- Optional parameters (`nullptr`).
- Low-level programming.

We'll study pointers in detail later.

---

# Comparison

| Method | Copy | Original Changes |
|---------|------|------------------|
| Pass by Value | ✔ | ❌ |
| Pass by Reference | ❌ | ✔ |
| Pass by Address | ❌ | ✔ |

---

# Which Should You Use?

### Small Data Types

Examples

```cpp
int

char

bool

double
```

Use

```
Pass by Value
```

Copying them is inexpensive.

---

### Large Objects

Examples

```cpp
string

vector

class
```

Use

```
const Reference
```

to avoid unnecessary copying.

---

### Need to Modify Original Data

Use

```
Reference

or

Pointer
```

depending on the situation.

---

# Common Mistakes

## Expecting Pass by Value to Modify Data

Wrong

```cpp
void fun(int x)
{
    x++;
}
```

The original variable never changes.

---

## Forgetting *

Wrong

```cpp
ptr++;
```

Correct

```cpp
(*ptr)++;
```

---

## Modifying const Reference

Wrong

```cpp
void print(const string& s)
{
    s = "Hello";
}
```

Compilation Error.

---

# Best Practices

- Pass small fundamental types by value.
- Pass large objects by const reference.
- Use references when modification is required.
- Use pointers when nullability or dynamic memory is needed.

---

# Important Points

- Pass by Value creates a copy.
- Pass by Reference creates an alias.
- Pass by Address passes a memory address.
- References avoid unnecessary copying.
- const references provide efficiency and safety.
- Parameter passing directly affects program performance.

---

# Summary

- C++ provides multiple ways to pass data to functions.
- Each method has different performance and behavior.
- Choosing the correct parameter passing technique leads to safer, faster, and more maintainable programs.
- Modern C++ commonly uses **Pass by Value** for small types and **const Pass by Reference** for larger objects.

---

## What's Next?

**Next Chapter:** Default Arguments

You'll learn:

- Default Parameters
- Rules
- Evaluation
- Ambiguity
- Best Practices
