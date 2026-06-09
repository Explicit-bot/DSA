/*
Given an integer N, print the following pattern.
for example N=5
                level   i   space
1        1      0       0   8
12      21      1       1   6
123    321      2       2   4
1234  4321      3       3   2
1234554321      4       4   0
1234  4321      3       5   2
123    321      2       6   4
12      21      1       7   6
1        1      0       8   8
*/

#include <iostream>
using namespace std;

void pattern9(int n){
    for(int i{};i<2*n-1;++i){
        int cnt{};
        int level=(i<n)?i:(2*n-i-2);
        //num
        for(int j{};j<level+1;++j){
            ++cnt;
            cout<<cnt;
        }
        //space
        for(int j{};j<(2*(n-level-1));++j){
            cout<<" ";
        }

        //num
        for(int j{};j<level+1;++j){
            cout<<cnt;
            --cnt;
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
