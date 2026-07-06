//1295
#include<iostream>
#include<vector>
using namespace std;

int findNumbers(vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        int d=floor(log10(nums[i]))+1;
        if(d%2==0){
            ++cnt;
        }
    }
    return cnt;
}

int findNumbers(vector<int>& nums) {
    int ans{};
    
    for (auto x : nums) {
        ans += (x > 9 && x < 100) ||
        (x > 999 && x < 10000) ||
        (x == 100000);
    }   
    return ans;
}
