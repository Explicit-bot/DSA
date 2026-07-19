#include<iostream>
#include<string>
#include<vector>
using namespace std;


string removeOuterParentheses(string s) {
    int n=s.size();
    string ans;
    int cnt{};
    for(int i{};i<n;++i){
        if(s[i]=='('){
            ++cnt;
            if(cnt>=2){
                ans.push_back('(');
            }
        }
        else{
            --cnt;
            if(cnt>0){
                ans.push_back(')');
            }
        }
    }
    return ans;   
}
