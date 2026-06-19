#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

int countArrays(vector<int>& nums,int sum){
    int cntarr{1};
    long long sumarray{};
    for(int i{0};i<nums.size();++i){
        if(sumarray+nums[i]<=sum){
            sumarray+=nums[i];
        }
        else{
            ++cntarr;
            sumarray=nums[i];
        }
    }
    return cntarr;
}

int splitArrayBrute(vector<int>& nums,int m){
    int n=nums.size();
    if(m>n){
        return -1;
    }

    int l=*max_element(nums.begin(),nums.end());
    int h=accumulate(nums.begin(),nums.end(),0);
    for(int i{l};i<=h;++i){
        if(countArrays(nums,i)<=m){
            return i;
        }
    }
    return -1;
}

int splitArrayOptimal(vector<int>& nums,int m){
    int n=nums.size();
    if(m>n){
        return -1;
    }

    int l=*max_element(nums.begin(),nums.end());
    int h=accumulate(nums.begin(),nums.end(),0);
    while(l<=h){
        int mid=l+(h-l)/2;
        if(countArrays(nums,mid)>m){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return l;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int m{};
    cin>>m;

    cout<<splitArrayBrute(nums,m)<<"\n";
    cout<<splitArrayOptimal(nums,m)<<"\n";
}
