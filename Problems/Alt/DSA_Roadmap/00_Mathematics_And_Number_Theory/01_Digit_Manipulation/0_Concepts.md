# 01_Digit_Manipulation
## Extraction of digits
• % (modulus) extracts the digit.
• / (division) removes the digit.
So,whenever we perform:
    int digit = n % 10;     //we get the LAST digit.
    n /= 10;                //we REMOVE the LAST digit.     

Special focus on:
### Integer Division
123 / 10 = 12
5 / 2 = 2
1 / 10 = 0

### Modulo Operator
123 % 10 = 3
456 % 10 = 6

## Data Types
Understand:
int
long long

Know their limits:
INT_MAX   = 2147483647
INT_MIN   = -2147483648
LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775808


## Count Digits
# Method 1: Using loop
    if(n == 0){
        return 1;
    }
    while(n > 0){
        count++;
        n /= 10;
    }

# Method 2: Using log
    digits = floor(log10(n)) + 1

# Mathematical Functions
Header: #include <cmath>

Functions to know:
abs(-15)      // 15
sqrt(49)      // 7
pow(2,10)     // 1024
log10(1000)   // 3
floor(3.9)    // 3
ceil(3.1)     // 4

# STL Functions
## algorithm
Header: #include <algorithm>

Functions:
reverse(v.begin(), v.end());
max(a,b);
min(a,b);

## string
Header: #include <string>

Functions:
to_string()
stoi()
stoll()

Examples:
string s = to_string(123);
int x = stoi("123");
long long y = stoll("123456789123");

# Important Edge Cases
Always check:
* n = 0
* negative numbers
* integer overflow
* leading zeroes disappearing after reversal

Examples:
1200 -> 21
100 -> 1
10 -> 1
