#include<iostream>
#include<vector>
using namespace std;

bool consecutiveSetBits(int n){
    int cnt{};
    while(n>0){
        if((n&1) && (n>>1)&1){
            ++cnt;
        }
        n=n>>1;
    }
    return cnt==1;
}

int main(){
    int n;
    cin>>n;

    cout<<consecutiveSetBits(n);
}
