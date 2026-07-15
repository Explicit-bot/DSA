//38
#include <iostream>
#include <string>
using namespace std;

//Iterative
string countAndsay(int n){
    string ans="1";
    for(int j{2};j<=n;++j){
        string temp="";
        int i{};
        while(i<ans.size()){
            int cnt{1};
            while(i+1<ans.size() && ans[i]==ans[i+1]){
                ++cnt;
                ++i;
            }
            temp+=to_string(cnt);
            temp+=ans[i];
            ++i;
        }
        ans=temp;
    }
    return ans;
}

//Recursive
string encode(string s) {
    string ans;
    
    int i{};
    while (i < s.size()) {
        int j = i;
        while (j < s.size() && s[j] == s[i]){
            j++;
        }
        
        ans += to_string(j - i);
        ans += s[i];
        i = j;
    }
    
    return ans;
}

string countAndSay(int n) {
    if (n == 1)
    return "1";
    
    return encode(countAndSay(n - 1));
}
