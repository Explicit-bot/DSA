#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool isvowel(char ch){
    int k=tolower(ch);
    if(k=='a' || k=='e' || k=='i' || k=='o' || k=='u'){
        return true;
    }
    return false;
}
string reverseVowels(string s) {
    int n=s.length();
    int l{};
    int r{n-1};
    while(l<r){
        while(l<r && !isvowel(s[l])){
            ++l;
        }
        while(l<r && !isvowel(s[r])){
            --r;
        }
        swap(s[l],s[r]);
        ++l;
        --r;
    }
    return s;
}

