/*
Given an integer N, print the following pattern.
for example N=5

* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
*/

#include <iostream>
using namespace std;

void pattern1(int n){
    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

int main(){
    int N;

    cout<<"Enter N:";
    cin>>N;

    pattern1(N);

}
