/*
***
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

bool ispal(int N){
    int revn{};
    int num{N};  //***
    while(N!=0){
        int ld=N%10;

        if(revn>(INT_MAX/10)||(revn==INT_MAX&&ld>7)){
            return 0;
        }
        if(revn<(INT_MIN/10)||(revn==INT_MIN&&ld<-8)){
            return 0;
        }

        revn=revn*10 + ld;
        N/=10;
    }
    if(num>=0){
        return revn==num;
    }
    else{
        return false;
    }
}


int main(){
    int N{};

    cout<<"Enter your no.";
    cin>>N;

    if(ispal(N)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
}

