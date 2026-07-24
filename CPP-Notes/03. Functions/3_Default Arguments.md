# Default Arguments in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Functions
- Function Parameters
- Function Calls

---

# Introduction

Sometimes a function can be called with the same argument values repeatedly.

Instead of passing those values every time, C++ allows us to specify **default values** for parameters.

These values are called **Default Arguments** (or **Default Parameters**).

---

# Why Do We Need Default Arguments?

Suppose a company gives every employee a default bonus of ₹1000.

Without default arguments:

```cpp
calculateSalary(50000, 1000);
calculateSalary(60000, 1000);
calculateSalary(70000, 1000);
```

The same value is written repeatedly.

With default arguments:

```cpp
calculateSalary(50000);
calculateSalary(60000);
calculateSalary(70000);
```

Cleaner and easier to maintain.

---

# Syntax

```cpp
return_type function(parameter = default_value);
```

Example

```cpp
void greet(string name = "Guest")
{
    cout << "Hello " << name;
}
```

---

# Example

```cpp
#include <iostream>
using namespace std;

void greet(string name = "Guest")
{
    cout << "Hello " << name;
}

int main()
{
    greet();

    greet("Naman");
}
```

Output

```
Hello Guest
Hello Naman
```

---

# How Default Arguments Work

Function

```cpp
void greet(string name = "Guest")
```

Call

```cpp
greet();
```

Compiler internally treats it as

```cpp
greet("Guest");
```

---

# Supplying Your Own Value

If an argument is supplied,

the default value is ignored.

Example

```cpp
greet("Rahul");
```

Output

```
Hello Rahul
```

---

# Multiple Default Arguments

```cpp
void display(int a = 10,
             int b = 20)
{
    cout << a << " " << b;
}
```

Example

```cpp
display();
```

Output

```
10 20
```

---

```cpp
display(100);
```

Output

```
100 20
```

---

```cpp
display(100, 200);
```

Output

```
100 200
```

---

# Memory View

Function

```cpp
display(100);
```

Compiler sees

```
a = 100

b = 20
```

Only the missing arguments receive default values.

---

# Rules for Default Arguments

---

## Rule 1

Default arguments must be assigned **from right to left**.

Correct

```cpp
void fun(int a,
         int b = 10,
         int c = 20);
```

---

Wrong

```cpp
void fun(int a = 10,
         int b,
         int c);
```

Compilation Error.

---

# Why?

Suppose

```cpp
fun(5);
```

Compiler cannot determine

```
a = ?

b = ?

c = ?
```

Therefore,

once a parameter receives a default value,

all parameters to its right must also have default values.

---

## Rule 2

Default arguments should be specified only **once**.

Usually in the function declaration.

Correct

```cpp
void fun(int x = 10);

void fun(int x)
{

}
```

Wrong

```cpp
void fun(int x = 10);

void fun(int x = 20)
{

}
```

Compilation Error.

---

## Rule 3

Arguments are matched **from left to right**.

Example

```cpp
void add(int a,
         int b = 10,
         int c = 20);
```

Call

```cpp
add(5);
```

Compiler assigns

```
a = 5

b = 10

c = 20
```

---

# Common Examples

Example 1

```cpp
void print(int x = 100)
{
    cout << x;
}
```

---

Example 2

```cpp
int add(int a,
        int b = 0)
{
    return a + b;
}
```

---

Example 3

```cpp
void student(string name,
             string city = "Delhi")
{

}
```

---

# Advantages

- Reduces duplicate code.
- Makes function calls simpler.
- Improves readability.
- Provides optional parameters.
- Easier to maintain.

---

# Limitations

- Arguments can only be omitted from the right.
- Default values cannot depend on later parameters.
- Too many default parameters may reduce readability.

---

# Common Mistakes

## Wrong Order

Wrong

```cpp
void fun(int a = 10,
         int b);
```

Compilation Error.

---

## Giving Default Values Twice

Wrong

```cpp
void fun(int x = 5);

void fun(int x = 10)
{

}
```

Compilation Error.

---

## Forgetting That User Values Override Defaults

```cpp
display(100);
```

does **not** produce

```
10 20
```

It produces

```
100 20
```

---

# Default Arguments vs Function Overloading

Sometimes both can solve the same problem.

Default Arguments

```cpp
void print(int x = 0);
```

Function Overloading

```cpp
void print();

void print(int x);
```

For simple optional parameters,

default arguments are usually preferred.

For different behavior,

function overloading is a better choice.

---

# Best Practices

- Declare default arguments in the function declaration.
- Use meaningful default values.
- Avoid too many default parameters.
- Use default arguments only when a parameter is genuinely optional.

---

# Important Points

- Default arguments provide values automatically when arguments are omitted.
- Missing arguments are filled from left to right using available defaults.
- Default values must be assigned from right to left.
- Default arguments should be specified only once.
- Explicitly supplied arguments always override default values.

---

# Summary

- Default arguments make functions easier to use by allowing optional parameters.
- They reduce repetitive code and improve readability.
- They are widely used in libraries and APIs to provide flexible function interfaces without requiring multiple overloaded functions.

---

## What's Next?

**Next Chapter:** Inline Functions

You'll learn:

- What are Inline Functions?
- Why They Exist
- Function Call Overhead
- Inline Expansion
- Advantages
- Limitations
- When Inline is Ignored
- `inline` vs Macros
