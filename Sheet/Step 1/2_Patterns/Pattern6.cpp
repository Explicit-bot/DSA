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

void pattern6(int n){
    for(int i{};i<n;++i){
        //Space
        for(int j{};j<i;++j){
            cout<<" ";
        }

        //Star
        for(int j{};j<2*(n-i-1)+1;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int n;

    cout<<"Enter n:";
    cin>>n;

    pattern6(n);
}
