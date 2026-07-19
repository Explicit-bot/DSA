#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//Brute
bool isPalindrome(string &s,int l,int r){
    
    while(l<r){
        if(s[l]!=s[r])
            return false;
    
        l++;
        r--;
    }
    return true;
}

string longestPalindrome(string s) {
    int n=s.size();
    int maxLen=0;
    string ans="";

    for(int i=0;i<n;i++){        
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                if(j-i+1>maxLen){
                    maxLen=j-i+1;
                    ans=s.substr(i,maxLen);
                }
            }
        }
    }
    
    return ans;
}

//Better
string longestPalindrome(string s) {
    int n=s.size();
        
    if(n<=1){
        return s;
    }
    
    int start=0;
    int maxLen=1;
    
    for(int i=0;i<n;i++){
        int odd=expand(s,i,i);
        int even=expand(s,i,i+1);
        int len=max(odd,even);
        if(len>maxLen){
            maxLen=len;
            start=i-(len-1)/2;
        }
    }
    return s.substr(start,maxLen);
}

int expand(string &s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }   
    return right-left-1;
}

