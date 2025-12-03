/*
Function Template for Finding Maximum Number
Write a Function Template for finding Maximum of 2 numbers
*/
#include<iostream>
using namespace std;

//write a Max() function template for 2 numbers
template <class M>
M Max(M x,M y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}
void main()
{
    cout<<Max(10,5)<<endl;
    cout<<Max(12.5f,17.3f);
}
