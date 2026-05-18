/*
Given an integer N, print the following pattern.
for example N=5
* 
* *
* * *
* * * *
* * * * *
*/

#include <iostream>
using namespace std;

void pattern2(int n){
    for(int i{};i<n;++i){
        for(int j{};j<i+1;++j){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

int main(){
    int N;

    cout<<"Enter N:";
    cin>>N;

    pattern2(N);

}
