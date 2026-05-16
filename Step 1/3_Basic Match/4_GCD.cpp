/*
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.
*/
#include <iostream>
using namespace std;

//Brutte Force approach
int findgcd(int n1,int n2){
    int gcd{1};
    for(int i{};i<min(n1,n2);++i){
        if(n1%i==0 && n2%i==0){
            gcd=i;
        }
    }
    return gcd;
}

//Better Approach
int findGcd(int n1,int n2){
    for(int i{min(n1,n2)};i>0;--i){
        if(n1%i==0 && n2%i==0){
           return i;
        }
    }
    return 1;
}

//Subtraction-based Euclidean Algorithm 
int FindGCD(int n1,int n2){
    while(n1!=n2){
        if(n1>n2){
            n1-=n2;
        }
        else if(n2>n1){
            n2-=n1;
        }
    }
    return n1;
}
//Optimal Approach(Modulo-based Euclid)
int FINDGCD(int a, int b){
    while(b != 0){
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}



int main(){
    int n1{},n2{};

    cout<<"Enter the numbers:";
    cin>>n1>>n2;

    
    cout<<"Brute Force Approach:"<<findgcd(n1,n2)<<"\n";
    cout<<"Better Approach:"<<findGcd(n1,n2)<<"\n";
    cout<<"Subtraction-based Euclid:"<<FindGCD(n1,n2)<<"\n";
    cout<<"Optimal Approach(Modulo-based Euclid):"<<FINDGCD(n1,n2)<<"\n";
    
    return 0;
}


/*

1) Modulo-based Euclid
Time: O(log(min(n1, n2)))

2) Reverse brute force (min → 1)
Time: O(min(n1, n2))

3) Brute force (1 → min)
Time: O(min(n1, n2))

4) Subtraction-based Euclid
Time: O(max(n1, n2))

*/
