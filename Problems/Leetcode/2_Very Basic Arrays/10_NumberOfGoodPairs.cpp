#include<iostream>
#include<vector>
#include<map>
using namespace std;

int GoodPairsBrute(const vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        for(int j{i+1};j<n;++j){
            if(nums[i]==nums[j]){
                ++cnt;
            }
        }
    }
    return cnt;
}

int GoodPairsOptimal(vector<int>& nums){
    int n=nums.size();
    int cnt{};
    map<int,int> mp;
    for(auto x:nums){
        cnt+=mp[x]++;
    }
    return cnt;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<GoodPairsBrute(nums)<<"\n";
    cout<<GoodPairsOptimal(nums)<<"\n";
}
