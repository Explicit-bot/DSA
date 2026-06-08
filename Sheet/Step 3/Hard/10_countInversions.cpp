#include<iostream>
#include<vector>

using namespace std;

int CountInversionBrute(const vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        for(int j{i};j<n;++j){
            if(nums[j]<nums[i]){
                ++cnt;
            }
        }
    }
    return cnt;
}

//Optimal
int merge(vector<int>& nums,int l,int mid ,int h){
    int cnt{};
    int left{l};
    int right{mid+1};
    vector<int> ans;
    while(left<=mid && right<=h){
        if(nums[left]<=nums[right]){
            ans.push_back(nums[left]);
            ++left;
        }
        else{
            ans.push_back(nums[right]);
            cnt+=mid-left+1;
            ++right;
        }
    }

    while(left<=mid){
        ans.push_back(nums[left]);
        ++left;
    }

    while(right<=h){
        ans.push_back(nums[right]);
        ++right;
    }

    for(int i = l; i <= h; ++i){
        nums[i] = ans[i - l];
    }

    return cnt;
}

int mergesort(vector<int>& nums,int l,int h){
    int cnt{};
    if(l>=h){
        return cnt;
    }

    int mid=(l+h)/2;
    cnt+=mergesort(nums,l,mid);
    cnt+=mergesort(nums,mid+1,h);
    cnt+=merge(nums,l,mid,h);

    return cnt;
}

int CountInversionOptimal(vector<int>& nums){
    int n=nums.size();
    return mergesort(nums,0,n-1);
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    cout<<CountInversionBrute(nums)<<"\n";
    cout<<CountInversionOptimal(nums)<<"\n";
    
}
