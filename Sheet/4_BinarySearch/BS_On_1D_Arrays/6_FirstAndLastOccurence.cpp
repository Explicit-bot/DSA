#include<iostream>
#include<vector>
using namespace std;

int LowerBound(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{-1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>=k){
            h=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int UpperBound(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{-1};
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

pair<int,int> FirstAndLast(vector<int>& nums,int k){
    int first=LowerBound(nums,k);
    if(first==-1){
        return {-1,-1};
    }
    int last=UpperBound(nums,k)-1;
    return {first,last};
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

    pair<int,int> ans=FirstAndLast(nums,k);
    cout<<"First Occurence:"<<ans.first<<"\n";
    cout<<"Last Occurence:"<<ans.second<<"\n";
}
