#include<iostream>
#include<vector>
using namespace std;

vector<int> RepeatingMissingBrute(const vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int repeating{};
    for(int i{};i<n;++i){
        if(nums[i]==nums[i+1]){
            repeating=nums[i];
        }
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    vector<int> ans=RepeatingMissingBrute(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }

}
