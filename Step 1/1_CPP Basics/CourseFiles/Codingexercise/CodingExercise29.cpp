/*
Check if a number is Armstrong Number
Write a loop to find sum of cubes of digits of a number and check if its Armstrong number
function Armstrong(int n)
ARMSTRONG NUMBER - if the sum of cubes of digits of a number is equal to a number
output
cout<<"armstrong"
cout<<"not a armstrong"
*/
#include<iostream>

void Armstrong(int n)
{
    int sum=0,r;
    int m=n;
    
    
    while(n>0){
        r=n%10;
        n/=10;
        sum+=std::pow(r,3);
    }
    
     if(sum==m)
        std::cout<<"armstrong";
    else
        std::cout<<"not armstrong";
}
