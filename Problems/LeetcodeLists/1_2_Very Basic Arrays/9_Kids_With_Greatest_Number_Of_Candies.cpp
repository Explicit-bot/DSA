#include<iostream>
#include<vector>
using namespace std;

vector<bool> GreatestNumofCandies(vector<int>& nums,int extracandies){
    int n=nums.size();
    int maxi{nums[0]};
    for(const auto& x:nums){
        if(x>maxi){
            maxi=x;
        }
    }
    
    vector<bool> ans;
    for(auto x : nums){
        ans.push_back(x+extracandies>=maxi);
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int extracandies{};
    cin>>extracandies;

    vector<bool> ans=GreatestNumofCandies(nums,extracandies);
    for(auto x:ans){
        cout<<x<<" ";
    }
}
