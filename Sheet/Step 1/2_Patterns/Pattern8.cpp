/*
Given an integer N, print the following pattern.
for example N=5
*********
 *******
  *****
   ***
    *
*/

#include <iostream>
using namespace std;

void pattern8(int N){
    for(int i{};i<N;++i){
        //Space
        for(int j{};j<i;++j){
            cout<<" ";
        }

        //star
        for(int j{};j<2*(N-i)-1;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern8(P);

    return 0;
}
