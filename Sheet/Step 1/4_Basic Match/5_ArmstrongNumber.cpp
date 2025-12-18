/*
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.
*/
#include <iostream>
using namespace std;

bool isArmstrong(int n){
    int sum{};
    int temp=n;
    int cnt{};

    while(temp>0){
        cnt=log10(n)+1;
        int ld=temp%10;
        sum=sum + pow(ld,cnt);
        temp/=10;
    }

        return sum==n;
}

int main(){
    int num{};

    cout<<"Enter the number:";
    cin>>num;

    bool ret=isArmstrong(num);
    if(ret==true){
        cout<<num<<" is an Armstrong Number.";
    }
    else{
        cout<<num<<" is not an Armstrong Number.";
    }


    return 0;
}
