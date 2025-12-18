/*
Given an integer N, print the following pattern.
for example N=5
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

#include <iostream>
using namespace std;

void pattern11(int N){
    for(int i{};i<N;++i){
        int start=(i%2==0)?1:0;
        
        for(int j{};j<i+1;++j){
            cout<<start<<" ";
            start=1-start;
        }

        cout<<"\n";
    }
}


int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern11(P);

    return 0;
}
