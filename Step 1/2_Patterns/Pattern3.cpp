/*
Given an integer N, print the following pattern.
for example N=5
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

#include <iostream>
using namespace std;

void pattern3(int n){
    for(int i{};i<n;++i){
        for(int j{};j<i+1;++j){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int N;

    cout<<"Enter N:";
    cin>>N;

    pattern3(N);

}
