/*
Maximum of 2 Numbers
Write conditional statement to find Maximum of 2 numbers
Parameters
x and y are 2 numbers
Expected output: print maximum number, just print a number
example
cout<<x;     or   cout<<y;
*/

#include<iostream>

void max(int x,int y)
{
     if(x>y){
        std::cout << x ;
    }
    
    else{
         std::cout << y ;
    }
   
}
