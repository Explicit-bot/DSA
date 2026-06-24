#include<iostream>
using namespace std;

int revn(int d){
    int ans{};
    while(d){
        ans=ans*10+d%10;
        d/=10;
    }
    return ans;
}

bool sumOfNumberAndReverse(int num) {
    for(int i{};i<=num;++i){
        if(i+revn(i)==num){
            return true;
        }
    }
    return false;
}
