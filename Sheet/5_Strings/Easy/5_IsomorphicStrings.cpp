#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isIsomorphicBrute(string s, string t) {
    int n = s.size();

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < i; j++) {

            // Same source character but different target character
            if(s[j] == s[i] && t[j] != t[i])
                return false;

            // Different source character but same target character
            if(s[j] != s[i] && t[j] == t[i])
                return false;
        }
    }

    return true;
}

bool isIsomorphicBetter(string s, string t) {
    unordered_map<char,char> sToT;
    unordered_map<char,char> tToS;

    for(int i = 0; i < s.size(); i++) {

        // s[i] already mapped but to a different character
        if(sToT.count(s[i]) && sToT[s[i]] != t[i])
            return false;

        // t[i] already occupied by another character
        if(tToS.count(t[i]) && tToS[t[i]] != s[i])
            return false;

        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
    }

    return true;
}

bool isIsomorphic(string s, string t) {
    int m1[256]={};
    int m2[256]={};
    int n=s.size();

    for(int i{0};i<n;++i){
        if(m1[s[i]]!=m2[t[i]]){
            return false;
        }
        m1[s[i]]=i+1;
        m2[t[i]]=i+1;
    }
    return true;
}

