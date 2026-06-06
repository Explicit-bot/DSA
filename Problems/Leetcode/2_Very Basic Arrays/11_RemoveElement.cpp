#include<iostream>
#include<vector>
using namespace std;

int RemoveElementBrute(vector<int>& nums,int val){
    int n=nums.size();
    vector<int> temp{};
    for(auto x:nums){
        if(x!=val){
            temp.push_back(x);
        }
    }

    int k=temp.size();
    int val_len=n-k;
    
    for(int i{};i<k;++i){
        nums[i]=temp[i];
    }

    return k;
}

int RemoveElementOptimal(vector<int>& nums,int val){
    int n=nums.size();
    int i{};
    for(int j{};j<n;++j){
        if(nums[j]!=val){
            nums[i]=nums[j];
            ++i;
        }
    }
    return i;
}
