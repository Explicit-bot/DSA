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

void pattern3(int N){
    for(int i{};i<N;++i){
        for(int j{};j<i+1;++j){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }

}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern3(P);

    return 0;
}
