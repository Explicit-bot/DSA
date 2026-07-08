//1291
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int removeOuterParentheses(string s) {
    int n=s.size();
    int ans{};
    int cnt{};
    for(int i{};i<n;++i){
        if(s[i]=='('){
            ++cnt;
        }
        else{
            --cnt;
            if(cnt>0){
                ++ans;
            }
        }
    }
    return ans;   
}

