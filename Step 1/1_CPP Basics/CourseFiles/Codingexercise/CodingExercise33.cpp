/*
Sum of all Elements of Array
Find the Sum of all the elements in an Array
function Sum( )
A -- Array of elements
n -- number of elements
output
cout<<sum;
*/

#include<iostream>
using namespace std;

void Sum()
{
    int A[]={2,4,11,8,10,15,13},n=7;
    int sum=0;
    
    //add all elements from Array A to sum
    //print sum
    
    for(int i{};i<7;++i){
        sum+=A[i];
    }
    cout << sum;
}
