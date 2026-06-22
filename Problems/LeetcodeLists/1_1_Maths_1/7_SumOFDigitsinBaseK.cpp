#include<iostream>
using namespace std;

int sumBase(int n, int k) {
    int sum{};
    while(n){
        sum+=n%k;
        n/=k;
    }
    return sum;
}

int main(){
    int n{},k{};
    cin>>n>>k;

    cout<<sumBase(n,k)<<"\n";
}
