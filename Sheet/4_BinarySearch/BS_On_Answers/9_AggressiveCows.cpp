#include<iostream>
#include<vector>
using namespace std;

bool canBeplaced(vector<int>& nums,int dist,int cows){
    int cntcows{1};
    int last{nums[0]};
    for(int i{1};i<nums.size();++i){
        if(nums[i]-last>=dist){
            ++cntcows;
            last=nums[i];
        }
    }
    return cntcows>=cows;
}

int aggressiveCowsBrute(vector<int>& nums , int cows){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int h=nums[n-1]-nums[0];
    for(int i{1};i<=h;++i){
        if(!canBeplaced(nums,i,cows)){
            return (i-1);
        }
    }
    return h;
}

int aggressiveCowsOptimal(vector<int>& nums , int cows){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int l{1};
    int h=nums[n-1]-nums[0];
    while(l<=h){
        int mid=l+(h-l)/2;
        if(canBeplaced(nums,mid,cows)){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return h;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int k{};
    cin>>k;

    cout<<aggressiveCowsBrute(nums,k)<<"\n";
    cout<<aggressiveCowsOptimal(nums,k)<<"\n";
}
