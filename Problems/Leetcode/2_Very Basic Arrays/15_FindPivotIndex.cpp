#include<iostream>
#include<vector>
using namespace std;

int FindPivotIndexBrute(vector<int>& nums){
    int n=nums.size();
    for(int i{0};i<n;++i){
        int rsum{};
        int lsum{};
        
        for(int j{};j<i;++j){
            lsum+=nums[j];
        }

        for(int j{i+1};j<n;++j){
            rsum+=nums[j];
        }

        if(lsum==rsum){
            return i;
        }
    }
    return -1;
}

int FindPivotIndexOptimal(vector<int>& nums){
    int n=nums.size();
    int totalsum{};
    for(auto x:nums){
        totalsum+=x;
    }

    int leftsum{};
    for(int i{};i<n;++i){
        int rightsum=totalsum-leftsum-nums[i];
        if(leftsum==rightsum){
            return i;
        }
        leftsum+=nums[i];
    }
    return -1;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<FindPivotIndexBrute(nums)<<"\n";
    cout<<FindPivotIndexOptimal(nums)<<"\n";
}
