/*
***
Given an integer N, print the following pattern.
for example N=5
    0 1 2 3 4
0   * * * * *
1   *       *
2   *       *
3   *       *
4   * * * * *
*/

#include <iostream>
using namespace std;

void pattern10(int n){
    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            if(i==0||i==n-1||j==0||j==n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern10(P);

    return 0;
}
