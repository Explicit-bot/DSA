#include<iostream>
#include<vector>
using namespace std;

//O(logn)
int AddDigitsBrute(int num){
    if(num<=9) return num;
    while(num>9){
        int tempsum{};
        while(num>0){
            tempsum+=num%10;
            num/=10;
        }
        num=tempsum;
    }
    return num;
}

//O(1)
int AddDigitsOptimal(int nums){
    if(nums==0){
        return 0;
    }
    
    return 1+(nums-1)%9;
}

int main(){
    int n{};
    cin>>n;

    cout<<AddDigitsBrute(n)<<" ";
    cout<<AddDigitsOptimal(n)<<" ";
}

/*
Digital Root Formula: The repeated sum of the digits of a non-negative integer n until a single digit remains is called its digital root and is given by
    dr(n) = 0 if n=0 
    dr(n) = 1+(n−1)%9 for n>0
This follows from the fact that a number and the sum of its digits are congruent modulo 9.
*/
