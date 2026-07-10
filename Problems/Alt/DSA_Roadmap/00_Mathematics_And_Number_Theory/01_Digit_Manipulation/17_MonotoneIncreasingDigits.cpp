//738
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Brute 
bool isMonotone(int num){
    string s=to_string(num);
    for(int i{};i<s.size()-1;++i){
        if(s[i+1]<s[i]){
            return false;
        }
    }
    return true;
}

int monotoneDigits(int high){
    for(int i{high};i>=0;++i){
        if(isMonotone(i)){
            return i;
        }
    }
    return -1;
}

//Optimal
int monotoneDigitsOptimal(int high){
    string s=to_string(high);
    int n=s.size();
    int mark{n};
    for(int i{n-1};i>0;--i){
       if(s[i]<s[i-1]){
        --s[i-1];
        mark=i;
       }
    }
    for(int i{mark};i<n;++i){
        s[i]='9';
    }
    return stoi(s);
}
