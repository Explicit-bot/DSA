/*
PROBLEM: Add to make Positive
An array A of length N is called GOOD if the sum of all
its elements is non-negative, i.e.,
A1 + A2 + ... + AN ≥ 0

TASK
Find the minimum non-negative integer X such that
if you add X to each element of the array, the array
becomes GOOD.

That is, create a new array B of length N where:

Bi = Ai + X

and ensure:

B1 + B2 + ... + BN ≥ 0

----------------------------------------------------
📥 INPUT FORMAT
----------------------------------------------------
• The first line contains a single integer T,
  the number of test cases.

For each test case:
• The first line contains a single integer N.
• The second line contains N integers:
  A1, A2, ..., AN

----------------------------------------------------
📤 OUTPUT FORMAT
----------------------------------------------------
For each test case, output on a new line the minimum
non-negative integer X required.

----------------------------------------------------
📊 CONSTRAINTS
----------------------------------------------------
1 ≤ T ≤ 100  
1 ≤ N ≤ 100  
-100 ≤ Ai ≤ 100  

----------------------------------------------------
📝 NOTES
----------------------------------------------------
• X must be a non-negative integer.
• The same X is added to every element.
• Print one answer per test case.
====================================================
*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    //For Test case 
    int T{};
    cin>>T;
    //For test cases input
    while(T>0){
        --T;    //For looping T times
        
        //For length of array
        int N{};
        cin>>N;
        
        //Array declaration
        int arr[N];
        for(int i{};i<N;++i){
            cin>>arr[i];
        }
        
        int sum{};
        for(int i{};i<N;++i){
            sum+=arr[i];
        }
        
        if(sum>=0){
            cout<<0<<"\n";
        }
        else{
            int X=ceil((double)(-sum)/N);         //ceil(a / b) = (a + b - 1) / b
            cout<<X<<"\n";
        }
    }

    return 0;
}

