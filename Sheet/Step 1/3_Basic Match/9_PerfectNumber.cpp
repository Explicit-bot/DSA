/*
***
💡 What is a Perfect Number?
A perfect number is a positive integer that is equal to the sum of all its proper divisors (excluding itself).
⸻
🔹 Definition:
A number n is perfect if:
sum of divisors of n (excluding n) = n
*/

#include<iostream>
using namespace std;

bool isperfectnumber(int n){
    if(n<=1){
        return false;
    }

    int sum{1};  //as 1 is always a proper divisor.
    for(int i{2};i*i<=n;++i){
        if(n%i==0){
            sum+=i;
            if(n/i!=i){
                sum+=(n/i);
            }
        }
    }

    return sum==n;
}

int main(){
    int n{};

    cout<<"Enter your no.:";
    cin>>n;

    if(isperfectnumber(n)){
        cout<<n<<" is a perfect number.";
    }
    else{
        cout<<n<<" is not a perfect number.";
    }
}
