/*
Check if Number is Odd or Even
Write conditional statement for checking is a number is positive or negative
function OddEven is taking parameter
parameter
n - a integer number
Output
cout<<"odd"
cout<<"even"
*/
#include<iostream>

void OddEven(int n)
{
    
   if(n%2==0){
       std::cout << "even";
   }
   else{
       std::cout<<"odd";
   }
}

