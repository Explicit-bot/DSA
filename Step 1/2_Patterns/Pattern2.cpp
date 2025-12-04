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

void pattern2(int N){
    for(int i{};i<N;++i){
        for(int j{};j<i+1;++j){
            cout<<"* ";
        }
        cout<<"\n";
    }

}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern2(P);

    return 0;
}
