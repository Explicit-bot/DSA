#include<iostream>
#include<vector>
#include<set>
using namespace std;

int RemoveDuplicateBrute(vector<int>& nums){
    int n=nums.size();
    set<int> st;
    int idx{};
    for(auto x:nums){
        if(st.find(x)==st.end()){
            st.insert(x);
            nums[idx]=x;
            ++idx;
        }
    }
    return idx;
}

int RemoveDuplicatesOptimal(vector<int>& nums){
    int n=nums.size();
    int idx{};
    for(int i{1};i<n;++i){
        if(nums[i]!=nums[idx]){
            ++idx;
            nums[idx]=nums[i];
        }
    }
    return idx+1;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(auto& x: nums){
        cin>>x;
    }

    //RemoveDuplicateBrute(nums);
    RemoveDuplicatesOptimal(nums);
}
