#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Brute (O(N*N*N),O(1))
int SubArrayWorseBrute(vector<int>& nums,int l){
    int n=nums.size();
    int len{};
    for(int i{};i<n;++i){
        for(int j=i;j<n;++j){
            int sum{};
            for(int k=i;k<=j;++k){
                sum+=nums[k];
            }
            if(sum==l){
                len=max(len,j-i+1);
            }
        }
    }

    return len;
}

//Better (O(N*N),O(1))
int SubArrayBrute(vector<int>& nums,int k){
    int n=nums.size();
    int len{};
    for(int i{};i<n;++i){
        int sum{};
        for(int j{i};j<n;++j){
            sum+=nums[j];
            if(sum==k){
                len=max(len, j-i+1);
            }
        }
    }
    return len;
}

//Optimal (Prefix Sum + Hashing) (O(N),O(N))
int SunArrayBetter(vector<int> nums,int k){
    map<int,int> presummp{};
    int maxlen{};
    int sum{};

    for(int i{};i<nums.size();++i){
        sum+=nums[i];
        int rem=sum-k;
        if(sum==k){
            maxlen=i+1;
        }
        else if(presummp.find(rem)!=presummp.end()){
            int len=i-presummp[rem];
            maxlen=max(len,maxlen);
        }
        if(presummp.find(sum)==presummp.end()){
            presummp[sum]=i;
        }
    }
    return maxlen;
}
