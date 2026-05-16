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

void pattern6(int N){
    for(int i{};i<N;++i){
        for(int j{};j<N-i;++j){
            cout<<j+1<<" ";
        }
        cout<<"\n";
    }

}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern6(P);

    return 0;
}
