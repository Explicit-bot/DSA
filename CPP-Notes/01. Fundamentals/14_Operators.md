# Operators in C++

---

## Prerequisites

Before reading this chapter, you should know:

- Variables
- Data Types
- Type Conversion

---

# Introduction

An **Operator** is a symbol that performs an operation on one or more operands.

Example:

```cpp
a + b
```

Here,

- `+` → Operator
- `a`, `b` → Operands

Operators are one of the most fundamental parts of C++ and are used in:

- Arithmetic
- Conditions
- Loops
- Functions
- Bit Manipulation
- Object-Oriented Programming
- Competitive Programming

---

# Types of Operators

```
Operators
│
├── Arithmetic
├── Increment / Decrement
├── Assignment
├── Relational
├── Logical
├── Bitwise
├── Conditional (Ternary)
├── Special Operators
├── Operator Precedence
└── Operator Associativity
```

---

# 1. Arithmetic Operators

Used to perform mathematical calculations.

| Operator | Meaning |
|----------|---------|
| + | Addition |
| - | Subtraction |
| * | Multiplication |
| / | Division |
| % | Modulus (Remainder) |

Example:

```cpp
int a = 10;
int b = 3;

cout << a + b;
cout << a - b;
cout << a * b;
cout << a / b;
cout << a % b;
```

---

# Integer Division

If **both operands are integers**, the result is also an integer.

Example:

```cpp
7 / 2
```

Output:

```
3
```

The fractional part is discarded.

Examples:

```
9 / 4 = 2

10 / 3 = 3

-7 / 2 = -3
```

---

# Floating Point Division

If **at least one operand is floating-point**, the result is floating-point.

Examples:

```cpp
7.0 / 2

7 / 2.0

7.0 / 2.0
```

Output:

```
3.5
```

---

# Modulus Operator (%)

Returns the remainder after division.

Example:

```cpp
17 % 5
```

```
17 = (5 × 3) + 2
```

Output:

```
2
```

---

# Properties of %

- Works only with integers.
- Used to check odd/even numbers.

Examples:

```cpp
n % 2 == 0
```

Even number.

```cpp
n % 2 != 0
```

Odd number.

---

# 2. Increment and Decrement Operators

Used to increase or decrease a value by one.

| Operator | Meaning |
|----------|---------|
| ++ | Increment |
| -- | Decrement |

---

# Prefix Increment

Syntax:

```cpp
++x
```

Working:

1. Increment
2. Use value

Example:

```cpp
int x = 5;

cout << ++x;
```

Output:

```
6
```

---

# Postfix Increment

Syntax:

```cpp
x++
```

Working:

1. Use current value
2. Increment

Example:

```cpp
int x = 5;

cout << x++;
```

Output:

```
5
```

After execution:

```
x = 6
```

---

# Prefix vs Postfix

| Prefix | Postfix |
|---------|----------|
| Increment first | Use first |
| Returns new value | Returns old value |

---

# Decrement

Works exactly the same way.

```cpp
--x

x--
```

---

# Undefined Behavior

Avoid modifying the same variable multiple times in one expression.

Example:

```cpp
int i = 5;

int x = ++i + i++;
```

This results in **Undefined Behavior**.

The compiler is free to evaluate the expression in any order.

---

# 3. Assignment Operators

Used to assign values.

| Operator | Equivalent |
|----------|------------|
| = | a = b |
| += | a = a + b |
| -= | a = a - b |
| *= | a = a * b |
| /= | a = a / b |
| %= | a = a % b |

Example:

```cpp
x += 5;
```

Equivalent to:

```cpp
x = x + 5;
```

---

# = vs ==

This is one of the most common beginner mistakes.

Assignment:

```cpp
x = 5;
```

Comparison:

```cpp
x == 5;
```

Wrong:

```cpp
if(x = 5)
```

Correct:

```cpp
if(x == 5)
```

---

# 4. Relational Operators

Used to compare values.

Result:

```
true

or

false
```

| Operator | Meaning |
|----------|---------|
| == | Equal |
| != | Not Equal |
| > | Greater Than |
| < | Less Than |
| >= | Greater Than or Equal |
| <= | Less Than or Equal |

Example:

```cpp
5 > 3
```

Result:

```
true
```

---

# Boolean Output

```cpp
cout << (5 > 3);
```

Output:

```
1
```

Because

```
true → 1

false → 0
```

---

# 5. Logical Operators

Used to combine multiple conditions.

| Operator | Meaning |
|----------|---------|
| && | Logical AND |
| \|\| | Logical OR |
| ! | Logical NOT |

---

# Logical AND (&&)

Returns **true only if both conditions are true**.

Truth Table:

| A | B | A && B |
|:-:|:-:|:------:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Example:

```cpp
age >= 18 && age <= 60
```

---

# Logical OR (||)

Returns **true if at least one condition is true**.

Truth Table:

| A | B | A \|\| B |
|:-:|:-:|:---------:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

---

# Logical NOT (!)

Reverses a condition.

Example:

```cpp
!(5 > 2)
```

Result:

```
false
```

---

