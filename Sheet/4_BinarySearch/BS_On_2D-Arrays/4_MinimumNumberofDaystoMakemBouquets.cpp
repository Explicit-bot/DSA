#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

int cntBouquets(vector<int>& bloomday,int k,int currday){
    int cnt{};
    int bouquets{};
    for(auto& x:bloomday){
        if(x<=currday){
            ++cnt;
        }
        else{
            bouquets+=cnt/k;
            cnt=0;
        }
    }
    bouquets+=cnt/k;
    return bouquets;
}

int cntdaysBrute(vector<int>& bloomday,int m,int k){
    int n=bloomday.size();
    if(1ll*m*k > n){
        return -1;
    }
    int minval=*min_element(bloomday.begin(),bloomday.end());
    int maxval=*max_element(bloomday.begin(),bloomday.end());
    for(int i{minval};i<=maxval;++i){
        int cnt=cntBouquets(bloomday,k,i);
        if(cnt>=m){
            return i;
        }
    }
    return -1;
}

int cntdaysOptimal(vector<int>& bloomday,int m,int k){
    int n=bloomday.size();
    if(1ll*m*k > n){
        return -1;
    }
    int minval=*min_element(bloomday.begin(),bloomday.end());
    int maxval=*max_element(bloomday.begin(),bloomday.end());
    int ans{-1};
    int l{minval};
    int h{maxval};
    while(l<=h){
        int mid=l+(h-l)/2;
        int cnt=cntBouquets(bloomday,k,mid);
        if(cnt>=m){
            ans=mid;
            h=mid-1;
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

    int m{};
    cin>>m;

    int k{};
    cin>>k;

    cout<<cntdaysBrute(nums,m,k)<<"\n";
    cout<<cntdaysOptimal(nums,m,k)<<"\n";

}
