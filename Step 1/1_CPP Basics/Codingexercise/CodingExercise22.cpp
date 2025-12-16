/*
Arithmetic operations using switch
Write switch case for performing Arithmetic operations
function ArithOpt(int x, int y, int choice)
x and y are 2 values
choice
1 -- Add 2 number
2 -- Subtract 2 number
3 -- Multiply 2 number
4 -- Divide 2 numbers
*/

#include<iostream>

void ArithOpt(int x,int y, int choice)
{
    
    switch(choice){
        case 1:
            std::cout<<x+y;
            break;
        case 2:
            std::cout<<x-y;
            break;
        case 3:
            std::cout<<x*y;
            break;
        case 4:
            std::cout<<x/y;
            break;
    }
}
