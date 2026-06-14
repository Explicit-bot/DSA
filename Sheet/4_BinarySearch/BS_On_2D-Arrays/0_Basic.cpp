/*
=========================================================================================
                                POWER / EXPONENTIATION
=========================================================================================

This file contains COMPLETE notes about:

1. What is exponentiation
2. pow() function in C++
3. Problems with pow()
4. Safe uses of pow()
5. Powers of 2 using left shift
6. Naive exponentiation
7. Recursive Binary Exponentiation
8. Iterative Binary Exponentiation
9. Bitwise understanding
10. Why Binary Exponentiation works
11. Modular Exponentiation
12. Mathematical properties of modulo
13. Time complexities
14. Overflow issues
15. Competitive Programming usage
16. Important observations and tricks

=========================================================================================
                                1. WHAT IS EXPONENTIATION?
=========================================================================================

Exponentiation means repeated multiplication.

Example:

    2^5

means:

    2 * 2 * 2 * 2 * 2 = 32

Terminology:

    2 -> Base
    5 -> Exponent / Power

General form:

    a^b

Meaning:
    multiply 'a' exactly 'b' times.

=========================================================================================
                                2. pow() FUNCTION IN C++
=========================================================================================

Header:

*/
#include <iostream>
#include <cmath>
using namespace std;

/*
pow() is available in <cmath>

Syntax:

    pow(base, exponent)

Example:
*/

void powExamples() {

    cout << pow(2,3) << endl;      // 8
    cout << pow(5,2) << endl;      // 25
    cout << pow(9,0.5) << endl;    // 3
    cout << pow(2,-2) << endl;     // 0.25
}

/*
IMPORTANT:
-----------------------------------------
pow() generally returns DOUBLE.

Even:

    pow(2,3)

returns internally:

    8.000000

Type:

    double

So:

*/

void castingPow() {

    int x = (int)pow(2,3);

    cout << x << endl;
}

/*
Better cast:
*/

void betterCast() {

    int x = static_cast<int>(pow(2,3));

    cout << x << endl;
}

/*
=========================================================================================
                        3. PROBLEMS WITH pow()
=========================================================================================

pow() uses floating point internally.

Many implementations use:

        a^b = e^(b * ln(a))

for non-integer powers.

This causes precision issues.

Example:
*/

void precisionProblem() {

    cout << pow(2,10) << endl;

    // sometimes internally:
    // 1023.999999999
}

/*
Because of floating point approximation.

NEVER use pow() for exact integer comparisons.

WRONG:
*/

void wrongComparison() {

    if(pow(2,5) == 32) {
        cout << "Equal\n";
    }
}

/*
Why wrong?
-----------------------------------------
Floating point comparisons are dangerous.

Correct:
*/

void correctComparison() {

    if((1 << 5) == 32) {
        cout << "Equal\n";
    }
}

/*
=========================================================================================
                    4. WHEN IS pow() SAFE TO USE?
=========================================================================================

pow() is generally SAFE for:

1. Mathematical calculations
2. Fractional powers
3. Graphics
4. Scientific calculations
5. Approximate answers acceptable

Examples:

*/

void safePowUsage() {

    cout << pow(16,0.5) << endl;     // sqrt
    cout << pow(27,1.0/3) << endl;   // cube root
    cout << pow(2.5,3.7) << endl;
}

/*
pow() is NOT ideal for:

1. Competitive Programming integer powers
2. Exact comparisons
3. Huge integer exponents
4. Modular arithmetic

=========================================================================================
                        5. POWER OF 2 USING LEFT SHIFT
=========================================================================================

IMPORTANT BITWISE PROPERTY:

        1 << n

means:

        2^n

Why?

Binary left shift multiplies by 2.

Examples:

*/

void leftShiftExamples() {

    cout << (1 << 0) << endl;    // 1
    cout << (1 << 1) << endl;    // 2
    cout << (1 << 2) << endl;    // 4
    cout << (1 << 3) << endl;    // 8
    cout << (1 << 4) << endl;    // 16
    cout << (1 << 5) << endl;    // 32
}

/*
Binary visualization:

    1 = 0001

    1 << 1 = 0010 = 2
    1 << 2 = 0100 = 4
    1 << 3 = 1000 = 8

Each left shift:
    multiply by 2

IMPORTANT:
-----------------------------------------
Only works for powers of 2.

=========================================================================================
                        6. NAIVE EXPONENTIATION
=========================================================================================

Basic approach:
multiply 'a' exactly 'b' times.

Complexity:
    O(b)

Code:
*/

long long naivePower(long long a, long long b) {

    long long ans = 1;

    for(int i = 0; i < b; i++) {
        ans *= a;
    }

    return ans;
}

