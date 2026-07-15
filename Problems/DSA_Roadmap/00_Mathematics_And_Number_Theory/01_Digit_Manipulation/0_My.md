# My_Notes

---

## 1. GCC Built-in Functions
### `__builtin_popcount(num)`

Returns the **number of set bits (1's)** in the binary representation of an integer.

**Example**

```text
14 = 1110₂

__builtin_popcount(14) = 3
```

---

### `__builtin_clz(num)`

Returns the **number of leading zeros** in the binary representation of an integer.

**Example**

For a **32-bit integer**:

```text
num = 14

Binary:
00000000 00000000 00000000 00001110

Leading zeros = 28
```

Therefore,

```cpp
Bit Length = 32 - __builtin_clz(num);
```

---

### Time Complexity

For a number with **b bits**:

```text
popcount() : O(b)
clz()      : O(b)
```

For `int`, `b = 32` (constant), hence:

```text
O(1)
```

### Why?

Modern CPUs often have dedicated instructions for these operations.

- **POPCNT (Population Count)** → Counts the number of `1`s in a word.
- **LZCNT (Leading Zero Count)** or **BSR (Bit Scan Reverse)** → Used to determine the number of leading zeros or the position of the highest set bit.

So a compiler may translate:

```cpp
__builtin_popcount(num);
```

into

```assembly
POPCNT eax, edi
```

Similarly,

```cpp
__builtin_clz(num);
```

into

```assembly
LZCNT eax, edi
```

Because these instructions execute in a fixed number of CPU cycles, we treat them as:

```text
O(1)
```

---

## 2. Base Conversion

### Decimal → Base `b`

- Repeatedly divide by `b`.
- Read the remainders **from bottom to top**.

---

### Base `b` → Decimal

```text
Σ(digit × b^position)
```

---

### Base `A` → Base `B`

```text
Base A → Decimal → Base B
```

---

## 3. `INT_MAX` and `INT_MIN`

### Header File

`INT_MAX` and `INT_MIN` do **not** come from:

```cpp
<iostream>
```

or

```cpp
<bits/stdc++.h>
```

on **macOS/Clang**.

They are actually defined inside:

```cpp
#include <climits>
```

---

### Bounds

```cpp
INT_MAX =  2147483647   // ends with 7
INT_MIN = -2147483648   // ends with 8
```

---

### Important Observation

Since `INT_MAX` is an `int`,

```cpp
INT_MAX / 10
```

becomes

```text
214748364
```

and **not**

```text
214748364.7
```

So, when `rev` is near the boundary (`INT_MAX / 10` or `INT_MIN / 10`), adding certain last digits would exceed the integer range.

---

### Correct Overflow Checks

```cpp
// Positive limit
if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lastdigit > 7))
    return 0;

// Negative limit
if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lastdigit < -8))
    return 0;
```

These checks ensure:

- Multiplying `rev` by `10` is safe.
- Adding `lastdigit` will not push it outside the **32-bit integer range**.

---

## 4. Digital Root

### Digital Root Formula

The repeated sum of the digits of a non-negative integer `n` until a single digit remains is called its **digital root** and is given by:

```text
dr(n) = 0                  if n = 0

dr(n) = 1 + (n − 1) % 9    if n > 0
```

This follows from the fact that a number and the sum of its digits are **congruent modulo 9**.

---
