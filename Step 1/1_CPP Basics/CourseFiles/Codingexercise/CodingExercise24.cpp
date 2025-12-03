/*
Find Factorial of number
Write a loop to find factorial of number
function Factorial(int n)
output
cout<<fact
*/
#include<iostream>

void Factorial(int n)
{
    int fact=1;
    
    //write a loop for finding factorial on n
    for(int i{1};i<=n;++i)
    {
        fact*=i;
    }
    
    std::cout<<fact;
    
}
