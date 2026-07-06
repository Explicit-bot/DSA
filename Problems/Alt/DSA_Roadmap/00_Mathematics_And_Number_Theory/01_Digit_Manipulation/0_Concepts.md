# 00_Mathematics_And_Number_Theory

## 01_Digit_Manipulation

### Learn Before Starting

Before attempting any problem from this section, make sure you understand the following concepts.

---

# 1. Number Systems

* Decimal Number System (Base 10)
* Place Value System
* Powers of 10
* Most Significant Digit (MSD)
* Least Significant Digit (LSD)

Example:

```text
5837

5 × 10³ + 8 × 10² + 3 × 10¹ + 7 × 10⁰
```

---

# 2. Arithmetic Operators

Learn and understand:

```cpp
+
-
*
/
%
```

Special focus on:

## Integer Division

```cpp
123 / 10 = 12
5 / 2 = 2
1 / 10 = 0
```

## Modulo Operator

```cpp
123 % 10 = 3
456 % 10 = 6
```

---

# 3. Control Structures

You should be comfortable with:

* if
* if else
* while loops
* for loops

---

# 4. Data Types

Understand:

```cpp
int
long long
```

Know their limits:

```cpp
INT_MAX
INT_MIN
LLONG_MAX
LLONG_MIN
```

Values:

```cpp
INT_MAX   = 2147483647
INT_MIN   = -2147483648

LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775808
```

---

# 5. Core Digit Manipulation Templates

## Extract Last Digit

```cpp
int digit = n % 10;
```

---

## Remove Last Digit

```cpp
n /= 10;
```

---

## Traverse All Digits

```cpp
while(n > 0)
{
    int digit = n % 10;

    // process digit

    n /= 10;
}
```

---

## Reverse Number

```cpp
reverse = reverse * 10 + digit;
```

Complete template:

```cpp
int reverse = 0;

while(n > 0)
{
    int digit = n % 10;

    reverse = reverse * 10 + digit;

    n /= 10;
}
```

---

## Count Digits

```cpp
int count = 0;

while(n > 0)
{
    count++;
    n /= 10;
}
```

---

## Sum Of Digits

```cpp
int sum = 0;

while(n > 0)
{
    sum += n % 10;

    n /= 10;
}
```

---

## Product Of Digits

```cpp
int product = 1;

while(n > 0)
{
    product *= n % 10;

    n /= 10;
}
```

---

# 6. Mathematical Functions

Header:

```cpp
#include <cmath>
```

Functions to know:

```cpp
abs()
sqrt()
pow()
log10()
floor()
ceil()
```

Examples:

```cpp
abs(-15)      // 15
sqrt(49)      // 7
pow(2,10)     // 1024
log10(1000)   // 3
floor(3.9)    // 3
ceil(3.1)     // 4
```

---

# 7. STL Functions

## algorithm

```cpp
#include <algorithm>
```

Functions:

```cpp
reverse()
max()
min()
```

Examples:

```cpp
reverse(v.begin(), v.end());

max(a,b);

min(a,b);
```

---

## string

```cpp
#include <string>
```

Functions:

```cpp
to_string()
stoi()
stoll()
```

Examples:

```cpp
string s = to_string(123);

int x = stoi("123");

long long y = stoll("123456789123");
```

---

# 8. Complexity Knowledge

Understand why:

```cpp
while(n > 0)
{
    n /= 10;
}
```

runs in:

```text
O(log10(n))
```

and not:

```text
O(n)
```

Reason:

Each iteration removes one digit.

Example:

```text
1000000000
100000000
10000000
1000000
100000
10000
1000
100
10
1
0
```

Only 10 iterations are required.

---

# 9. Important Edge Cases
Always check:
* n = 0
* negative numbers
* integer overflow
* leading zeroes disappearing after reversal

Examples:
1200 -> 21
100 -> 1
10 -> 1
