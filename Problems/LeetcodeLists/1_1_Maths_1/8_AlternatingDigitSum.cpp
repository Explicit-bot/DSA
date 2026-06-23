#include<iostream>
using namespace std;

int alternateDigitSum(int n) {
    int sum{};
    while(n){
        int digits=int(log10(n)+1);
        if(digits%2==1){
            sum+=n%10;
        }
        else{
            sum-=n%10;
        }
        n/=10;
    }
    return sum;
}

int alternateDigitSumSign(int n) {
    int sum = 0;
    int sign = 1;
    
    while (n) {
        sum += sign * (n % 10);
        sign *= -1;
        n /= 10;
    }   
    return -sign * sum;
}

int alternateDigitSumTrick(int n) {
    int ans = 0;

    while (n){
        ans = n % 10 - ans;
        n /= 10;
    }

    return ans;
}

int main(){
    int n{};
    cin>>n;

    cout<<alternateDigitSum(n)<<"\n";
    cout<<alternateDigitSumSign(n)<<"\n";
    cout<<alternateDigitSumTrick(n)<<"\n";
}
/*
    ans = digit - ans
Think as: 
    new expression = new digit - old expression
or
new digit becomes positive,everything else changes sign.

EXAMPLE : n = 1234
Digits extracted: 4 → 3 → 2 → 1
VISUAL INTERPRETATION
The algorithm builds nested subtraction:
4
3 - (4)
2 - (3 - 4)
1 - (2 - (3 - 4))
Expanding brackets gives:
1 - 2 + 3 - 4

WHY DOES IT WORK?
Suppose currently
ans = a - b + c - d

A new digit x arrives.
We do: ans = x - ans
Substitute old ans: ans = x - (a - b + c - d)
Expanding brackets: ans = x - a + b - c + d

Observations:
1. x becomes positive and so the first digit is always positive as no one to the left.
2. Every previous sign flips.
*/
