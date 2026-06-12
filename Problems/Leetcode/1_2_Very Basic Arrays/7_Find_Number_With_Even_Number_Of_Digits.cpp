#include<iostream>
#include<vector>
using namespace std;

vector<int> FindNumWithEven(vector<int>& nums){
    vector<int> ans;
    for(auto x:nums){
        int digi=(int)(log10(x)+1);
        if(digi%2==0){
            ans.push_back(x);
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
    
    vector<int> ans=FindNumWithEven(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }

}
