#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int MajorityElmBrute(vector<int> &nums) {
    int n=nums.size();
    for(int i{};i<n;++i){
        int cnt{};
        for(int j{};j<n;++j){
            if(nums[i]==nums[j]){
                ++cnt;
            }
        }
        if(cnt>n/2){
            return nums[i];
        }
    }
    return -1;
}

int MajorityElmSort(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());

    return nums[n/2];
}

int MajorityElmBetter(vector<int>& nums){
    unordered_map<int,int> mp{};
    for(int i{};i<nums.size();++i){
        ++mp[nums[i]];
    }
    for(auto x:mp){
        if(x.second>(nums.size())/2){
            return x.first;
        }
    }
    return -1;
}

//Moore's Vooting Algorithm
int MajoritElmOptimal(vector<int>& nums){
    int elm{};
    int cnt{};
    for(int i{};i<nums.size();++i){
        if(cnt==0){
            elm=nums[i];
            cnt=1;
        }
        else if(nums[i]==elm){
            ++cnt;
        }
        else{
            --cnt;
        }
    }

    int cnt1{};
    for(int i{};i<nums.size();++i){
        if(nums[i]==elm){
            ++cnt1;
        }
    }
    if(cnt1>(nums.size())/2){
        return elm;
    }
    return -1;
}

