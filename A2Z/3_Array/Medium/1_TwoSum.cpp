#include <iostream>
#include <vector>
using namespace std;

vector <int> TwoSumBrute(vector<int>& nums,int target){
    for(int i{};i<nums.size();++i){
        for(int j{i+1};j<nums.size();++j){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

vector<int> TwoSumMap(vector<int>& nums,int target){
    unordered_map<int,int> numidxpair{};  //O(N) but O(N^2) in worst
    //map<int,int> numidxpair{}; //O(NlogN)  
    for(int i{};i<nums.size();++i){
        int alt=target-nums[i];
        if(numidxpair.find(alt)!=numidxpair.end()){
            return {numidxpair[alt],i};
        }
        numidxpair[nums[i]]=i;
    }
    return {-1,-1};
}

vector<int> TwoSumTwoPointer(vector<int>& nums,int target){
    vector<pair<int,int>> hash{};
    for(int i{};i<nums.size();++i){
        hash.push_back({nums[i],i});
    }
    sort(hash.begin(),hash.end());
    int left{};
    int right{nums.size()-1};
    while(left<right){
        if(hash[left].first+hash[right].first>target){
            --right;
        }
        else if(hash[left].first+hash[right].first<target){
            ++left;
        }
        else{
            return {hash[left].second,hash[right].second};
        }
    }
    return {-1,-1};
}


/*
| Rank | Approach              | Time                  | Space |
| ---- | --------------------- | --------------------- | ----- |
| 🥇 1 | HashMap               | O(N) avg, O(N²) worst | O(N)  |
| 🥈 2 | Two Pointer + Sorting | O(N log N)            | O(N)  |
| 🥉 3 | Brute Force           | O(N²)                 | O(1)  |
*/
