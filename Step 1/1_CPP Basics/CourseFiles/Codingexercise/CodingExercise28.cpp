/*
Display Digits of a number
Write a loop to display Digits of a given number in reverse
function Digits(int n)
output
cout<<digit<<" "
*/
#include<iostream>

void Digits(int n)
{
    int digit;
    
    while(n>0){
        digit=n%10;
        n/=10;
        std::cout<<digit<<" ";
    }
}
