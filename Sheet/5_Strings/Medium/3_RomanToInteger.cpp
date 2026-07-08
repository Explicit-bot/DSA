#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int romanToint(string s){
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int ans{};
    for(int i{};i<s.size()-1;++i){
        if(s[i]<s[i+1]){
            ans-=roman[s[i]];
        }
        else{
            ans+=roman[s[i]];
        }
    }
    return ans+roman[s.back()];
}
