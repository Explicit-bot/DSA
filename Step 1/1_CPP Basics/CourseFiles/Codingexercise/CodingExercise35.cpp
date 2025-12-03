/*
Find Minimum Element in an Array
Write a loop to find the minimum element from Array
*/
#include<iostream>
using namespace std;

void Min()
{
    int A[]={8,4,12,37,36,25,-2,10,15,25};
    int min=A[0];
    
    //write a loop to find minimum number
    for(int i{};i<10;++i){
        if(min>A[i]){
            min=A[i];
        }
    }
    
    cout<<min;
}
