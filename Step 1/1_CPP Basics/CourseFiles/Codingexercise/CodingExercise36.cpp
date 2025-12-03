/*
Count number of negative and positive numbers in Array
Write a loop to count number of positive and negative numbers separately in a Array
*/

#include<iostream>
using namespace std;

void Count()
{
    int A[]={3,5,-2,9,-4,10,-24,19,81,-7,12,13};
    int pcount=0;
    int ncount=0;
    
    // write a loop to count positive and negative numbers
    for(int x:A)
    {
        if(x<0)
            ncount++;
        else
            pcount++;
    }
    
    cout<<pcount<<" "<<ncount;
}
