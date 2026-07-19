#include<iostream>
#include<vector>
using namespace std;

int GetFirst(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{n};
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

int GetLast(vector<int>& nums,int k){
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

vector<int> FirstAndLast(vector<int>& nums,int k){
    int first=GetFirst(nums,k);
    
    if(first==-1 || nums[first]!=k){
        return {-1,-1};
    }

    int last=GetLast(nums,k)-1;
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

    vector<int> ans=FirstAndLast(nums,k);
    cout<<"First Occurence at idx:"<<ans[0]<<"\n";
    cout<<"Last Occurence at idx:"<<ans[1]<<"\n";
}
