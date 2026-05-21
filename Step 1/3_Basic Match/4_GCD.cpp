/*
***
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.
Theorems for GCD:-
GCD(a,b) = GCD(a-b,b)
GCD(a,b) = GCD(b, a%b)
*/

#include <iostream>
using namespace std;

//Traversal approach - Brute
int findgcdtrav(int n,int m){
    int gcd{1};
    for(int i{1};i<=min(n,m);++i){   //can't initialize i by zero 
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
    return gcd;
}

//Reverse traversal Approach - Better brute
int findgcdrevtrav(int n,int m){
    for(int i{min(n,m)};i>0;--i){
        if(n%i==0 && m%i==0){
           return i;
        }
    }
    return 1;
}

//Subtraction-based Euclidean Algorithm - Better approach (just worst case problem)
int findgcdSubtraction(int n,int m){
    while(n!=m){
        if(n>m){
            n-=m;
        }
        else if(m>n){
            m-=n;
        }
    }
    return n;
}

//Modulo-based Euclid approach - Most optimal
int findgcdmodulo(int n,int m){
    while(m!=0){
        int rem=n%m;
        n=m;
        m=rem;
    }
    return n;
}

int main(){
    int n1{},n2{};

    cout<<"Enter the numbers:";
    cin>>n1>>n2;

    
    cout<<"Brute Force Approach:"<<findgcdtrav(n1,n2)<<"\n";
    cout<<"Better Approach:"<<findgcdrevtrav(n1,n2)<<"\n";
    cout<<"Subtraction-based Euclid:"<<findgcdSubtraction(n1,n2)<<"\n";
    cout<<"Optimal Approach(Modulo-based Euclid):"<<findgcdmodulo(n1,n2)<<"\n";
    
}


/*
1) Modulo-based Euclid 
Time: O(log(min(n1, n2)))
In Euclid’s algorithm:Every 1 or 2 iterations reduce the numbers by at least half.
THIS is why logarithm appears.

2) Reverse brute force (min → 1) worst case is min -> 1 normally stops early
Time: O(min(n1, n2))

3) Brute force (1 → min) always goes till min
Time: O(min(n1, n2))

4) Subtraction-based Euclid - conceptually better because reduces the problem
Time: O(max(n1, n2))
*/
