/*
Function to calculate m power n.
Write a function for calculating m power n.
Main is calling a function pow(2,5) and you have to implement pow(m,n) function
function should return the result
*/
#include<iostream>
using namespace std;


//write a pow() function here 
int pow(int m,int n){
    int p{1};
    for(int i{};i<n;++i){
        p=p*m;
    }
    return p;
}

void main()
{
    cout<<pow(2,5);
}

