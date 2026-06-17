#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long ceilQuotientsum(vector<int>& nums,int divisor){
    long long sum{};
    for(auto x:nums){
        sum+=ceil(double(x)/divisor);
    }
    return sum;
}

int SmallestdivisorBrute(vector<int>& nums,int threshold){
    int maxval=*max_element(nums.begin(),nums.end());
    for(int i{1};i<=maxval;++i){
        long long k=ceilQuotientsum(nums,i);
        if(k<=threshold){
            return i;
        }
    }
    return -1;
}

int SmallestdivisorOptimal(vector<int>& nums,int threshold){
    int maxval=*max_element(nums.begin(),nums.end());
    int l{1};
    int h{maxval};
    int ans{-1};
    while(l<=h){
        int mid=l+(h-l)/2;
        int k=ceilQuotientsum(nums,mid);
        if(k<=threshold){
            h=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int h{};
    cin>>h;

    cout<<SmallestdivisorBrute(nums,h)<<"\n";
    cout<<SmallestdivisorOptimal(nums,h)<<"\n";
}
