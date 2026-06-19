#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

int countStudents(vector<int>& nums,int pages){
    int cntstd{1};
    long long sumpages{};
    for(int i{0};i<nums.size();++i){
        if(sumpages+nums[i]<=pages){
            sumpages+=nums[i];
        }
        else{
            ++cntstd;
            sumpages=nums[i];
        }
    }
    return cntstd;
}

int findPagesBrute(vector<int>& nums,int m){
    int n=nums.size();
    if(m>n){
        return -1;
    }

    int l=*max_element(nums.begin(),nums.end());
    int h=accumulate(nums.begin(),nums.end(),0);
    for(int i{l};i<=h;++i){
        if(countStudents(nums,i)<=m){
            return i;
        }
    }
    return -1;
}

int findPagesOptimal(vector<int>& nums,int m){
    int n=nums.size();
    if(m>n){
        return -1;
    }

    int l=*max_element(nums.begin(),nums.end());
    int h=accumulate(nums.begin(),nums.end(),0);
    while(l<=h){
        int mid=l+(h-l)/2;
        if(countStudents(nums,mid)>m){
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

    cout<<findPagesBrute(nums,m)<<"\n";
    cout<<findPagesOptimal(nums,m)<<"\n";
}
