/*
Problem Statement: Given an integer N, return the number of digits in N.
*/

#include <iostream>
using namespace std;

//Brute Force approach
int countdigit(int N){
    int cnt{};
    
    while(N>0){
    ++cnt;
    N/=10;
    }

    return cnt;
}

//Optimal approach
int CountDigit(int N){
    int cnt=int(log10(N)+1);

    return cnt;
}

int main(){
    int number{};

    cout<<"Enter a number:";
    cin>>number;

    //Using brute force
    int digit=countdigit(number); 
    cout<<"Number of digits in the given number are "<<digit;
    cout<<"\n";

    //Using Optimal approach
    digit=CountDigit(number); 
    cout<<"Number of digits in the given number are "<<digit;
    cout<<"\n";

    return 0;
}
