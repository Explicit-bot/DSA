/*
Function for Finding maximum of 3 numbers
Write a function for Maximum of 3 Numbers.
Main is calling a function Max(7,10,5) and you have to implement Max() function
function should return Maximum of 3 number
*/
#include<iostream>
using namespace std;


int Max(int a,int b,int c){
    if(a>b && a>c){
        return a;
    }
    else if(b>c){
        return b;
    }
    else {
        return c;
    }
    
}

void main()
{
    cout<<Max(7,10,5);
}
