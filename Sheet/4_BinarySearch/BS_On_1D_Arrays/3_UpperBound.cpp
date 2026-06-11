#include<iostream>
#include<vector>
using namespace std;

//*Sorted array
int UpperBoundBrute(vector<int>& nums,int k){
    for(int i{};i<nums.size();++i){
        if(nums[i]>k){
            return i;
        }
    }
    return nums.size();
}

int UpperBoundOptimal(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{n};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>k){
            h=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    int k{};
    cin>>k;

    cout<<UpperBoundBrute(nums,k)<<"\n";
    cout<<UpperBoundOptimal(nums,k)<<"\n";
}
