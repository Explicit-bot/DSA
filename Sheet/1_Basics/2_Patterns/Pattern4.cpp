/*
****
Given an integer N, print the following pattern.
for example N=5
E
DE
CDE
BCDE
ABCDE
*/

#include <iostream>
using namespace std;

void pattern4(int n){
    for(int i{};i<n;++i){
        char ch='A'+n-1-i;
        for(int j{};j<i+1;++j){
            cout<<ch;
            ++ch;
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern4(P);

    return 0;
}

