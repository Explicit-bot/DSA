# Variable Scope and Lifetime in C++

---

# Introduction

Every variable in a program has two important properties:

1. **Scope**
2. **Lifetime (Storage Duration)**

Understanding these concepts is essential because they determine:

- Where a variable can be accessed.
- How long a variable exists in memory.

---

# Scope

**Scope** defines **where a variable can be accessed** within a program.

If a variable is outside its scope, it cannot be used.

Example:

```cpp
int main()
{
    int age = 20;

    cout << age;      // ✔ Accessible
}
```

```cpp
cout << age;          // ❌ Error
```

`age` exists only inside `main()`.

---

# Types of Scope

C++ provides the following scopes:

```
Scope
│
├── Local Scope
├── Block Scope
├── Global Scope
├── Function Scope
├── Class Scope
└── Namespace Scope
```

---

# 1. Local Scope

Variables declared inside a function belong to the **Local Scope**.

They can only be accessed inside that function.

Example:

```cpp
void display()
{
    int x = 10;

    cout << x;
}
```

Outside the function:

```cpp
cout << x;
```

Produces an error because `x` is local to `display()`.

---

# Local Variable

A variable declared inside a function is called a **Local Variable**.

Example:

```cpp
int main()
{
    int marks = 90;
}
```

`marks` exists only inside `main()`.

---

# 2. Block Scope

A **Block** is any code enclosed within `{}`.

Variables declared inside a block exist only inside that block.

Example:

```cpp
if(true)
{
    int x = 10;

    cout << x;
}
```

Outside the block:

```cpp
cout << x;
```

Produces a compilation error.

---

# Block Scope Example

```cpp
for(int i = 0; i < 5; i++)
{
    int square = i * i;

    cout << square;
}
```

Both

```
i

square
```

exist only inside the loop.

---

# Nested Blocks

Blocks may exist inside other blocks.

Example:

```cpp
int x = 100;

{
    int y = 50;

    {
        int z = 20;
    }
}
```

Accessibility:

```
x → Everywhere below its declaration

y → Only inside outer block

z → Only inside inner block
```

---

# 3. Global Scope

Variables declared outside every function belong to the **Global Scope**.

Example:

```cpp
int score = 100;

int main()
{
    cout << score;
}
```

Global variables can be accessed from any function (unless hidden).

---

# Global Variable

```cpp
int count = 0;

void display()
{
    cout << count;
}

int main()
{
    cout << count;
}
```

Both functions can access the same variable.

---

# Local vs Global Variable

```cpp
int x = 100;

int main()
{
    int x = 10;

    cout << x;
}
```

Output:

```
10
```

The local variable hides the global variable.

---

# Scope Resolution Operator (::)

The global variable can still be accessed using the **Scope Resolution Operator**.

Example:

```cpp
int x = 100;

int main()
{
    int x = 10;

    cout << x;      // 10

    cout << ::x;    // 100
}
```

---

# 4. Function Scope

Labels used with `goto` have **Function Scope**.

Example:

```cpp
start:

cout << "Hello";
```

A label can be accessed anywhere inside the same function.

Function scope is mainly associated with labels and is rarely used in modern C++.

---

# 5. Class Scope

Members declared inside a class belong to the **Class Scope**.

Example:

```cpp
class Student
{
public:

    int roll;
};
```

Access:

```cpp
Student s;

s.roll = 10;
```

---

# 6. Namespace Scope

Variables declared inside a namespace belong to the **Namespace Scope**.

Example:

```cpp
namespace College
{
    int students = 500;
}
```

Access:

```cpp
cout << College::students;
```

---

# Variable Shadowing

Variable Shadowing occurs when a variable declared in an inner scope has the same name as a variable in an outer scope.

Example:

```cpp
int x = 100;

int main()
{
    int x = 50;

    {
        int x = 10;

        cout << x;
    }
}
```

Compiler always selects the nearest variable.

---

# Scope Lookup Order

The compiler searches variables in this order:

```
Current Block
        │
        ▼
Outer Block
        │
        ▼
Function
        │
        ▼
Global Scope
```

The nearest matching variable is used.

---

# Lifetime

Lifetime determines **how long a variable exists in memory**.

Even if a variable is out of scope, it may still exist temporarily depending on its storage duration.

---

# Local Variable Lifetime

Example:

```cpp
void display()
{
    int x = 10;
}
```

```
Function Starts
        │
        ▼
Variable Created
        │
        ▼
Function Ends
        │
        ▼
Variable Destroyed
```

---

# Global Variable Lifetime

Example:

```cpp
int count = 0;
```

```
Program Starts
        │
        ▼
Variable Created
        │
        ▼
Program Ends
        │
        ▼
Variable Destroyed
```

---

# Static Variable Lifetime

Example:

```cpp
void display()
{
    static int count = 0;

    count++;

    cout << count;
}
```

Although the variable is inside the function, it exists throughout the program.

Each function call continues using the previous value.

Output:

```
1

2

3

4
```

---

# Storage Duration

Storage duration defines how long memory remains allocated.

Main types:

| Storage Duration | Lifetime |
|------------------|----------|
| Automatic | Block execution |
| Static | Entire program |
| Thread Local | Lifetime of thread |
| Dynamic | Until `delete` |

---

# Automatic Storage

Default for local variables.

Example:

```cpp
int x = 10;
```

Destroyed automatically when the block ends.

---

# Static Storage

Used by:

- Global variables
- Static variables

Memory exists for the entire execution of the program.

---

# Dynamic Storage

Created using

```cpp
new
```

Example:

```cpp
int* ptr = new int;
```

Memory remains allocated until

```cpp
delete ptr;
```

---

# Thread Storage (Overview)

Introduced in C++11.

Each thread gets its own copy of the variable.

Example:

```cpp
thread_local int count = 0;
```

We'll study multithreading later.

---

# Scope vs Lifetime

These are different concepts.

Example:

```cpp
void display()
{
    static int x = 0;
}
```

Scope:

```
Inside display()
```

Lifetime:

```
Entire Program
```

A variable may have a small scope but a long lifetime.

---

# Summary Table

| Variable | Scope | Lifetime |
|----------|-------|----------|
| Local | Function / Block | Until block ends |
| Global | Entire program | Entire program |
| Static Local | Function | Entire program |
| Dynamic | Depends on pointer | Until `delete` |
| Namespace | Namespace | Entire program |

---

# Best Practices

- Keep variables in the smallest possible scope.
- Avoid unnecessary global variables.
- Use `static` only when persistence is required.
- Release dynamically allocated memory using `delete`.
- Use meaningful variable names to avoid shadowing.
- Minimize variable lifetime whenever possible.

---

# Important Points

- Scope determines **where** a variable can be accessed.
- Lifetime determines **how long** a variable exists.
- Local variables have automatic storage duration.
- Global and static variables exist throughout program execution.
- Variable shadowing hides variables from outer scopes.
- The scope resolution operator (`::`) accesses hidden global variables.
- Dynamic memory remains allocated until explicitly released.

---

# Summary

- Scope and lifetime are independent properties of a variable.
- Scope controls visibility, while lifetime controls existence.
- Understanding these concepts is essential for writing safe and maintainable C++ programs.
- These ideas become even more important when studying functions, pointers, classes, and dynamic memory management.
