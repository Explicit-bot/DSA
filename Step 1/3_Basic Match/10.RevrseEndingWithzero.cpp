/*
***
Given an integer N, reverse its digits while preserving trailing zeroes in the reversed output.
If the number is negative, preserve the negative sign.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;


// Brute Force Approach
vector<char> reverseVectorChar(int n){

    vector<char> rev{};

    if(n == 0){
        rev.push_back('0');
        return rev;
    }

    if(n < 0){
        n = -n;
    }

    while(n > 0){

        int rem = n % 10;

        rev.push_back(rem + '0');

        n /= 10;
    }

    return rev;
}


// Better Approach
string reverseString(int n){

    if(n == 0){
        return "0";
    }

    string rev = "";

    bool neg = false;

    if(n < 0){
        neg = true;
        n = -n;
    }

    while(n > 0){

        rev += char((n % 10) + '0');

        n /= 10;
    }

    if(neg){
        rev = "-" + rev;
    }

    return rev;
}


// Optimal Approach
vector<int> reverseVectorInt(int n){

    vector<int> rev{};

    if(n == 0){
        rev.push_back(0);
        return rev;
    }

    if(n < 0){
        n = -n;
    }

    while(n > 0){

        rev.push_back(n % 10);

        n /= 10;
    }

    return rev;
}


int main(){

    int n;

    cout << "Enter number: ";
    cin >> n;


    vector<char> brute = reverseVectorChar(n);

    cout << "\nBrute Force (vector<char>): ";

    if(n < 0){
        cout << "-";
    }

    for(char x : brute){
        cout << x;
    }


    string better = reverseString(n);

    cout << "\nBetter (string): ";

    cout << better;


    vector<int> optimal = reverseVectorInt(n);

    cout << "\nOptimal (vector<int>): ";

    if(n < 0){
        cout << "-";
    }

    for(int x : optimal){
        cout << x;
    }

    return 0;
}
/*
when you want to convert a digit (an int like 0–9) into a character (like '0'–'9'), you add the character '0' to the digit. Let’s break this down clearly:
🔹 Why Add '0' to a Digit?
Characters in C++ have ASCII codes.
For example:
'0' has ASCII value 48
'1' is 49
...
'9' is 57
ASCII
Digit-        0-9     48-57
lowercase-    a-z     97-122
Uppercase-    A-Z     65-90

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
*/
