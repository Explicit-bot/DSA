//Repeatedly push the largest element to the end through adjacent swaps 
// • Is it STABLE??
// • Is it in-place??
// • Is it adaptive??

#include<iostream>
#include<vector>
using namespace std;


void BubbleSortIterativeBrute(vector<int>& nums){
    int n=nums.size();
    for(int i{n-1};i>0;--i){
        for(int j{};j<i;++j){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

void BubbleSortIterativeOptimal(vector<int>& nums){
    int n=nums.size();
    for(int i{n-1};i>0;--i){
        bool swapped{false};
        for(int j{};j<i;++j){
            if(nums[j]>nums[j+1]){
              swap(nums[j],nums[j+1]);
              swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void BubbleSortRecursiveBrute(vector<int>& nums,int n){
    if(n==1){
        return;
    }

    for(int i{};i<n-1;++i){
        if(nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
        }
    }
    
    BubbleSortRecursiveBrute(nums,n-1);
}

void BubbleSortRecursiveOptimal(vector<int>& nums,int n){
    if(n==1){
        return;
    }

    bool swapped=false;
    for(int i{};i<n-1;++i){
        if(nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
            swapped=true;
        }
    }
    if(!swapped){
        return;
    }
    BubbleSortRecursiveOptimal(nums,n-1);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Original array:\n";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    
    //BubbleSortIterativeBrute(nums);
    //BubbleSortIterativeBrute(nums);
    //BubbleSortRecursiveBrute(nums, n);
    BubbleSortRecursiveOptimal(nums, n);

    cout << "Sorted array:\n";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}


/*
In optimized bubble sort, we check whether any swap occurred in a pass.
If no swap happens, the array is already sorted, so we stop early.

| Version               | Best Case  | Average Case | Worst Case | Space    |
| --------------------- | ---------- | ------------ | ---------- | -------- |
| Iterative (Brute)     | O(n²)      | O(n²)        | O(n²)      | O(1)     |
| Iterative (Optimized) | O(n)✅     | O(n²)        | O(n²)      | O(1)     |
| Recursive (Brute)     | O(n²)      | O(n²)        | O(n²)      | O(n)**   |
| Recursive (Optimized) | O(n)✅     | O(n²)        | O(n²)      | O(n)**   |

*/
