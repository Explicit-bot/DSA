/*
Finding maximum of 3 numbers
Write nested if conditions to find maximum of three numbers
parameters of Max3(int a, int b, int c)
a,b and c are 3 numbers
output
print greatest number
*/

#include<iostream>

void Max3(int a,int b,int c)
{
    if(b>a && b>c){
        
        std::cout << b; 
    }
    else{
        if(a>c){
            std::cout<<a;
        }
        else{
            std::cout<<c;
        }
    }

}
