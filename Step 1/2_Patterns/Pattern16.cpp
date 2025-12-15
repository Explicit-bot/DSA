/*
Given an integer N, print the following pattern.
for example N=5
A
BB
CCC
DDDD
EEEEE
*/

#include <iostream>
using namespace std;

void pattern16(int N){
    char chr='A';
    for(int i{};i<N;++i){
        for(int j{};j<i+1;++j){
            cout<<chr;
        }
        ++chr;
        cout<<"\n";
    }
}


int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern16(P);

    return 0;
}
