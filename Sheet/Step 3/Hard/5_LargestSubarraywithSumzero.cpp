#include<iostream>
#include<vector>
using namespace std;

int maxlenBrute(vector<int>& nums){
    int n=nums.size();
    int maxlen{};
    for(int i{};i<n-1;++i){
        int sum{};
        for(int j{i};j<n;++i){
            sum+=nums[j];
            if(sum==0){
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;    
}

int maxlenOptimal(vector<int>& nums){
    int n=nums.size();
    int left{};
    int right{};
    int sum{nums[0]};
    int maxlen{};

    while(left<=right && right<n){
        if(sum<0){
            sum-=nums[left];
            ++left;
        }
        else if(sum==0){
            maxlen=max(maxlen,right-left+1);
        }
        ++right;
        else{
            sum+=
        }
    }
}
