/*
Given an integer N, print the following pattern.
for example N=5
A
AB
ABC
ABCD
ABCDE
*/

#include <iostream>
using namespace std;

void pattern14(int N){
    
    for(int i{};i<N;++i){
        char chr='A';
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

    pattern14(P);

    return 0;
}
