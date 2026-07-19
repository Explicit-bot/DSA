#include<iostream>
#include<string>
using namespace std;

int maxDepth(string s) {
    int n = s.size();
    int ans{};
    int cnt{};
    for (int i{}; i < n; ++i) {
        if (s[i] == '(') {
            ++cnt;
        } else if(s[i]==')'){
            --cnt;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
