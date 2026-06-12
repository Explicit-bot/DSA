#include<iostream>
#include<vector>
using namespace std;

void RunningSum(vector<int>& nums){
    int n=nums.size();

    for(int i{1};i<n;++i){
        nums[i]+=nums[i-1];
    }

}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    RunningSum(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }

}
