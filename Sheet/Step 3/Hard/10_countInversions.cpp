#include<iostream>
#include<vector>

using namespace std;

int CountInversionBrute(const vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        for(int j{i};j<n;++j){
            if(nums[j]<nums[i]){
                ++cnt;
            }
        }
    }
    return cnt;
}

//Optimal


int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    cout<<CountInversionBrute(nums)<<"\n";
}
