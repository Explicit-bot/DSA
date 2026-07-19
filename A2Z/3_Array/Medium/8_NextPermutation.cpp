#include<iostream>
#include<vector>
using namespace std;

//For Brute we can Genrate all permutations in sorted order then select next index whic is very high complexity as O(N!*N) atleast
vector<int> nextPermutationBrute(vector<int>& nums) {
    // Store all permutations
    vector<vector<int>> all;
    vector<int> temp{nums};
    // Generate all permutations
    sort(nums.begin(), nums.end());
    do {
        all.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    // Traverse the list to find current permutation
    for (int i = 0; i < all.size(); i++) {
        if (all[i] == temp) {
            // If it's the last permutation
            if (i == all.size() - 1)
                return all[0];
            // Return the next one
            return all[i + 1];
        }
    }

        // Return original if not found (shouldn't happen)
    return temp;
}

//For Better we can use the STL function next_permutation(); this will give us a clean code as actual algorithm was not here 
void nextPermutationBetter(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}


//Optimal(Internal Function of next_permutation())  ***
void NextPermutationOptimal(vector<int>& nums){
    int n=nums.size();
    int idx{-1};
    for(int i{n-1};i>0;--i){
        if(nums[i]>nums[i-1]){
            idx=i-1;
            break;
        }
    }

    if(idx==-1){
        reverse(nums.begin(),nums.end());
        return;
    }

    for(int i{n-1};i>idx;--i){
        if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
        }
    }
    reverse(nums.begin()+idx+1,nums.end());
}
