#include<iostream>
#include<string>
using namespace std;

bool isvowel(char c){
    c = tolower(c);
    return string("aeiou").find(c) != string::npos;
}

bool halvesAreAlike(string s) {
    int n=s.size();
    int cnt{};
    for(int i{};i<=(n/2)-1;++i){
        if(isvowel(s[i])){
            ++cnt;
        }
    }
    for(int i=(n/2);i<n;++i){
        if(isvowel(s[i])){
            --cnt;
        }
    }
    return cnt==0;
}

