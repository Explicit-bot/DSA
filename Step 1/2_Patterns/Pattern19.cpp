/*
Given an integer N, print the following pattern.
for example N=5
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5

*/

#include <iostream>
using namespace std;

void pattern22(int N){
    for(int i{};i<2*N-1;++i){
        int cnt{i};
        for(int j{};j<2*N-1;++j){
            if(i==cnt||j==cnt||i==2*N-cnt-2||j==2*N-cnt-2){
                cout<<N-cnt;
            }
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern22(P);

    return 0;
}
