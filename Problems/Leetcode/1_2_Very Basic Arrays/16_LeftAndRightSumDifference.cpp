#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void LeftAndRight(vector<int>& nums){
    int n=nums.size();
    int totalsum{};
    int leftsum{};
    int current{};
    for(auto x:nums){
        totalsum+=x;
    }

    for(int i{};i<n;++i){
        current=nums[i];
        int rightsum=totalsum-leftsum-current;
        nums[i]=abs(leftsum-rightsum);
        leftsum+=current;
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    LeftAndRight(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }
}