# Short Circuit Evaluation

## AND

If the first condition is false,

the second condition is not evaluated.

Example:

```cpp
if(a != 0 && b / a > 2)
```

If

```
a == 0
```

division never occurs.

---

## OR

If the first condition is true,

the second condition is skipped.

Example:

```cpp
if(true || expensiveFunction())
```

`expensiveFunction()` is never called.

---

# 6. Bitwise Operators

Operate directly on bits.

| Operator | Meaning |
|----------|---------|
| & | Bitwise AND |
| \| | Bitwise OR |
| ^ | Bitwise XOR |
| ~ | Bitwise NOT |
| << | Left Shift |
| >> | Right Shift |

Used in:

- Competitive Programming
- Operating Systems
- Embedded Systems
- Cryptography

---

# Bitwise AND (&)

Rule:

```
1 & 1 = 1

Otherwise 0
```

Example:

```
12 = 1100

10 = 1010

AND

1000

↓

8
```

---

# Bitwise OR (|)

Rule:

```
If either bit is 1,

result is 1.
```

---

# Bitwise XOR (^)

Rule:

```
Different bits → 1

Same bits → 0
```

Important Properties:

```
a ^ a = 0

a ^ 0 = a

(a ^ b) ^ b = a
```

---

# Bitwise NOT (~)

Flips every bit.

Important Formula:

```
~a = -(a + 1)
```

Example:

```
~5

↓

-6
```

---

# Left Shift (<<)

Moves bits to the left.

Example:

```cpp
5 << 1
```

Result:

```
10
```

Property:

```
a << n

=

a × 2ⁿ
```

---

# Right Shift (>>)

Moves bits to the right.

Example:

```cpp
20 >> 2
```

Result:

```
5
```

Property:

```
a >> n

=

a / 2ⁿ
```

(integer division)

---

# Common Bit Tricks

Check Odd / Even

```cpp
n & 1
```

Multiply by 2

```cpp
n << 1
```

Divide by 2

```cpp
n >> 1
```

Check Power of Two

```cpp
n > 0 && (n & (n - 1)) == 0
```

Remove Last Set Bit

```cpp
n & (n - 1)
```

Get Last Set Bit

```cpp
n & (-n)
```

---

# 7. Ternary Operator

Short form of an if-else statement.

Syntax:

```cpp
condition ? expression1 : expression2;
```

Example:

```cpp
int mx = (a > b) ? a : b;
```

Equivalent to:

```cpp
if(a > b)
    mx = a;
else
    mx = b;
```

---

# 8. Special Operators

| Operator | Purpose |
|----------|---------|
| sizeof | Size of datatype/object |
| & | Address of |
| * | Dereference |
| . | Member Access |
| -> | Pointer Member Access |
| :: | Scope Resolution |

---

# sizeof

Returns the size in bytes.

Example:

```cpp
sizeof(int)
```

---

# Address Operator (&)

Returns the memory address.

Example:

```cpp
int x = 10;

cout << &x;
```

---

# Dereference Operator (*)

Used with pointers.

Example:

```cpp
int* ptr = &x;

cout << *ptr;
```

---

# Operator Precedence

Precedence determines **which operator executes first**.

Example:

```cpp
2 + 3 * 4
```

Result:

```
14
```

because multiplication has higher precedence.

---

# Parentheses

Parentheses override precedence.

Example:

```cpp
(2 + 3) * 4
```

Output:

```
20
```

Always use parentheses when they improve readability.

---

# Operator Associativity

Associativity decides the direction of evaluation when operators have the same precedence.

Left to Right:

```cpp
10 - 5 - 2
```

becomes

```
(10 - 5) - 2
```

---

Right to Left:

```cpp
a = b = c = 5;
```

becomes

```
a = (b = (c = 5))
```

---

# Best Practices

- Avoid modifying a variable multiple times in the same expression.
- Prefer readability over clever tricks.
- Use parentheses to make expressions clear.
- Be careful with `=` and `==`.
- Use bitwise operators only when necessary.
- Understand short-circuit evaluation.

---

# Important Points

- Operators perform operations on operands.
- Integer division removes the fractional part.
- `%` works only with integers.
- Prefix and postfix operators behave differently.
- `=` assigns, while `==` compares.
- `&&` and `||` use short-circuit evaluation.
- Bitwise operators work directly on binary data.
- Parentheses improve readability and avoid precedence-related bugs.
- Precedence decides priority, while associativity decides evaluation order.

---

# Summary

- Operators are fundamental building blocks of C++ expressions.
- C++ provides arithmetic, relational, logical, bitwise, assignment, conditional, and special operators.
- Understanding precedence, associativity, and short-circuit evaluation helps avoid subtle bugs.
- Mastering operators is essential before moving to control flow, loops, functions, and advanced C++ programming.

---

## What's Next?

**Next Chapter:** Important Language Concepts

You'll learn:

- Integer Overflow
- Floating Point Precision
- NaN and Infinity
- Division by Zero
- Integer Promotion
- Undefined Behavior
- Implementation Defined Behavior
- Compiler Optimizations
