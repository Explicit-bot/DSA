/*
***
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

void pattern7(int n){
    for(int i{};i<n;++i){
        char ch='A';

        //space
        for(int j{};j<n-i-1;++j){
            cout<<" ";
        }
        //Alphabet
        for (int j{};j<2*i+1;++j){
            cout<<ch;
            if(j<i){
                ++ch;
            }
            else{
                --ch;
            }
        }
        cout<<"\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    pattern7(P);

    return 0;
}
