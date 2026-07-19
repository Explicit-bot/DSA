#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int NumberofSubarraWithXORkBrute(vector<int>& nums,int k){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        int xor1{};
        for(int j{i};j<n;++j){
            xor1^=nums[j];
            if(xor1==k){
                ++cnt;
            }
        }
    }
    return cnt;
}

int NumberofSubarraWithXORkOptimal(vector<int>& nums,int k){
    int n=nums.size();
    int prexor{};
    int cnt{};
    unordered_map<int,int> mp;
    mp[0]=1;
    for(int i{};i<n;++i){
        prexor=prexor^nums[i];
        cnt+=mp[prexor^k];
        ++mp[prexor];
    }
    return cnt;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int k{};
    cin>>k;
    
    cout<<"\n";

    cout<<NumberofSubarraWithXORkBrute(nums,k)<<"\n";
    cout<<NumberofSubarraWithXORkOptimal(nums,k)<<"\n";
}

/*
You forgot: mp[0] = 1;
This is essential.

Why?
Because if the prefix XOR itself becomes k, then: prexor ^ k = 0
and we need to count the empty prefix.

Example:
nums = [4]
k = 4

Prefix XOR:
4

Now:
prexor ^ k = 4 ^ 4 = 0

So we need one occurrence of XOR 0 already present.
*/
