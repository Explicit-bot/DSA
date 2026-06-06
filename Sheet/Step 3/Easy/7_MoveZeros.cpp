/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 104
-2^31 <= nums[i] <= 2^31 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

//Brute (O(n),O(n))
void moveZeroesBrute(vector<int> nums) {
    int n=nums.size();
    vector<int> temp{};
    for(int x:nums){
        if(x!=0){
            temp.push_back(x);
        }
    }
    int cnt{n-temp.size()};
    while(cnt>0){
        temp.push_back(0);
        --cnt;
    }

    for(int i{}; i<n; ++i){
        nums[i] = temp[i];
    }
}


//Optimal
void moveZeroesOptimal(vector<int>& nums) {
    int n=nums.size();
    int i{};

    if(n<2){
        return;
    }

    for(int j{1};j<n;++j){
        if(nums[i]!=0){
            ++i;
        }

        if(nums[j]!=0&&nums[i]==0){
            nums[i]=nums[j];
            nums[j]=0;
            ++i;
        }
    }
}

int main(){
    int n{};
    cin>>n;

    vector <int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    moveZeroesBrute(nums);
    //moveZeroesOptimal(nums);

    for(auto x:nums){
        cout<<x<<" ";
    }
    cout<<"\n";
}
