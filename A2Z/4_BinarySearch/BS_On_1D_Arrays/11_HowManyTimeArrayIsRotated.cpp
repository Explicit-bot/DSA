#include<iostream>
#include<vector>
using namespace std;

 int howmanyrotations(vector<int>& nums){
    int n=nums.size();
    int l{};
    int h{n-1};
    int mini{INT_MAX};
    int idx{};
    while(l<=h){
        int mid=l+(h-l)/2;
        
        if(nums[l]<=nums[h]){
            mini=min(mini,nums[l]);
            if(mini==nums[l]){
                idx=l;
            }
            break;
        }

        if(nums[mid]>=nums[l]){
            mini=min(mini,nums[l]);
            if(mini==nums[l]){
                idx=l;
            }
            l=mid+1;
        }
        else if(nums[mid]<=nums[h]){
            mini=min(mini,nums[mid]);
            if(mini==nums[mid]){
                idx=mid;
            }
            h=mid-1;
        }
    }
    return idx;
}

int main(){
    int n{};
    cin>>n;
    
    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<howmanyrotations(nums);
}
