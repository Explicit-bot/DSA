/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Constraints:
-2^31 <= x <= 2^31 - 1
Follow up: Could you solve it without converting the integer to a string?
*/

#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int n) {
    int revn{};
    int num=n;

    while(n!=0){
        int ld=n%10;
        if(revn<INT_MIN/10||revn>INT_MAX/10){
            return 0;
        }
        revn=(revn*10)+ld;
        n/=10;
    }

    /*
     if(num!=revn){
        return false;
    }
    return true;
    Instead of this we can use:
    */

    return num==revn;
}

int main(){
    int num{};

    cout<<"Enter no. you want to check:";
    cin>>num;

    bool ret=isPalindrome(num);
    if(ret==true){
        cout<<num<<" is a palindrome.";
    }
    else{
        cout<<num<<" is not a palindrome.";
    }

    return 0;
}
