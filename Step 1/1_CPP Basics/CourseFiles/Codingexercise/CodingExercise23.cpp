/*
Sum of first N natural number
Write a loop to find sum of first n natural number
function SumOfN(int n)
output
cout<<sum
*/
#include<iostream>

void SumOfN(int n)
{
    int sum=0;
    
    for(int i{};i<=n;++i)
    {
        sum += i;
        
    }

    std::cout<<sum;
}
