#include<iostream>
#include<vector>
using namespace std;

//Iterative Bubble Sort(Brute Force)
void bubbleSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

//Iterative Bubble Sort(Optimal)
void bubbleSortOptimized(vector<int>& nums) {
    int n = nums.size();

    for (int i = n - 1; i > 0; --i) {
        bool swapped = false;

        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }    
    }
}


//Recursive Bubble Sort(Brute Force)
void BubbleSortRec(vector<int>& nums,int n){
    if(n==1){
        return;
    }

    for(int j{};j<n-1;++j){
        if(nums[j]>nums[j+1]){
            swap(nums[j],nums[j+1]);
            
        }
    }
    BubbleSortRec(nums,n-1);
}

//Recursive Bubble Sort(Optimal)
void BubbleSortRecOptimized(vector<int>& nums,int n){
    if(n==1){
        return;
    }
    bool didntswap=true;
    for(int j{};j<n-1;++j){
        if(nums[j]>nums[j+1]){
            swap(nums[j],nums[j+1]);
            didntswap=false;
        }
    }
    if(didntswap){
        return;
    }
    BubbleSortRecOptimized(nums,n-1);
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
    cout << endl;

    // Choose ONE
    // bubbleSort(nums);
    // bubbleSortOptimized(nums);
    // BubbleSortRec(nums, n);
    BubbleSortRecOptimized(nums, n);

    cout << "Sorted array:\n";
    for (int x : nums) cout << x << " ";
    cout << endl;

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
