/*
Given an integer N, print the following pattern.
for example N=5
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

#include <iostream>
using namespace std;

void pattern13(int N){
    int cnt=1;
    for(int i{};i<N;++i){
        for(int j{};j<i+1;++j){
            cout<<cnt<<" ";
            ++cnt;
        }
        cout<<"\n";
    }
}


int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern13(P);

    return 0;
}
