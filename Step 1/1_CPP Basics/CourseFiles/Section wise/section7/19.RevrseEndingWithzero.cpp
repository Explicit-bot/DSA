/*
when you want to convert a digit (an int like 0–9) into a character (like '0'–'9'), you add the character '0' to the digit. Let’s break this down clearly:

🔹 Why Add '0' to a Digit?
Characters in C++ have ASCII codes.
For example:
'0' has ASCII value 48
'1' is 49
...
'9' is 57

So, if you have:
    int digit = 5;
    char ch = digit + '0'; // ➜ ch becomes '5'

You're shifting the digit 5 up to the correct ASCII code for '5':
 5 + 48 = 53  → which is ASCII for '5'

 🔸 Example Code
#include <iostream>
using namespace std;

int main() {
    int digit = 7;
    char ch = digit + '0';

    cout << "Digit: " << digit << endl;
    cout << "As character: " << ch << endl;
    return 0;
}

🟢 Output:
Edit
Digit: 7
As character: 7

🔸 Opposite: Convert '7' to 7
You subtract '0':

char ch = '7';
int digit = ch - '0'; // ➜ digit becomes 7
This is useful when parsing strings with digits.

⚠️ Edge Case: Only works for 0–9
If the int value is not in 0–9, the result will be a non-digit character.
    int digit = 12;
    char ch = digit + '0';  // ch = ASCII 60 → '<'

So always ensure:
    if (digit >= 0 && digit <= 9)
        char ch = digit + '0';

✅ Summary
Convert	Code
int → char	ch = digit + '0'
char → int	digit = ch - '0'

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
