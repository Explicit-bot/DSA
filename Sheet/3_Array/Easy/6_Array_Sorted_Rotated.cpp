/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Brute force(O(n^2),O(n))
bool IsSorted(vector<int> nums){
    for(int i{};i<(nums.size()-1);++i){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    return true;
}

bool checkBrute(vector<int> nums){
    for(int i{};i<nums.size();++i){
        rotate(nums.begin(),nums.begin()+1,nums.end());
        if(IsSorted(nums)){
            return true;
        }
    }
    return false;
}

//Using min element approach(O(n),O(1))
bool checkBetter(vector<int>& nums){
    int n=nums.size();
    int minidx{};
    for(int i{1};i<n;++i){
        if(nums[minidx]>nums[i]){
            minidx=i;
        }
    }

    //left check
    for(int i{};i<minidx-1;++i){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }

    //right check
    for(int i{minidx};i<n-1;++i){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    //Boundary check
    if(minidx!=0&&nums[0]<nums[n-1]){
        return false;
    }

    return true;
}

//Optimal   (O(n),O(1))
bool checkOptimal(vector<int> nums){
    int cnt{};
    for(int i{};i<(nums.size()-1);++i){
        if(nums[i]>nums[i+1]){
            ++cnt;
        }   
    }
    if(nums[0]<nums[nums.size()-1]){
        ++cnt;
    }

    return cnt<=1;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<checkBrute(nums)<<"\n";
    cout<<checkBetter(nums)<<"\n";
    //cout<<CHECK(nums)<<"\n";
    
}
