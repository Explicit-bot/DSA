/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateBrute(int arr[],int n,int k){
    if(n==0){
        return;
    }

    k=k%n;
    vector<int> temp{};
    for(int i{n-k};i<n;++i){
        temp.push_back(arr[i]);
    }
    for(int i{};i<n-k;++i){
        temp.push_back(arr[i]);
    }
    
    for(int i{};i<n;++i){
        arr[i]=temp[i];
    }
}

void rotateOptimal(int arr[],int n,int k){
    if(n==0){
        return;
    }

    k=k%n;
    
    reverse(arr,arr+n);
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
}
