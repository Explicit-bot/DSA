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

bool isSameAfterReversals(int num) {
    if(revn(revn(num))==num){
        return true;
    }
    return false;
}
