/*
Given an integer N, print the following pattern.
for example N=5
    A
   ABA 
  ABCBA
 ABCDCBA
ABCDEDCBA
*/

#include <iostream>
using namespace std;

void pattern17(int N){
    for(int i{};i<N;++i){
        //Space
        for(int j{};j<N-i-1;++j){
            cout<<" ";
        }

        //character
        char chr='A';
        for(int j{};j<2*i+1;++j){
            cout<<chr;
            if(j<i){
                ++chr;
            }
            else{
                --chr;
            }
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern17(P);

    return 0;
}
