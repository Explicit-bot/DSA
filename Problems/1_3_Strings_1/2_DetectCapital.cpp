#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool detectCapitalUse(string word) {
    int n=word.length();
    int cnt{};
    for(auto x:word){
        if(isupper(x)){
            ++cnt;
        }
    }
    
    if(n==cnt || (cnt==1 && isupper(word[0])) || cnt==0){
        return true;
    }
    return false;
}
