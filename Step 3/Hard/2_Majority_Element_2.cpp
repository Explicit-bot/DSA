#include<iostream>
#include<vector>
using namespace std;

vector<int> MajorityElementBrute(vector<int> nums){
    int n=nums.size();
    vector<int> ans{};

    for(int i{};i<n;++i){
        int targ{nums[i]};
        int cnt{1};
        for(int j{i+1};j<n;++j){
            if(targ==nums[j]){
                ++cnt;
            }
        }
        if(cnt>n/3 && ans.back()!=ans[0]){
            ans.push_back(targ);
        }
        if(ans.size()==2){
            return ans;
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

    vector<int> ans=MajorityElementBrute(nums);

    for(auto x:ans){
        cout<<x<<" ";
    }

}
