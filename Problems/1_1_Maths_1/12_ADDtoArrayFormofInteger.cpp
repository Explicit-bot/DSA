#include<iostream>
#include<vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    int n=num.size();
    for(int i{n-1};i>=0;--i){
        num[i]+=k;
        k=num[i]/10;
        num[i]%=10;
    }
    
    while(k>0){
        num.insert(num.begin(),k%10);
        k/=10;
    }
    return num;
}


vector<int> addToArrayFormOptimal(vector<int>& num, int k) {
    int n=num.size();
    vector<int> ans;
    for(int i{n-1}; i >= 0 || k > 0; --i) {
        if(i >= 0){
            k += num[i];
        }
        ans.push_back(k % 10);
        k /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
