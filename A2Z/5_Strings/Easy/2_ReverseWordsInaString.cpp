#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reversewords(string s){
    int n=s.size();
    vector<string> ans;
    string temp;
    for(int i{};i<n;++i){
        if(s[i]!=' '){
            temp+=s[i];
        }
        else if(!temp.empty()){
            ans.push_back(temp);
            temp="";
        }
    }
    if(!temp.empty()){
        ans.push_back(temp);
    }

    reverse(ans.begin(),ans.end());
    string result;
    for(int i{};i<ans.size();++i){
        result+=ans[i];
        if(i<ans.size()-1){
            result+=' ';
        }
    }
    return result;
}

string reverseWords(string s) {
    string result = "";
    
    int i = s.size() - 1;
    
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        if (i < 0){
            break;
        } 
        int end = i;
        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        
        string word = s.substr(i + 1, end - i);
        
        if (!result.empty()) {
            result += " ";
        }
        
        result += word;
    
    return result;
}
