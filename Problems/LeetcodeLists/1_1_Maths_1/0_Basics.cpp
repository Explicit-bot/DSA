/*
1. Extraction of digits
-----------------------------------------------------
• % (modulus) extracts the digit.
• / (division) removes the digit.

2. GCC BUILT-IN FUNCTIONS
-----------------------------------------------------
__builtin_popcount(num) - Returns number of set bits.
E.g:
1110₂
__builtin_popcount(14)
= 3

__builtin_clz(num) - Returns number of leading zeros.
E.g:
For a 32-bit integer:
num = 14
Binary: 00000000 00000000 00000000 00001110
Leading zeros = 28
Therefore:
Bit Length = 32 - __builtin_clz(num)

3. Base conversion
-----------------------------------------------------
• Decimal → Base b
Repeated division by b.
Read remainders bottom-up.

• Base b → Decimal
Σ(digit × b^position)

• Base A → Base B
Base A → Decimal → Base B

4. Alternating sign sum
------------------------------------------------------
    ans = digit - ans
Think as: 
    new expression = new digit - old expression
or
new digit becomes positive,everything else changes sign.

5. INT_MAX and INT_MIN
------------------------------------------------------
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
*/
