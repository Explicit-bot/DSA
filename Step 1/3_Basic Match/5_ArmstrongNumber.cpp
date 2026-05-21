/*
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.
*/

#include <iostream>
using namespace std;

bool isarmstrong(int n){

    int power=int(log10(n)+1);
    int temp=n;
    int sum{};
    while(temp>0){
        sum+=pow(temp%10,power);
        temp/=10;
    }
    return sum==n;
}

int main(){
    int num{};

    cout<<"Enter the number:";
    cin>>num;

    if(isarmstrong(num)){
        cout<<num<<" is an Armstrong Number.";
    }
    else{
        cout<<num<<" is not an Armstrong Number.";
    }

    return 0;
}