/*
Example:

    naivePower(2,5)

Process:

    1 * 2 = 2
    2 * 2 = 4
    4 * 2 = 8
    8 * 2 = 16
    16 * 2 = 32

Problem:
-----------------------------------------
Very slow for huge powers.

Example:

    2^1000000000

Impossible practically.

=========================================================================================
                7. MATHEMATICS BEHIND BINARY EXPONENTIATION
=========================================================================================

KEY OBSERVATION:

If exponent is EVEN:

        a^b = (a^(b/2))^2

Example:

        2^8 = (2^4)^2

If exponent is ODD:

        a^b = a * a^(b-1)

Example:

        2^5 = 2 * 2^4

This reduces exponent quickly.

Instead of:
    subtracting 1 every time

we:
    divide exponent by 2

This reduces complexity from:

    O(n)

to:

    O(log n)

=========================================================================================
                8. RECURSIVE BINARY EXPONENTIATION
=========================================================================================
*/

long long recursivePower(long long a, long long b) {

    // base case
    if(b == 0) {
        return 1;
    }

    // even exponent
    if(b % 2 == 0) {

        long long half = recursivePower(a,b/2);

        return half * half;
    }

    // odd exponent
    else {

        return a * recursivePower(a,b-1);
    }
}

/*
Example:

        2^10

becomes:

        (2^5)^2

then:

        2 * (2^4)

then:

        ((2^2)^2)

Exponent keeps shrinking rapidly.

Complexity:
-----------------------------------------
O(log b)

Space Complexity:
-----------------------------------------
O(log b)
(recursion stack)

=========================================================================================
                9. ITERATIVE BINARY EXPONENTIATION
=========================================================================================

MOST IMPORTANT VERSION.

Uses:
1. binary representation
2. bit operations

Core idea:
-----------------------------------------

Example:

        13 = 1101(binary)

Meaning:

        13 = 8 + 4 + 1

So:

        2^13
        =
        2^8 * 2^4 * 2^1

We only multiply powers corresponding to SET BITS.

=========================================================================================
*/

long long iterativePower(long long a, long long b) {

    long long ans = 1;

    while(b > 0) {

        // if current bit is set
        if(b & 1) {
            ans *= a;
        }

        // square the base
        a *= a;

        // move to next bit
        b >>= 1;
    }

    return ans;
}

/*
DRY RUN:
-----------------------------------------

Compute:

        3^13

13 in binary:

        1101

Iteration 1:
-----------------------------------------
b = 13

last bit = 1

ans = ans * a
    = 1 * 3
    = 3

square base:
    a = 3 * 3 = 9

shift exponent:
    b = 6

Iteration 2:
-----------------------------------------
b = 6

last bit = 0

no multiplication

square:
    a = 81

shift:
    b = 3

Iteration 3:
-----------------------------------------
last bit = 1

ans = 3 * 81

etc...

=========================================================================================
                    10. WHY DOES a *= a WORK?
=========================================================================================

Suppose:

        a = 2

After squaring repeatedly:

        2
        4
        16
        256
        ...

These are:

        2^1
        2^2
        2^4
        2^8
        ...

Every squaring doubles exponent power.

This perfectly matches binary decomposition.

=========================================================================================
                    11. BITWISE UNDERSTANDING
=========================================================================================

IMPORTANT OPERATORS:
-----------------------------------------

1. b & 1

Checks:
    Is last bit set?

Meaning:
    Is number odd?

Examples:

    5 = 101
    5 & 1 = 1

    6 = 110
    6 & 1 = 0

2. b >>= 1

Right shift by 1.

Equivalent to:

    b = b / 2

for integers.

Example:

    13 = 1101
    13 >> 1 = 0110 = 6

=========================================================================================
                    12. MODULAR ARITHMETIC
=========================================================================================

Expression:

        a % m

means:
    remainder when a is divided by m.

Example:

        17 % 5 = 2

because:

        17 = 5*3 + 2

=========================================================================================
            13. IMPORTANT MODULO PROPERTIES
=========================================================================================

VERY IMPORTANT:

1. Addition Property

        (a + b) % m
        =
        ((a % m) + (b % m)) % m

2. Subtraction Property

        (a - b) % m
        =
        ((a % m) - (b % m) + m) % m

3. Multiplication Property

        (a * b) % m
        =
        ((a % m) * (b % m)) % m

This property makes modular exponentiation possible.

IMPORTANT:
-----------------------------------------

Division DOES NOT work normally.

WRONG:

        (a / b) % m

NOT equal to:

        ((a % m) / (b % m)) % m

Division requires modular inverse.

=========================================================================================
                14. MODULAR EXPONENTIATION
=========================================================================================

Goal:

        a^b % mod

efficiently.

Without modulo:
-----------------------------------------
Huge overflow occurs.

Example:

        2^1000000

Impossible to store.

Solution:
-----------------------------------------
Take modulo after every multiplication.

=========================================================================================
*/

