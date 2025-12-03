/*
Function Overloading for Sum of Numbers
Write 3 Overloaded functions for
1. Sum of 2 integers
2. Sum of 2 Floats
3. Sum of 3 integers
Main is calling 3 functions, implement all 3 functions
*/
#include<iostream>
using namespace std;


//1. write a sum() function here to add 2 integer
int sum(int x,int y){
    return x+y;
}
//2. write a sum() function here to add 2 floats
float sum(float x, float y){
    return x+y;
}
//3. write a sum() function here to add 3 integer
int sum(int x,int y,int z){
    return x+y+z;
}


void main()
{
    cout<<sum(10,5);
    cout<<sum(12.9f,8.3f);
    cout<<sum(10,20,30);
}
