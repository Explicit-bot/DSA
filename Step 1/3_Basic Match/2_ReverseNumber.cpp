/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 
Constraints:
-2^31 <= x <= 2^31 -1

Note: If a number has trailing zeros, then its reverse will not include them. For e.g , reverse of 10400 will be 401 instead of 00401.
*/

#include <iostream>
#include <climits>
/*
✅ Why do we include <climits>?
Because your code uses:
INT_MAX
INT_MIN
These two constants do NOT come from <iostream> or <bits/stdc++.h> on macOS/Clang.
They are actually defined inside:
#include <climits>
*/
using namespace std;

int reversenumber(int x){
        int rev{};

        while(x!=0){
        int lastdigit=x%10;         //When x is negative, % returns a negative remainder.

        //Positive
        if(rev>INT_MAX/10||(rev==INT_MAX/10&&lastdigit>7)){
            return 0;
        }

        //Negative
        if(rev<INT_MIN/10||(rev==INT_MIN/10&&lastdigit<-8)){
            return 0;
        }
        rev=(rev*10)+lastdigit;
        x/=10;
        }
        return rev;
}

int main(){
    int num{};

    cout<<"Enter the number:";
    cin>>num;

    int revN=reversenumber(num);

    cout<<"Reverse of the number is :"<<revN<<"\n";

    return 0;
}


/*
Here’s your code again for reference:

int reversenumber(int x){
    int rev{};
    while(x!=0){
        int lastdigit = x % 10;
        rev = (rev * 10) + lastdigit;

        if(rev < INT_MIN || rev > INT_MAX){
            return 0;
        }

        x /= 10;
    }
    return rev;
}

Now, a few key points to fix or understand:

⚠️ 1. The overflow check is in the wrong place
You’re checking for overflow after the multiplication and addition, but by that time, overflow might’ve already happened!
So your check won’t reliably catch it because overflow in C++ is undefined behavior — once it happens, it’s too late.

👉 Correct way:
Check before updating rev whether multiplying and adding will overflow.


    -------------------- Reverse Integer: Overflow Logic Summary --------------------

    1) Extracting Digits:
       Using `lastdigit = x % 10` works for both positive and negative values.
       For negative numbers, the remainder is also negative:
           -123 % 10  ->  -3
       So reversed digits of a negative integer will also be negative.

    2) Why Overflow Happens:
       Reversing an integer requires the step:
           rev = rev * 10 + lastdigit;
       This multiplication and addition can cause signed 32-bit overflow.
       Since signed overflow is undefined behavior, we MUST check BEFORE updating `rev`.

    3) INT_MAX and INT_MIN Bounds:
       INT_MAX =  2147483647   (ends with 7)
       INT_MIN = -2147483648   (ends with 8)

       When rev is near the boundary (INT_MAX/10 or INT_MIN/10), 
       adding certain last digits would exceed the integer range.

    4) Correct Overflow Checks:
       Before updating rev:

       // Positive limit
       if (rev > INT_MAX/10 || (rev == INT_MAX/10 && lastdigit > 7))
           return 0;

       // Negative limit
       if (rev < INT_MIN/10 || (rev == INT_MIN/10 && lastdigit < -8))
           return 0;

       These checks ensure:
       - Multiplying rev by 10 is safe
       - Adding lastdigit will not push it outside the 32-bit range

    5) Why -8?
       INT_MIN ends with 8.
       Since negative remainders come from x % 10,
       possible last digits are -1 to -9.
       The smallest safe last digit when rev == INT_MIN/10 is -8.
       Anything less (like -9) would overflow.


    ------------------------ Reverse Integer: INT_MAX Overflow Note ------------------------
    INT_MAX Value:
       The maximum 32-bit signed integer is:
           INT_MAX = 2147483647     (10 digits)

    Reversing INT_MAX:
       Reversing the digits produces:
           7463847412     (also 10 digits, but much larger)

    Overflow Explanation:
       A signed 32-bit integer can store values only up to:
           +2147483647

       The reversed value:
           7463847412  >  INT_MAX

    Therefore, reversing INT_MAX will ALWAYS overflow.
    ------------------------------------------------------------------------------
*/

