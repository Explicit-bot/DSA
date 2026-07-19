#include<iostream>
#include<vector>
using namespace std;

 int Searchmini(vector<int>& nums){
    int n=nums.size();
    int l{};
    int h{n-1};
    int mini{INT_MAX};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[l]<=nums[h]){
            mini=min(mini,nums[l]);
            break;
        }

        if(nums[mid]>=nums[l]){
            mini=min(mini,nums[l]);
            l=mid+1;
        }
        else if(nums[mid]<=nums[h]){
            mini=min(mini,nums[mid]);
            h=mid-1;
        }
    }
    return mini;
}

int main(){
    int n{};
    cin>>n;
    
    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<Searchmini(nums);
}
