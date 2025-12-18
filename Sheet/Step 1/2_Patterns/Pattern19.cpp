/*
Given an integer N, print the following pattern.
for example N=5
**********
****  ****
***    ***
**      **
*        *
**      **
***    *** 
****  ****
**********
*/

#include <iostream>
using namespace std;

void pattern19(int N){
    for(int i{};i<2*N-1;++i){
        int level=(i<N)?i:(2*N-2-i);

        //Star
        for(int j{};j<N-level;++j){
            cout<<"*";
        }

        //space
        for(int j{};j<2*level;++j){
            cout<<" ";
        }

        //star
        for(int j{};j<N-level;++j){
            cout<<"*";
        }

        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern19(P);

    return 0;
}
