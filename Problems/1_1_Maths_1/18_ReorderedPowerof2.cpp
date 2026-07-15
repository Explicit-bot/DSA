//869
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool reorderPowerof2(int n){
    string num=to_string(n);
    sort(num.begin(),num.end());
    for(int i{};i<31;++i){
        int power=1<<i;

        string curpower=to_string(power);
        sort(curpower.begin(),curpower.end());
        if(num==curpower){
            return true;
        }
    }
    return false;
}

vector<int> currentDigits(int n){
    vector<int> freq(10,0);
    while(n){
        freq[n%10]++;
        n/=10;
    }
    return freq;
}

bool reorderPower2(int n){
    vector<int> curr=currentDigits(n);
    for(int i{};i<31;++i){
        if(curr==currentDigits(1<<i)){
            return true;
        }
    }
    return false;
}
