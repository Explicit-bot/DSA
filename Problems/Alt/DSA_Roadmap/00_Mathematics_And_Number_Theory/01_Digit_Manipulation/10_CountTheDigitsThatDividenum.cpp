#include<iostream>
using namespace std;

int countDigits(int num) {
    int cnt{};
    int temp{num};
    while(num){
        int ld=num%10;
        if(temp%ld==0){
            ++cnt;
        }
        num/=10;
    }
    return cnt;
}

int main(){
    int n{};
    cin>>n;

    cout<<countDigits(n)<<"\n";
}
