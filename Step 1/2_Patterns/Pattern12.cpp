/*
Given an integer N, print the following pattern.
for example N=5
1        1
12      21
123    321
1234  4321
1234554321
*/

#include <iostream>
using namespace std;

void pattern12(int N){
    int cnt{1};
    for(int i{};i<N;++i){
        //number
        for(int j{};j<i+1;++j){
            cout<<cnt;
            ++cnt;
        }

        //space
        for(int j{};j<2*(N-i-1);++j){
            cout<<" ";
        }

        //number
        for(int j{};j<i+1;++j){
            --cnt;
            cout<<cnt;
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern12(P);

    return 0;
}
