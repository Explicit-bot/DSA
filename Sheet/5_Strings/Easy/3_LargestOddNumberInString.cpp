#include<iostream>
#include<string>
#include<vector>
using namespace std;

string largestOddNumber(string s) {
    int n=s.size();
    int idx{-1};
    for(int i{n-1};i>=0;--i){
        if((s[i]-'0')%2==1){
            idx=i;
            break;
        }
    }
    
    int i{};
    while(i<=idx && s[i]=='0'){
        ++i;
    }
    return s.substr(i,idx-i+1);
}
