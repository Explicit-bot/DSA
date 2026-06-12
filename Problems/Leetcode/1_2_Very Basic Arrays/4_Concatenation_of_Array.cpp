#include<iostream>
#include<vector>
using namespace std;

vector<int> Concatenation(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(2*n,0);
    for(int i{};i<n;++i){
        ans[i]=nums[i];
        ans[i+n]=nums[i];
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
    
    vector<int> ans=Concatenation(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }

}
