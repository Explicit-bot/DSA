/*
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.

A prime number is a number which has no divisors except 1 and itself.
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
        int cnt{};
        for(int i{1};i*i<=n;++i){
            if(n%i==0){
                ++cnt;
                if(n/i!=i){
                    ++cnt;
                }
            }
        }
        return cnt==2;
}


int main(){
    int num{};

    cout<<"Enter no. you want to check:";
    cin>>num;

    bool ret=isPrime(num);
    if(ret==true){
        cout<<num<<" is Prime.";
    }
    else{
        cout<<num<<" is not Prime.";
    }

    return 0;
}
