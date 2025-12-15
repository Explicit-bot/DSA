/*
Given an integer N, print the following pattern.
for example N=5
*
**
***
****
*****
****
***
**
*

*/

#include <iostream>
using namespace std;

//Using levels concept
void pattern10(int N){
    for(int i{};i<2*N-1;++i){
        int level=(i<N)?i:(2*N-i)-2;

        //star
        for(int j{};j<level+1;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern10(P);

    return 0;
}
