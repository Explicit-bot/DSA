/*
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

void pattern18(int N){
    for(int i{};i<N;++i){
        char chr='A'+N-1-i;
        for(int j{};j<i+1;++j){
            cout<<chr;
            ++chr;
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern18(P);

    return 0;
}
