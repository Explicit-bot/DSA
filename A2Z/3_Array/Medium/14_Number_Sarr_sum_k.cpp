#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//Brute force Approach would be the one with two loops

//Empty array is subarray of every array


//Think what is happening
int SubarraySumOptimal(vector<int>& nums, int k) {
    int n=nums.size();
    int cnt{};
    int presum{};
    map<int,int> mp{};
    mp[0]=1;
    for(int i{};i<n;++i){
        presum+=nums[i];
        int rem=presum-k;
        cnt+=mp[rem];
        ++mp[presum];;
    }
    return cnt;
}
