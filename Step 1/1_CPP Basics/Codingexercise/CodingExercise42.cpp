/*
Pointer Arithmetic
Perform Arithmetic operations of pointer
*/
#include<iostream>
using namespace std;

void PointerArith()
{
    int A[]={2,4,6,8,10,12};
    int *p=A;
    
    // move pointer to next location to print 4
    ++p;
    cout<<*p;
    
    p=p+3; // pointer will be pointing on 10
    
    cout<<p[-4];   // complete this statement to print 2 without moving pointer
}
