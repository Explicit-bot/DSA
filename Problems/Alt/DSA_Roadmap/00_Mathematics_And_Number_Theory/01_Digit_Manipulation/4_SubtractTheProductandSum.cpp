//1281
#include<iostream>
#include<vector>
using namespace std;

int subtractProductAndSum(int n){
    int prod{1};
    int sum{};
    while(n>0){
        int ld=n%10;
        sum+=ld;
        prod*=ld;
        n/=10;
    } 
    return prod-sum;
}

int main(){
    int n{};
    cin>>n;

    cout<<subtractProductAndSum(n)<<"\n";
    
}
