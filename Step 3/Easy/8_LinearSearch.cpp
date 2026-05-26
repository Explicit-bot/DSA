#include <iostream>
#include <vector>
using namespace std;

//MinIndex
int linearsearch(vector<int> nums,int target){
    int n=nums.size();
    for(int i{};i<n;++i){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}
//all indexes
void linearSearchAll(vector<int>& nums, int target) {
    int n=nums.size();
    bool found{};
    for(int i{};i<n;++i){
        if(nums[i]==target){
            cout<<i<<" ";
            if(!found){
                found=true;
            }
        }
    }
    if(!found){
        return;
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for (auto& x : nums){
        cin >> x;
    }

    int target{};
    cin>>target;

    
    cout<<linearsearch(nums,target)<<"\n";

    linearSearchAll(nums,target);   //indexes
    cout<<"\n";
}
