/*
Given an integer N, print the following pattern.
for example N=5
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include <iostream>
using namespace std;

//Without levels
void pattern8(int n){
    for(int i{};i<2*n-1;++i){
        int spaces=(i<n)?(n-i-1):(i-n+1);
        int star=(i<n)?(2*i+1):(2*(2*n-i-2)+1);
        //space
        for(int j{};j<spaces;++j){
            cout<<" ";
        }
        //star
        for(int j{};j<star;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

//using levels
void Pattern8(int n){
    for(int i{};i<2*n-1;++i){
        int level=(i<n)? i:(2*n-i-2);

        //Space
        for(int j{};j<n-level-1;++j){
            cout<<" ";
        }

        //star
        for(int j{};j<2*level+1;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int n;

    cout<<"Enter n:";
    cin>>n;

    //pattern8(n);
    Pattern8(n);
}
