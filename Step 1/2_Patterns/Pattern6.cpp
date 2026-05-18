/*
Given an integer N, print the following pattern.
for example N=5
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/

#include <iostream>
using namespace std;

void pattern6(int n){
    for(int i{};i<n;++i){
        for(int j{};j<n-i;++j){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;

    cout<<"Enter n:";
    cin>>n;

    pattern6(n);
}
