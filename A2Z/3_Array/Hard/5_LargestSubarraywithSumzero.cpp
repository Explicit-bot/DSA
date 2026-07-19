#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxlenBrute(vector<int>& nums){
    int n=nums.size();
    int maxlen{};
    for(int i{};i<n;++i){
        int sum{};
        for(int j{i};j<n;++j){
            sum+=nums[j];
            if(sum==0){
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;    
}

int maxlenOptimal(vector<int>& nums){
    int n=nums.size();
    unordered_map <int,int> mp;
    int sum{};
    int maxlen{};
    for(int i{};i<n;++i){
        sum+=nums[i];
        if(sum==0){
            maxlen=i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            maxlen=max(maxlen,i-mp[sum]);
        }

        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }

    return maxlen;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }
    cout<<"Input Array:";
    for(auto x:nums){
        cout<<x<<" ";
    }

    cout<<"\n";

    cout<<maxlenBrute(nums)<<"\n";
    cout<<maxlenOptimal(nums)<<"\n";
}
