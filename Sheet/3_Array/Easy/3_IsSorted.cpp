/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

Example 1
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

Example 2
Input : nums = [1, 2, 1, 4, 5]
Output : false
Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
*/

#include<iostream>
using namespace std;

bool issortedbrute(int arr[],int n){
    for(int i{};i<n-1;++i){
        for(int j{i+1};j<n;++j){
            if(arr[j]<arr[i]){
                return false;
            }
        }
    }
    return true;
}

bool issortedOptimal(int arr[],int n){
    for(int i{};i<n-1;++i){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n{};
    cin>>n;

    int arr[101];
    for(int i{};i<n;++i){
        cin>>arr[i];
    }

    cout<<issortedbrute(arr,n)<<"\n";
    cout<<issortedOptimal(arr,n)<<"\n";
}
