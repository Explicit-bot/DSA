#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int myAtoiBrute(string s){
    int n=s.size();
    int i{};
    while(i<n && s[i]=' '){
        ++i;
    }
    int sign{1};
    if(i<n && (s[i]=='+'||s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        ++i;
    }

    string digits="";
    while(i<n && isdigit(s[i])){
        digits+=s[i];
    }

    if(digits.empty()){
        return 0;
    }

    long long num{};
    for(auto c:digits){
        int digit=c-'0';
        if(num>(INT_MAX/10) || ((num==INT_MAX/10)&&(sign==1?7:8))){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        num=num*10+digit;
    }
    return sign*num;
}

int myAtoi(string s){
    int n=s.size();
    int i{};
    while(i<n && s[i]=' '){
        ++i;
    }
    int sign{1};
    if(i<n && (s[i]=='+'||s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        ++i;
    }

    long long num{};
    while(i<n && isdigit(s[i])){
        int digit=s[i]-'0';
        if(num>(INT_MAX/10) || ((num==INT_MAX/10)&&digit>(sign==1?7:8))){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        num=num*10+digit;
        ++i;
    }
    return sign*num;
}
