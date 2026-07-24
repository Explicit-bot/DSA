# Functions in C++

---

# Introduction

A **Function** is a reusable block of code designed to perform a specific task.

Instead of writing the same code multiple times, we write it once inside a function and call it whenever needed.

---

# Why Do We Need Functions?

Suppose you need to calculate the sum of two numbers multiple times.

Without functions:

```cpp
int sum = a + b;
// ...

sum = x + y;
// ...

sum = p + q;
```

The same logic is repeated.

Using a function:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Now,

```cpp
cout << add(5, 10);

cout << add(20, 30);

cout << add(100, 200);
```

The code becomes shorter, cleaner, and reusable.

---

# Advantages of Functions

- Code Reusability
- Better Readability
- Easier Debugging
- Easier Maintenance
- Reduces Code Duplication
- Improves Modularity

---

# Real Life Analogy

Think of a function as a machine.

```
Input

↓

Function

↓

Output
```

Example:

```
5, 10

↓

add()

↓

15
```

---

# Function Syntax

```cpp
return_type function_name(parameters)
{
    // body

    return value;
}
```

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

---

# Parts of a Function

```
int add(int a, int b)
{
    return a + b;
}
```

| Part | Meaning |
|------|---------|
| int | Return Type |
| add | Function Name |
| int a, int b | Parameters |
| { } | Function Body |
| return | Returned Value |

---

# Function Terminology

```
Function Definition

↓

Function Call

↓

Execution

↓

Return
```

---

# Function Definition

The actual implementation of a function.

Example:

```cpp
int square(int x)
{
    return x * x;
}
```

---

# Function Call

Calling a function transfers program control to that function.

Example:

```cpp
square(5);
```

The function executes and then returns control to the caller.

---

# Example

```cpp
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << add(5, 3);

    return 0;
}
```

Output

```
8
```

---

# Function Execution Flow

```
main()

   │

   ▼

add(5,3)

   │

return 8

   │

   ▼

main() continues
```

---

# Function Call Stack

Whenever a function is called,

the operating system creates a **Stack Frame**.

Example

```cpp
main()

↓

add()

↓

multiply()
```

Memory Layout

```
Stack

+-------------+
| multiply()  |
+-------------+
| add()       |
+-------------+
| main()      |
+-------------+
```

When `multiply()` finishes,

its stack frame is removed.

Then

`add()`

continues execution.

---

# Function Prototype

A function prototype tells the compiler that a function exists.

Syntax

```cpp
return_type function(parameters);
```

Example

```cpp
int add(int, int);
```

Notice:

There is **no function body**.

---

# Why Do We Need Prototypes?

The compiler reads code from top to bottom.

Example

```cpp
int main()
{
    add(2,3);
}

int add(int a, int b)
{
    return a+b;
}
```

Without a prototype,

the compiler doesn't know about `add()` when it reaches `main()`.

Correct

```cpp
int add(int,int);

int main()
{

}

int add(int a,int b)
{

}
```

---

# Function Definition

The complete implementation.

Example

```cpp
int add(int a, int b)
{
    return a + b;
}
```

---

# Function Declaration vs Definition

Declaration

```cpp
int add(int,int);
```

Definition

```cpp
int add(int a,int b)
{
    return a+b;
}
```

| Declaration | Definition |
|-------------|------------|
| Tells compiler | Implements function |
| No body | Contains body |

---

# Parameters

Variables declared inside the function definition.

Example

```cpp
int add(int a, int b)
```

Here,

```
a

b
```

are parameters.

---

# Arguments

Actual values supplied during function call.

Example

```cpp
add(10,20);
```

Arguments

```
10

20
```

---

# Parameters vs Arguments

| Parameters | Arguments |
|------------|-----------|
| Inside function definition | Passed during function call |
| Receive values | Supply values |

---

# Return Type

Specifies the datatype returned by the function.

Example

```cpp
int add()
```

Returns an integer.

---

# Returning Values

```cpp
return expression;
```

Example

```cpp
return a+b;
```

The returned value goes back to the caller.

---

# Functions Returning Nothing

Some functions perform work but return nothing.

Return type

```cpp
void
```

Example

```cpp
void greet()
{
    cout << "Hello";
}
```

---

# Calling void Function

```cpp
greet();
```

Output

```
Hello
```

---

# Types of Functions

Functions are commonly classified into four categories.

---

## 1. No Arguments, No Return Value

```cpp
void greet()
{
    cout << "Hello";
}
```

---

## 2. Arguments, No Return Value

```cpp
void printSum(int a,int b)
{
    cout<<a+b;
}
```

---

## 3. No Arguments, Return Value

```cpp
int getNumber()
{
    return 100;
}
```

---

## 4. Arguments and Return Value

```cpp
int add(int a,int b)
{
    return a+b;
}
```

This is the most commonly used type.

---

# Scope of Parameters

Parameters behave like local variables.

Example

```cpp
int add(int a,int b)
{

}
```

`a`

and

`b`

exist only inside the function.

---

# Local Variables

Variables declared inside a function are local.

Example

```cpp
void fun()
{
    int x = 10;
}
```

`x`

cannot be accessed outside the function.

---

# Nested Function Calls

Example

```cpp
square(add(2,3));
```

Execution

```
main()

↓

add()

↓

returns 5

↓

square()

↓

returns 25
```

---

# Function Naming

Good

```cpp
calculateArea()

findMaximum()

printStudent()
```

Poor

```cpp
abc()

temp()

f1()
```

Choose names that describe the function's purpose.

---

# Common Mistakes

## Forgetting Parentheses

Wrong

```cpp
add;
```

Correct

```cpp
add();
```

---

## Missing Return

Wrong

```cpp
int add()
{

}
```

Every non-void function should return a value.

---

## Calling Before Declaration

Wrong

```cpp
main()

↓

add()

↓

Definition Later
```

Without a prototype,

this results in a compilation error.

---

# Best Practices

- Keep functions small.
- One function should perform one task.
- Use meaningful names.
- Avoid duplicate code.
- Write reusable functions.
- Use prototypes when definitions appear later.
- Prefer returning values instead of using global variables.

---

# Important Points

- Functions improve code reusability.
- A function performs one specific task.
- Every function has a return type.
- Parameters receive values.
- Arguments provide values.
- Function calls create stack frames.
- Local variables exist only inside their function.
- Prototypes allow functions to be called before their definitions.

---

# Summary

- Functions are one of the most important building blocks of C++.
- They divide large programs into smaller, manageable pieces.
- Proper use of functions improves readability, maintainability, and code reuse.
- Understanding functions is essential before learning parameter passing, recursion, overloading, templates, and object-oriented programming.

---

## What's Next?

**Next Chapter:** Function Declaration & Definition

You'll learn:

- Declaration
- Definition
- Prototype
- Forward Declaration
- Header Files
- Multiple Source Files
- Compilation Units
- Linker Perspective
