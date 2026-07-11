/*
----------------------------------------------------
1. GCC BUILT-IN FUNCTIONS
----------------------------------------------------
__builtin_popcount(num) - Returns number of set bits.
E.g:
14 =1110₂
__builtin_popcount(14) = 3
___________________________________________________________
__builtin_clz(num) - Returns number of leading zeros.
E.g:
For a 32-bit integer:
num = 14
Binary: 00000000 00000000 00000000 00001110
Leading zeros = 28
Therefore:
Bit Length = 32 - __builtin_clz(num)
____________________________________________________________
for a number with b bits:
popcount() : O(b)
clz()      : O(b)
For int, b = 32 (constant), hence O(1).

Why?
Modern CPUs often have dedicated instructions for these operations:
POPCNT (Population Count): counts the number of 1's in a word.
LZCNT (Leading Zero Count) or BSR (Bit Scan Reverse): used to determine the number of leading zeros or the position of the highest set bit.

So a compiler may translate
    __builtin_popcount(num);   ->     POPCNT eax, edi
Similarly,
    __builtin_clz(num);     ->      LZCNT eax, edi
Because these instructions execute in a fixed number of CPU cycles,we treat them as O(1)

----------------------------------------------------
2. Base conversion
----------------------------------------------------
• Decimal → Base b
Repeated division by b.
Read remainders bottom-up.

• Base b → Decimal
Σ(digit × b^position)

• Base A → Base B
Base A → Decimal → Base B

----------------------------------------------------
3. INT_MAX and INT_MIN
----------------------------------------------------
• INT_MAX & INT_MIN do not come from <iostream> or <bits/stdc++.h> on macOS/Clang.
They are actually defined inside: #include <climits>
• INT_MAX and INT_MIN Bounds:
    INT_MAX =  2147483647   (ends with 7)
    INT_MIN = -2147483648   (ends with 8)
As int so INT_MAX/10 would be 2147483647 not 214748364.7.So,when rev is near the boundary (INT_MAX/10 or INT_MIN/10),adding certain last digits would exceed the integer range.
Correct Overflow Checks:       
       // Positive limit
       if (rev > INT_MAX/10 || (rev == INT_MAX/10 && lastdigit > 7))
           return 0;

       // Negative limit
       if (rev < INT_MIN/10 || (rev == INT_MIN/10 && lastdigit < -8))
           return 0;
These checks ensure:
- Multiplying rev by 10 is safe
- Adding lastdigit will not push it outside the 32-bit range

----------------------------------------------------
4. Digital Root
----------------------------------------------------
Digital Root Formula: The repeated sum of the digits of a non-negative integer n until a single digit remains is called its digital root and is given by
    dr(n) = 0 if n=0 
    dr(n) = 1+(n−1)%9 for n>0
This follows from the fact that a number and the sum of its digits are 
congruent modulo 9.
*/
