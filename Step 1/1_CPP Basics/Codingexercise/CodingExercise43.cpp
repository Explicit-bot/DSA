/*
unction for Adding 2 numbers
Write a function for adding 2 Number.
you have to write a complete function as explained on white board.
Main is calling a function add(10,5) and you have to implement add() function
function should return the result
*/
#include<iostream>
using namespace std;


//write a add() function here to add 2 numbers
int add(int x, int y){
    int z;
    z=x+y;
    return z;
}

void main()
{
    cout<<add(10,5);
}
