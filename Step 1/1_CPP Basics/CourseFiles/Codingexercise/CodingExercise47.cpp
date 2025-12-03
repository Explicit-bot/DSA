/*
Function Overloading for Min of Numbers
Write Overloaded Functions for finding Minimum of numbers.
implement following functions
1. Minimum of 2 integers
2. Minimum of 3 integers
3. Minimum of 2 floats
*/
#include<iostream>
using namespace std;


//1 write a min() function here to Min of 2 integers
int min(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}
//2 write a min() function here to Min of 3 integers
int min(int x,int y,int z){
    if(x<y && x<z){
        return x;
    }
    else if(y<z){
        return y;
    }
    else{
        return z;
    }
}
//3 write a min() function here to Min of 2 floats
float min(float x,float y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

void main()
{
    cout<<min(10,5);
    cout<<min(12,7,9);
    cout<<min(18.0f,9.0f);
}
