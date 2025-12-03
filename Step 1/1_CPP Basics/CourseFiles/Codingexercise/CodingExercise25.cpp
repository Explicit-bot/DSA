/*
Find factors of a number
Write a loop to print factors of a given number
function Factors(int n)
output
cout<<i<<" "
*/

#include<iostream>

using namespace std;

void Factors(int n)
{
    
   for(int i{1}; i<=n; ++i)
   {
       if(n%i==0){
           std::cout<<i<<" ";
       }
   }
   
}
