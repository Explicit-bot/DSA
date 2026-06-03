/*
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

Example 1
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation:
The largest value in nums is 8, the second largest is 7

Example 2
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation:
The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int slargestBrute(vector<int> nums){        //we can pass by reference here if orignal
                                             //array is not required to be preserved
    if (nums.size()<2){
        return -1;
    }

    sort(nums.begin(),nums.end());  //O(NlogN)

    for(int i{1};i<nums.size();++i){     //O(N)
        if(*(nums.end()-i)!=*(nums.end()-i-1)){
            return *(nums.end()-i-1);
        }
    }
    return -1;
}

int slargestbetter(vector<int> nums){
    if(nums.size()<2){
        return -1;
    }
    int largest{INT_MIN};
    int slargest{INT_MIN};
    for(int i{};i<nums.size();++i){     //O(N)
        if(nums[i]>largest){
            largest=nums[i];
        }
    }

    for(int i{};i<nums.size();++i){     //O(N)
        if(nums[i]<largest&&nums[i]>slargest){
            slargest=nums[i];
        }
    }

    if(slargest==INT_MIN){
        return -1;
    }
    else{
        return slargest;
    }
}

pair<bool,int> slargestoptimal(vector<int> nums){
    if(nums.size()<2){
        return {false,-1};
    }

    int largest{nums[0]};
    int slargest{INT_MIN};
    bool found=false;

    for(int i{1};i<nums.size();++i){    //O(N)
        if(largest<nums[i]){
            slargest=largest;
            largest=nums[i];
            found=true;
        }
        else if(nums[i]<largest&&slargest<nums[i]){
            slargest=nums[i];
            found=true;
        }
    }
    if(found==false){      //Think why
        return {false,-1};
    }
    else{
        return {true,slargest};
    }
}


int main(){
    int n{};
    cout<<"Enter no. of elements:";
    cin>>n;

    int temp{};
    vector<int> nums{};
    for(int i{};i<n;++i){   
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<"The second largest no. is(using brute):"<<slargestBrute(nums)<<"\n";
    cout<<"The second largest no. is(using better):"<<slargestbetter(nums)<<"\n";
    cout<<"The second largest no. is(using optimal):"<<slargestoptimal(nums).first<<","<<slargestoptimal(nums).second<<"\n";
}
