#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[strs.size()-1];
    int minidx=min(first.size(),last.size());
    string ans;
    for(int i{};i<minidx;++i){
        if(first[i]==last[i]){
            ans+=first[i];
        }
        else{
            break;
        }
    }
    return ans;
}
