#include<iostream>
#include<vector>
using namespace std;

int Search1(vector<int>& nums,int k){
    int n=nums.size();
    int l{};
    int h{n-1};

    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==k){
            return mid;
        }

        if(nums[l]<=nums[mid]){
            if(nums[l]<=k && nums[mid]>k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(nums[mid]<k && k<=nums[h]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
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
    
    int k{};
    cin>>k;

    cout<<Search1(nums,k);
}
