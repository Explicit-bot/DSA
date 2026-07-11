# 00_Mathematics_And_Number_Theory

## 02_Divisibility_And_Factors

### Learn Before Starting

Before attempting any problem in this section, make sure you understand the following concepts.

---

# 1. What is Divisibility?

A number **a** is divisible by another number **b** if dividing **a** by **b** leaves no remainder.

Mathematically,

```text
a % b = 0
```

Example:

```cpp
12 % 3 = 0
18 % 6 = 0
25 % 5 = 0
```

Not divisible:

```cpp
13 % 5 = 3
19 % 4 = 3
```

---

# 2. What is a Factor?

A factor (or divisor) of a number is a number that divides it exactly.

Example:

```text
12
```

Factors:

```text
1 2 3 4 6 12
```

Every factor satisfies:

```cpp
12 % factor == 0
```

---

# 3. What is a Multiple?

A multiple is obtained by multiplying a number by an integer.

Example:

Multiples of 5:

```text
5
10
15
20
25
30
...
```

Formula:

```text
multiple = n × k
```

where k is an integer.

---

# 4. Relationship Between Factors and Multiples

If

```text
a divides b
```

then

```text
a is a factor of b

b is a multiple of a
```

Example:

```text
4 divides 20

4 is a factor of 20

20 is a multiple of 4
```

---

# 5. Factor Pairs

Factors always occur in pairs.

Example:

```text
36
```

Pairs:

```text
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

Notice that once we reach

```text
6
```

the pairs start repeating.

This observation leads to an important optimization.

---

# 6. Why Do We Only Iterate Till √N?

Suppose

```text
n = 36
```

Pairs are:

```text
1 36
2 18
3 12
4 9
6 6
```

After √36 = 6, every remaining factor has already been discovered through its pair.

General Proof:

If

```text
a × b = n
```

and

```text
a > √n
```

then

```text
b < √n
```

Therefore every factor larger than √n has a corresponding factor smaller than √n.

Hence checking beyond √n is unnecessary.

---

# 7. Finding All Factors

## Brute Force

```cpp
for(int i = 1; i <= n; i++)
{
    if(n % i == 0)
    {
        // factor found
    }
}
```

Complexity:

```text
O(n)
```

---

## Optimized

```cpp
for(int i = 1; i * i <= n; i++)
{
    if(n % i == 0)
    {
        // i is a factor

        if(i != n / i)
        {
            // n / i is also a factor
        }
    }
}
```

Complexity:

```text
O(√n)
```

---

# 8. Perfect Square

A perfect square is a number whose square root is an integer.

Examples:

```text
1
4
9
16
25
36
49
64
81
100
```

Check:

```cpp
int root = sqrt(n);

if(root * root == n)
{
    // perfect square
}
```

---

# 9. Mathematical Functions Required

```cpp
#include <cmath>
```

Functions:

```cpp
sqrt()
```

Remember:

```cpp
sqrt()
```

returns a

```text
double
```

not an integer.

---

# 10. Complexity

Brute force factor search:

```text
O(n)
```

Optimized factor search:

```text
O(√n)
```

This optimization is one of the most frequently used ideas in number theory.

---

# 11. Common Observations

If

```text
n % i == 0
```

then

```text
n / i
```

is also a factor.

Example:

```text
60
```

If

```text
60 % 4 == 0
```

then

```text
60 / 4 = 15
```

So factors are:

```text
4 and 15
```

---

# 12. Edge Cases

Always think about:

* n = 1
* Prime numbers
* Perfect squares
* Very large values of n
* Duplicate factor when i == n / i

Example:

```text
36

6 × 6
```

Only print

```text
6
```

once.

---

# Problems

## Easy

* Count Divisors (Classic)
* Print All Divisors (Classic)
* LC 2427 — Number of Common Factors
* LC 2520 — Count the Digits That Divide a Number
* LC 507 — Perfect Number
* LC 1952 — Three Divisors

## Medium

* LC 1492 — The kth Factor of n
* LC 1390 — Four Divisors
* LC 2427 — Number of Common Factors (optimized)
* LC 2507 — Smallest Value After Replacing With Sum of Prime Factors

## Hard

None.

Hard divisor problems generally require concepts from later sections such as Prime Numbers, GCD, Sieve, or Dynamic Programming and are intentionally postponed to avoid future-topic leakage.
