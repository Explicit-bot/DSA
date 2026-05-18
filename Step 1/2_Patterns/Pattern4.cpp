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

void pattern4(int n){
    for(int i{};i<n;++i){
        for(int j{};j<i+1;++j){
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int N;

    cout<<"Enter N:";
    cin>>N;

    pattern4(N);

}
