/*
Given an integer N, print the following pattern.
for example N=5
* * * * *
* * * *
* * *
* *
*
*/

#include <iostream>
using namespace std;

void pattern5(int N){
    for(int i{};i<N;++i){
        for(int j{};j<N-i;++j){
            cout<<"* ";
        }
        cout<<"\n";
    }

}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern5(P);

    return 0;
}
