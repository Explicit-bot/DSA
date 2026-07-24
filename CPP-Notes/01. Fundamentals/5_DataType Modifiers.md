# Data Type Modifiers in C++

---

# What are Data Type Modifiers?

**Modifiers** are keywords that change the **size**, **range**, or **sign** of fundamental data types.

They modify the behavior of an existing data type instead of creating a new one.

Example:

```cpp
short int age;
long int population;
unsigned int marks;
```

Here,

- `short`
- `long`
- `unsigned`

are **modifiers**.

---

# Why Do We Need Modifiers?

Different situations require different ranges of values.

Example:

- Student age → `short`
- Population of a country → `long long`
- Number of bytes in a file → `unsigned long long`

Modifiers allow us to choose the most appropriate datatype.

---

# Available Modifiers

| Modifier | Purpose |
|----------|---------|
| short | Reduces size |
| long | Increases size |
| long long | Very large integer range |
| signed | Stores positive and negative values |
| unsigned | Stores only non-negative values |

---

# Compatible Data Types

Not every modifier can be used with every datatype.

| Base Type | short | long | long long | signed | unsigned |
|-----------|:-----:|:----:|:---------:|:------:|:---------:|
| int | ✅ | ✅ | ✅ | ✅ | ✅ |
| char | ❌ | ❌ | ❌ | ✅ | ✅ |
| float | ❌ | ❌ | ❌ | ❌ | ❌ |
| double | ❌ | ✅ | ❌ | ❌ | ❌ |
| bool | ❌ | ❌ | ❌ | ❌ | ❌ |

---

# Integer Types

By default,

```cpp
int
```

means

```cpp
signed int
```

Therefore,

```cpp
int x;
```

and

```cpp
signed int x;
```

are identical.

---

# short

`short` stores smaller integers.

Example:

```cpp
short age = 20;
```

Equivalent to

```cpp
short int age;
```

Typical Size:

```
2 Bytes
```

---

# long

`long` stores larger integers.

Example:

```cpp
long population = 1000000;
```

Equivalent to

```cpp
long int population;
```

Typical Size:

```
4 or 8 Bytes
```

(depending on the compiler and operating system)

---

# long long

Used when integers may become very large.

Example:

```cpp
long long distance = 9876543210123;
```

Equivalent to

```cpp
long long int distance;
```

Typical Size:

```
8 Bytes
```

---

# signed

Allows storing both positive and negative values.

Example:

```cpp
signed int temperature = -20;
```

Range:

```
Negative

↓

0

↓

Positive
```

Since `int` is already signed by default,

writing

```cpp
signed int
```

is usually unnecessary.

---

# unsigned

Stores only non-negative values.

Example:

```cpp
unsigned int marks = 95;
```

Negative values are **not allowed**.

Since no bits are reserved for the sign, the maximum positive value becomes larger.

---

# Why Does unsigned Have a Larger Range?

Suppose a datatype uses **8 bits**.

Signed representation:

```
-128

↓

127
```

Unsigned representation:

```
0

↓

255
```

The sign bit is used for storing larger positive values instead.

---

# Modifier Combinations

The compiler automatically assumes `int` if omitted.

Examples:

```cpp
short

short int

signed short

signed short int
```

All are valid.

---

## Unsigned Short

```cpp
unsigned short
```

Equivalent to

```cpp
unsigned short int
```

---

## Unsigned Int

```cpp
unsigned
```

Equivalent to

```cpp
unsigned int
```

---

## Long

```cpp
long
```

Equivalent to

```cpp
long int
```

---

## Unsigned Long

```cpp
unsigned long
```

Equivalent to

```cpp
unsigned long int
```

---

## Long Long

```cpp
long long
```

Equivalent to

```cpp
long long int
```

---

## Unsigned Long Long

```cpp
unsigned long long
```

Equivalent to

```cpp
unsigned long long int
```

---

# Character Types

Characters can also be signed or unsigned.

```cpp
char
```

```cpp
signed char
```

```cpp
unsigned char
```

Unlike `int`, whether plain `char` behaves as signed or unsigned depends on the compiler.

Therefore,

do not assume its sign.

---

# Floating Point Types

Floating-point types support only one modifier.

```
float
```

```
double
```

```
long double
```

Example:

```cpp
long double pi = 3.141592653589793L;
```

The suffix

```
L
```

indicates a `long double` literal.

---

# Literal Types

Different literals have different default data types.

## Integer Literal

```cpp
10
```

Default datatype:

```
int
```

---

## Floating-Point Literal

```cpp
3.14
```

Default datatype:

```
double
```

To create a float literal:

```cpp
3.14f
```

---

## Character Literal

```cpp
'A'
```

Datatype:

```
char
```

---

## String Literal

```cpp
"Hello"
```

This is **not** a `std::string`.

Internally, it is stored as

```cpp
const char[]
```

This concept becomes important later while studying pointers and arrays.

---

# Data Type Sizes

Sizes depend on:

- Compiler
- Operating System
- Architecture (32-bit / 64-bit)

Never assume fixed sizes.

Always use:

```cpp
sizeof(datatype)
```

Example:

```cpp
cout << sizeof(long);
```

---

# Common Examples

```cpp
short age = 18;

unsigned int marks = 95;

long population = 1500000;

long long stars = 1000000000000;

long double pi = 3.141592653589793L;
```

---

# Best Practices

- Use `int` for most integer values.
- Use `long long` when numbers may exceed the range of `int`.
- Prefer `double` over `float` unless memory is limited.
- Use `unsigned` only when negative values are impossible.
- Never assume datatype sizes; verify using `sizeof()`.

---

