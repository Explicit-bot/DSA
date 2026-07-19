// • Take current element and place it at its correct position in the already sorted left part
// • Used internally in TimSort for small subarrays
// • Is it STABLE??
// • Is it in-place??
// • Is it adaptive??

/*
Default arguments must come from right to left.
Meaning:
once one parameter has a default value,
all parameters after it must also have default values.
*/

#include<iostream>
#include<vector>
using namespace std;

void InsertionSortIterativeSwap(vector<int>& nums){
    int n=nums.size();
    for(int i{1};i<n;++i){
        int j{i};

        while(j>0 && nums[j] < nums[j-1]){
            swap(nums[j],nums[j-1]);
            --j;
        }
    }
}

void InsertionSortIterativeShift(vector<int>& nums){
    int n=nums.size();

    for(int i{1};i<n;++i){
        int key=nums[i];
        int j{i};
        while(j>0 && key<nums[j-1]){
            nums[j]=nums[j-1];
            --j;
        }
        nums[j]=key;
    }
}

void InsertionSortRecursiveSwap(vector<int>& nums,int n,int i=1){
    if(i>=n){
        return;
    }  
    int j{i};
    while(j>0 && nums[j]<nums[j-1]){
        swap(nums[j],nums[j-1]);
        --j;
    }
    InsertionSortRecursiveSwap(nums,n,i+1);
}

void InsertionSortRecursiveShift(vector<int>& nums,int n,int i=1){
    if(i>=n){
        return;
    }  
    int j{i};
    int key=nums[i];
    while(j>0 && key<nums[j-1]){
        nums[j]=nums[j-1];
        --j;
    }
    nums[j]=key;
    InsertionSortRecursiveShift(nums,n,i+1);
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n,0);
    cout << "Enter elements:";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Original array:\n";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Choose ONE
    InsertionSortIterativeSwap(nums);
    // InsertionSortIterativeShift(nums);
    // InsertionSortRecursiveSwap(nums,n);
    // InsertionSortRecursiveShift(nums,n);
  

    cout << "Sorted array:\n";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}

/*
⏱️ TIME & SPACE COMPLEXITY
| Version                 | Best Case | Average Case | Worst Case | Space |
|-------------------------|-----------|--------------|------------|-------|
| Iterative eSwap)       | O(n)✅    | O(n²)        | O(n²)      | O(1)  |
| Iterative (Optimized)   | O(n)✅    | O(n²)        | O(n²)      | O(1)  |
| Recursive eSwap)       | O(n)✅    | O(n²)        | O(n²)      | O(n)  |
| Recursive (Optimized)   | O(n)✅    | O(n²)        | O(n²)      | O(n)  |
*O(n) due to recursion stack
*/
