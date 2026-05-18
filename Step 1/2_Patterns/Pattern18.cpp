/*
Given an integer N, print the following pattern.
for example N=5
* * * * *
*       *
*       *
*       *
* * * * *
*/

#include <iostream>
using namespace std;

void pattern21(int N){
    for(int i{};i<N;++i){
        for(int j{};j<N;++j){
            if(i==0||j==0||i==N-1||j==N-1){
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

    pattern21(P);

    return 0;
}
