#include <iostream>
#include <vector>
using namespace std;

//MinIndex
int linearSearch(vector<int>& nums, int target) {
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
    bool found=false;
    for(int i{};i<n;++i){
        if(nums[i]==target){
            cout<<i<<" ";
            if(!found) found = true;   // only once
        }
    }
    if(!found){
        cout<<-1<<"\n";
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

    int MinINdex=linearSearch(nums,target);
    cout<<MinINdex<<"\n";

    linearSearchAll(nums,target);   //indexes
    cout<<"\n";
}
