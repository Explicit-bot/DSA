/*
Given an integer N, print the following pattern.
for example N=5
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/

#include <iostream>
using namespace std;

void pattern4(int N){
    for(int i{};i<N;++i){
        for(int j{};j<i+1;++j){
            cout<<i+1<<" ";
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
