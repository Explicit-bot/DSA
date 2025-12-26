/*
when you want to convert a digit (an int like 0–9) into a character (like '0'–'9'), you add the character '0' to the digit. Let’s break this down clearly:
🔹 Why Add '0' to a Digit?
Characters in C++ have ASCII codes.
For example:
'0' has ASCII value 48
'1' is 49
...
'9' is 57


Only works for 0–9
If the int value is not in 0–9, the result will be a non-digit character.
    int digit = 12;
    char ch = digit + '0';  // ch = ASCII 60 → '<'

So always ensure:
    if (digit >= 0 && digit <= 9)
        char ch = digit + '0';

Convert	Code
int → char	        char ch = digit + '0'
char → int	        int  digit = ch - '0'

Reverse a number
*/
#include <iostream>

int main(){
    int n{};
    char rev[10];
    int i{};
    int r{};

    std::cout<<"Enter your no:"<<std::flush;
    std::cin>>n;

    while(n>0){
        r=n%10;
        rev[i]=r+'0';
        n=n/10;
        ++i;
    }
    rev[i]='\0';
    std::cout<<rev<<std::endl;
}
/*
ASCII
Digit-        0-9     48-57
lowercase-    a-z     97-122
Uppercase-    A-Z     65-9

•Integer Division Rule
Expression	            Result
int / int	            int
float / int	            float
int / float	            float
double / anything	    double

Example
5 / 2     → 2
5.0 / 2   → 2.5
5 / 2.0   → 2.5

Explicit Type Casting (Manual Conversion)
•means you manually force conversion using cast syntax.

Syntax
(type) expression

(float)22 → 22.0
22.0 / 7 → double-precision floating-point division
Result → 3.142857

⚠️ Important
(float)(22 / 7)   // ❌ WRONG → still 3.0
•Casting must be done before division, not after.

4️⃣ Implicit Type Conversion (Automatic)
C++ automatically converts smaller types to larger ones.
Examples
22.0 / 7     → double
22 / 7.0     → double

Why?
int is automatically promoted to double
Result becomes double

📌 Note
22.0/7 and 22/7.0 both give double
double has more precision than float

5️⃣ float vs double 
Type	    Size	    Precision
float	    4 bytes	    ~6–7 digits
double	    8 bytes	    ~15–16 digits

Rule in CP & Real Programs
✅ Prefer double
❌ Avoid float unless memory is critical

NaN stands for “Not a Number”.
0.0 / 0.0        → NaN
sqrt(-1)         → NaN
log(-5)          → NaN

• NaN is NOT equal to anything
    NaN == NaN   → false ❌
    
    Correct way to check NaN
    isnan(x)
    
    Never do:
    if (x == NaN)   // ❌ WRONG
*/
