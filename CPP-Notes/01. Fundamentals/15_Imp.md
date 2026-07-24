# Important Language Concepts in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Variables
- Data Types
- Operators
- Type Conversion

---

# Introduction

This chapter covers important language concepts that don't belong to a single topic but are used throughout C++.

Understanding these concepts will help you avoid many common programming mistakes.

---

# Topics Covered

- Integer Division
- Floating Point Division
- Explicit Type Casting
- Implicit Type Conversion
- float vs double
- NaN
- Infinity
- Division by Zero
- Overflow
- Underflow
- Integer Overflow
- Floating Point Precision
- Increment & Decrement Pitfalls
- Undefined Behavior
- Integer Promotion

---

# Integer Division

When **both operands are integers**, C++ performs **integer division**.

The fractional part is discarded.

Example:

```cpp
5 / 2
```

Output:

```
2
```

Examples:

```
10 / 3 = 3

15 / 4 = 3

100 / 9 = 11
```

---

# Floating Point Division

If **at least one operand is floating-point**, the result becomes floating-point.

Examples:

```cpp
5.0 / 2
```

```
2.5
```

```cpp
5 / 2.0
```

```
2.5
```

```cpp
5.0 / 2.0
```

```
2.5
```

---

# Explicit Type Casting

Sometimes integer division is not desired.

Example:

```cpp
22 / 7
```

Output:

```
3
```

Correct:

```cpp
(float)22 / 7
```

Output:

```
3.142857
```

---

# Common Mistake

Wrong:

```cpp
(float)(22 / 7)
```

Output:

```
3.0
```

Reason:

Division happens first.

The result

```
3
```

is then converted to

```
3.0
```

Always cast **before** the operation.

---

# Implicit Type Conversion

The compiler automatically converts smaller types into larger types when required.

Example:

```cpp
22 / 7.0
```

Internally:

```
22

↓

22.0
```

Result:

```
3.142857
```

---

# float vs double

| float | double |
|--------|---------|
| 4 Bytes | 8 Bytes |
| ~6–7 digits | ~15–16 digits |
| Lower Precision | Higher Precision |

Example:

```cpp
float x = 3.1415926535f;

double y = 3.1415926535;
```

`double` stores much more accurate values.

---

# Which One Should You Use?

Unless memory is extremely limited,

prefer

```cpp
double
```

It is more accurate and is the default floating-point type in C++.

---

# Floating Point Precision

Floating-point numbers cannot represent every decimal value exactly.

Example:

```cpp
double x = 0.1 + 0.2;

cout << x;
```

Output may become:

```
0.30000000000000004
```

This happens because decimal values are stored in binary.

---

# Never Compare Floating Point Numbers Directly

Wrong:

```cpp
if(x == 0.3)
```

Better:

```cpp
fabs(x - 0.3) < 1e-9
```

We'll study this in detail later.

---

# NaN (Not a Number)

NaN means

```
Not a Number
```

Produced when a mathematical operation has no valid numeric result.

Examples:

```cpp
0.0 / 0.0
```

```cpp
sqrt(-1)
```

```cpp
log(-5)
```

---

# Properties of NaN

NaN is unique.

Even

```cpp
NaN == NaN
```

returns

```
false
```

---

# Checking NaN

Correct:

```cpp
isnan(x)
```

Wrong:

```cpp
x == NaN
```

Never compare NaN directly.

---

# Infinity

Floating-point numbers support positive and negative infinity.

Examples:

```cpp
10.0 / 0.0
```

Result:

```
+Infinity
```

---

```cpp
-10.0 / 0.0
```

Result:

```
-Infinity
```

These values are defined by the IEEE-754 floating-point standard.

---

# Division by Zero

## Integer Division

Example:

```cpp
10 / 0
```

Result:

```
Undefined Behavior
```

Most systems terminate the program with a runtime error.

---

## Floating Point Division

Example:

```cpp
10.0 / 0.0
```

Result:

```
Infinity
```

---

```cpp
0.0 / 0.0
```

Result:

```
NaN
```

---

# Overflow

Overflow occurs when a value exceeds the maximum range of its datatype.

Example:

```cpp
char x = 127;

++x;
```

Typical Output:

```
-128
```

Reason:

```
127

↓

Overflow

↓

-128
```

---

# Underflow

Underflow occurs when a value becomes smaller than the minimum range.

Example:

```cpp
char x = -128;

--x;
```

Typical Output:

```
127
```

---

# Integer Overflow

Example:

```cpp
int x = INT_MAX;

x++;
```

The result is **Undefined Behavior** in C++.

Some systems wrap around, but you should never rely on it.

---

# Floating Point Overflow

Example:

```cpp
double x = 1e308;

x *= 100;
```

Output:

```
Infinity
```

---

# Integer Promotion

Small integer types are automatically promoted to `int` during arithmetic.

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

Result type:

```
int
```

---

# Increment and Decrement Pitfalls

Avoid modifying the same variable multiple times within a single expression.

Wrong:

```cpp
int i = 5;

int x = ++i + i++;
```

This produces

```
Undefined Behavior
```

The compiler may evaluate the expression in different ways.

---

# Undefined Behavior

Undefined Behavior means the C++ Standard places **no requirements** on what happens.

The compiler is free to do anything.

Examples:

```cpp
int x = 10 / 0;
```

---

```cpp
int* ptr = nullptr;

*ptr = 10;
```

---

```cpp
int i = 5;

int x = ++i + i++;
```

Possible consequences:

- Crash
- Wrong Output
- No Error
- Different Output on Different Compilers

Never rely on Undefined Behavior.

---

# Implementation-Defined Behavior

Some behavior is intentionally left to the compiler.

Example:

```
Is char signed or unsigned?
```

Different compilers may choose different implementations.

Always consult compiler documentation if behavior is implementation-defined.

---

# Common Mistakes

### Integer Division

Wrong:

```cpp
22 / 7
```

Expected:

```
3.142857
```

Actual:

```
3
```

---

### Casting Too Late

Wrong:

```cpp
(float)(22 / 7)
```

Correct:

```cpp
(float)22 / 7
```

---

### Comparing Floating Point Numbers

Wrong:

```cpp
if(a == b)
```

Prefer using a tolerance.

---

### Modifying Variables Multiple Times

Wrong:

```cpp
++i + i++
```

Produces Undefined Behavior.

---

# Best Practices

- Prefer `double` over `float`.
- Never divide integers when decimal precision is needed.
- Cast before performing arithmetic.
- Avoid Undefined Behavior.
- Never compare floating-point values directly.
- Never assume integer overflow wraps around.
- Write clear expressions instead of clever ones.

---

# Important Points

- Integer division discards the fractional part.
- Floating-point division preserves decimals.
- `double` is usually preferred over `float`.
- NaN represents an invalid numeric result.
- Integer division by zero is Undefined Behavior.
- Floating-point division by zero produces Infinity or NaN.
- Integer overflow should never be relied upon.
- Small integer types are promoted to `int`.
- Undefined Behavior means anything can happen.

---

# Summary

- Many bugs in C++ arise not from syntax errors but from misunderstandings of language behavior.
- Concepts such as integer division, floating-point precision, overflow, NaN, and Undefined Behavior appear frequently in interviews and real-world programming.
- A strong understanding of these concepts will make your programs more reliable, portable, and easier to debug.

---

## What's Next?

**Next Chapter:** Keywords

You'll learn:

- C++ Reserved Keywords
- Categories of Keywords
- Contextual Keywords
- Commonly Used Keywords
- Best Practices
