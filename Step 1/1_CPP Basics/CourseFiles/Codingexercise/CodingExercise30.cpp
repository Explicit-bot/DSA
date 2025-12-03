/*
Reverse a Number
Write a loop for Reversing the Digits of a Number
function Reverse(int n)
output
cout<<rev
*/
#include<iostream>

void Reverse(int n)
{
    int rev=0;
    int m=n;
    int r;
    
   while(n>0){
       r=n%10;
       n/=10;
       rev=rev*10+r;
   }
   std::cout<<rev;
}
