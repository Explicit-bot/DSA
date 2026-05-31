#include<iostream>
#include<vector>
using namespace std;

vector<int> LeadersBrute(vector<int>& nums){
    int n=nums.size();
    vector<int> leaders{};
    
    for(int i{};i<n;++i){
        bool found{1};
        for(int j{i+1};j<n;++j){
            if(nums[j]>nums[i]){
                found=0;
                break;
            }
        }
        if(found){
            leaders.push_back(nums[i]);
        }
    }
    return leaders;
}

vector<int> LeaderOptimal(vector<int>& nums){
    int n=nums.size();
    vector<int> leaders{};
    int maxelm{nums[n-1]};
    leaders.push_back(maxelm);
    for(int i{n-2};i>=0;--i){
        if(nums[i]>maxelm){
            maxelm=nums[i];
            leaders.push_back(maxelm);
        }
    }
    reverse(leaders.begin(),leaders.end());
    return leaders;
}
