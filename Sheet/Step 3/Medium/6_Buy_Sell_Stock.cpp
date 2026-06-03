#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int BuySellStockBrute(vector<int>& nums){
    int n=nums.size();
    int maxi{};
    for(int i{};i<n-1;++i){
        int prof{};
        for(int j{i+1};j<n;++j){
            prof=nums[j]-nums[i];
            maxi =max(maxi,prof);
        }
    }
    return maxi;
}

int BuySellStockOptimal(vector<int>& nums){
    int n=nums.size();
    int maxi{};
    int mini{nums[0]};

    for(int i{1};i<n;--i){
        int cost=nums[i]-mini;
        maxi=max(maxi,cost);
        mini=min(mini,nums[i]);
    }
    return maxi;
}
