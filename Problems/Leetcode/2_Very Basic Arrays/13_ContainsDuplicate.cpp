#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

bool ContainsDuplicateMap(const vector<int>& nums){
    int n=nums.size();
    unordered_map<int,int> mp;
    for(const auto& x:nums){
        ++mp[x];
        if(mp[x]==2){
            return true;
        }
    }
    return false;
}

bool ContainsDuplicatesSet(const vector<int>& nums){
    unordered_set<int> st;
    for(auto x:nums){
        if(st.count(x)){
            return true;
        }
        st.insert(x);
    }
    return false;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(auto& x: nums){
        cin>>x;
    }

    cout<<ContainsDuplicateMap(nums)<<"\n";
    cout<<ContainsDuplicatesSet(nums)<<"\n";
}
