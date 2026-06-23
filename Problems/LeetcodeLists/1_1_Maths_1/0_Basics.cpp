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
*/
