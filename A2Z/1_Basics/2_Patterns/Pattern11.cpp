/*
***
Given an integer N, print the following pattern.
for example N=5
    
    0 1 2 3 4 5 6 7 8

0   5 5 5 5 5 5 5 5 5
1   5 4 4 4 4 4 4 4 5
2   5 4 3 3 3 3 3 4 5
3   5 4 3 2 2 2 3 4 5
4   5 4 3 2 1 2 3 4 5
5   5 4 3 2 2 2 3 4 5
6   5 4 3 3 3 3 3 4 5
7   5 4 4 4 4 4 4 4 5
8   5 5 5 5 5 5 5 5 5

*/

#include <iostream>
using namespace std;

void pattern11M1(int n){
   for(int i{};i<2*n-1;++i){
        for(int j{};j<2*n-1;++j){
            int left=j;
            int top=i;
            int bottom=2*n-2-i;
            int right=2*n-2-j;

            int dist=min(min(left,right),min(top,bottom));

            cout<<(n-dist);
        }
        cout<<"\n";
   }
}

void pattern11M2(int n){
    int size = 2*n - 1;
    int center = size / 2;

    for(int i{}; i<size; ++i){
        for(int j{}; j<size; ++j){

            int value = max(abs(i-center),
                            abs(j-center)) + 1;

            cout << value << " ";
        }

        cout << "\n";
    }
}

int main(){
    int P{};
    
    cout<<"Enter the value of N:";
    cin>>P;

    //pattern11M1(P);
    pattern11M2(P);
    return 0;
}

