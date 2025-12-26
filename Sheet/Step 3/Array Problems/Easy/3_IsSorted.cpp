#include <iostream>
using namespace std;

bool IsSorted(vector<int> &nums){
    for(int i{1};i<nums.size();++i){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<IsSorted(nums);
}
