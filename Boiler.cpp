#include<iostream>
#include<vector>
using namespace std;

vector<int> B(vector<int> nums){
    int n=nums.size();

}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    for(auto x:nums){
        cout<<x<<" ";
    }

}
