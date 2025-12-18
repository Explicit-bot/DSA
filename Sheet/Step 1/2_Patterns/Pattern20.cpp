/*
Given an integer N, print the following pattern.
for example N=5
*        * 
**      ** 
***    *** 
****  **** 
********** 
****  **** 
***    *** 
**      ** 
*        * 
*/

#include <iostream>
using namespace std;

void pattern20(int N){
    for(int i{};i<2*N-1;++i){
        int level=(i<N)?i:(2*N-2-i);

        //Star
        for(int j{};j<level+1;++j){
            cout<<"*";
        }

        //Space
        for(int j{};j<2*(N-level-1);++j){
            cout<<" ";
        }

        //Star
        for(int j{};j<level+1;++j){
            cout<<"*";
        }

        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern20(P);

    return 0;
}
