#include<iostream>
#include<vector>
using namespace std;

int getFloor(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{-1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]<=k){
            l=mid+1;
            ans=nums[mid];
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int getCeil(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{-1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>=k){
            h=mid-1;
            ans=nums[mid];
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

vector<int> floorAndCeil(vector<int>& nums,int k){
    return {getFloor(nums,k),getCeil(nums,k)};
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

    vector<int> ans=floorAndCeil(nums,k);
    cout<<"Floor:"<<ans[0]<<"\n";
    cout<<"Ceil:"<<ans[1]<<"\n";
    
}

