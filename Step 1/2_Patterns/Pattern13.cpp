/*
Given an integer N, print the following pattern.
for example N=5
ABCDE
ABCD
ABC
AB
A
*/

#include <iostream>
using namespace std;

void pattern15(int N){
    
    for(int i{};i<N;++i){
        char chr='A';
        for(int j{};j<N-i;++j){
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

    pattern15(P);

    return 0;
}
