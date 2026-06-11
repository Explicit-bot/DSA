#include<iostream>
#include<vector>
using namespace std;

 int Search2(vector<int>& nums){
    int n=nums.size();
    int l{};
    int h{n-1};
    int mini{INT_MAX};
    while(l<=h){
        int mid=l+(h-l)/2;
        mini=min(mini,nums[mid]);

        if(mini==nums[l] && nums[h]==mini){
            ++l;
            --h;
        }

        if(mini<=nums[mid-1]){
            h=mid-1;
        }
        
}

int main(){
    int n{};
    cin>>n;
    
    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<Search2(nums);
}
