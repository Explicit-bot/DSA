# 01_Digit_Manipulation

---

## Extraction of Digits

### Key Operators

- `%` (Modulus) → Extracts the **last digit**.
- `/` (Integer Division) → Removes the **last digit**.

So, whenever we perform:

```cpp
int digit = n % 10;   // Get the LAST digit
n /= 10;              // Remove the LAST digit
```

---

## Special Focus

### Integer Division

```text
123 / 10 = 12
5 / 2    = 2
1 / 10   = 0
```

---

### Modulo Operator

```text
123 % 10 = 3
456 % 10 = 6
```

---

## Data Types

### Understand

- `int`
- `long long`

### Know Their Limits

```cpp
INT_MAX   = 2147483647
INT_MIN   = -2147483648

LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775808
```

---

## Count Digits

### Method 1: Using Loop

```cpp
if (n == 0) {
    return 1;
}

while (n > 0) {
    count++;
    n /= 10;
}
```

---

### Method 2: Using `log10()`

```cpp
digits = floor(log10(n)) + 1;
```

---

## Mathematical Functions

**Header**

```cpp
#include <cmath>
```

### Functions to Know

```cpp
abs(-15);      // 15
sqrt(49);      // 7
pow(2, 10);    // 1024
log10(1000);   // 3
floor(3.9);    // 3
ceil(3.1);     // 4
```

---

## STL Functions

### `<algorithm>`

**Header**

```cpp
#include <algorithm>
```

**Functions**

```cpp
reverse(v.begin(), v.end());

max(a, b);
min(a, b);
```

---

### `<string>`

**Header**

```cpp
#include <string>
```

**Functions**

```cpp
to_string();
stoi();
stoll();
```

### Examples

```cpp
string s = to_string(123);

int x = stoi("123");

long long y = stoll("123456789123");
```

---

## Important Edge Cases

Always check:

- `n = 0`
- Negative numbers
- Integer overflow
- Leading zeroes disappearing after reversal

### Examples

```text
1200 → 21
100  → 1
10   → 1
```

---

## Quick Revision

| Operation | Purpose |
|-----------|---------|
| `n % 10` | Extract last digit |
| `n / 10` | Remove last digit |
| `log10(n) + 1` | Count digits (except `n = 0`) |
| `to_string()` | Number → String |
| `stoi()` | String → int |
| `stoll()` | String → long long |
| `reverse()` | Reverse a string/vector |
| `pow()` | Compute power |
| `sqrt()` | Square root |
| `abs()` | Absolute value |

---


