/*
Given an integer N, print the following pattern.
for example N=5
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include <iostream>
using namespace std;

void pattern9(int N){
    for(int i{};i<2*N-1;++i){
        int spaces=(i<N)?(N-i-1):(i-N+1);
        int stars=(i<N)?(2*(i)+1):(2*(2*N-i));

        //Space
        for(int j{};j<spaces;++j){
            cout<<" ";
        }

        //star
        for(int j{};j<stars;++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern9(P);

    return 0;
}
