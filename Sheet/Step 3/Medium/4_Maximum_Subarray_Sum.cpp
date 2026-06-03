#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MaxSubArrSumBrute(vector<int>& nums){
    int n=nums.size();
    int maxi{INT_MIN};
    for(int i{};i<n;++i){
        for(int j{i};j<n;++j){
            int sum{};
            for(int k{i};k<=j;++k){
                sum+=nums[k];
            }
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

int MaxSubArrSumBetter(vector<int>& nums){
    int n=nums.size();
    int maxi{INT_MIN};
    for(int i{};i<n;++i){
        int sum{};
        for(int j{i};j<n;++j){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

//Kadane's Algorithm
int MaxSubArrSumOptimal(vector<int>& nums){
    int maxi{INT_MIN};
    int sum{};
    for(int i{};i<nums.size();++i){
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}