long long modularPower(long long a, long long b, long long mod) {

    long long ans = 1;

    // reduce initial base
    a %= mod;

    while(b > 0) {

        // if current bit set
        if(b & 1) {

            ans = (ans * a) % mod;
        }

        // square base
        a = (a * a) % mod;

        // shift exponent
        b >>= 1;
    }

    return ans;
}

/*
Complexity:
-----------------------------------------
O(log b)

=========================================================================================
                15. WHY MODULAR EXPONENTIATION WORKS
=========================================================================================

Property used:

        (a * b) % m
        =
        ((a % m) * (b % m)) % m

So we reduce values repeatedly.

Instead of huge numbers:
-----------------------------------------

        2^1000000

we always keep numbers in range:

        [0, mod-1]

This prevents overflow.

=========================================================================================
                16. VERY IMPORTANT MOD VALUE
=========================================================================================

In CP you often see:

*/

const int MOD = 1e9 + 7;

/*
Why?

1. Large prime number
2. Fits in int
3. Good mathematical properties
4. Avoids collisions
5. Used in combinatorics

=========================================================================================
                    17. COMMON MISTAKES
=========================================================================================

1. USING pow() FOR MODULO

WRONG:
-----------------------------------------

        pow(a,b) % mod

Why wrong?
-----------------------------------------
1. floating point
2. overflow
3. precision issues

Correct:
-----------------------------------------

        modularPower(a,b,mod)

=========================================================================================

2. FORGETTING long long

WRONG:
-----------------------------------------

        int ans

Multiplication may overflow int.

Better:
-----------------------------------------

        long long ans

=========================================================================================

3. FLOATING POINT COMPARISON

WRONG:
-----------------------------------------

        if(pow(2,5) == 32)

=========================================================================================

4. FORGETTING MOD AFTER MULTIPLICATION

WRONG:
-----------------------------------------

        ans *= a

Correct:
-----------------------------------------

        ans = (ans * a) % mod

=========================================================================================
                    18. COMPLEXITY COMPARISON
=========================================================================================

Naive Exponentiation:
-----------------------------------------
Time:
        O(b)

Binary Exponentiation:
-----------------------------------------
Time:
        O(log b)

Example:

        2^1000000000

Naive:
-----------------------------------------
1 billion operations

Binary:
-----------------------------------------
~30 operations

Massive optimization.

=========================================================================================
                    19. IMPORTANT APPLICATIONS
=========================================================================================

1. Competitive Programming
2. Cryptography
3. RSA Encryption
4. Modular Inverse
5. Matrix Exponentiation
6. Fibonacci in log n
7. Number Theory
8. Hashing

=========================================================================================
                    20. POWER OF 2 TRICKS
=========================================================================================

Check if number is power of 2:
-----------------------------------------
*/

bool isPowerOfTwo(int n) {

    if(n <= 0) {
        return false;
    }

    return (n & (n-1)) == 0;
}

/*
Why?

Power of 2 has exactly one set bit.

Examples:

    8  = 1000
    7  = 0111

    8 & 7 = 0

=========================================================================================
                    21. IMPORTANT OBSERVATIONS
=========================================================================================

1.
-----------------------------------------
Left shift:

        x << n

means:

        x * (2^n)

2.
-----------------------------------------
Right shift:

        x >> n

means:

        x / (2^n)

for integers.

3.
-----------------------------------------
Binary exponentiation works because:
    exponent is processed bit by bit.

4.
-----------------------------------------
Every squaring creates powers of 2.

5.
-----------------------------------------
Binary representation is the heart of the algorithm.

=========================================================================================
                            22. FINAL MAIN FUNCTION
=========================================================================================
*/

int main() {

    cout << "pow examples:\n";
    powExamples();

    cout << "\nLeft shift:\n";
    leftShiftExamples();

    cout << "\nNaive power:\n";
    cout << naivePower(2,10) << endl;

    cout << "\nRecursive Binary Exponentiation:\n";
    cout << recursivePower(2,10) << endl;

    cout << "\nIterative Binary Exponentiation:\n";
    cout << iterativePower(2,10) << endl;

    cout << "\nModular Exponentiation:\n";
    cout << modularPower(2,10,1000000007) << endl;

    cout << "\nPower of 2 check:\n";
    cout << isPowerOfTwo(16) << endl;

    return 0;
}

/*
=========================================================================================
                                END OF NOTES
=========================================================================================
*/
