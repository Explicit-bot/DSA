/*
Take current element and place it at its correct
position in the already sorted left part
*/

#include<iostream>
#include<vector>
using namespace std;

// Iterative Insertion Sort (Brute Force)
void insertionSort(vector<int>& nums) {
    int n=nums.size();

    for (int i{1}; i < n; ++i) {
        int j{i};

        while (j > 0 && nums[j] < nums[j - 1]) {
            swap(nums[j], nums[j - 1]);
            --j;
        }
    }
}

// Iterative Insertion Sort (Optimized)
void insertionSortOptimized(vector<int>& nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;

        // Shift elements instead of swapping
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

// Recursive Insertion Sort (Brute Force)
void insertionSortRec(vector<int>& nums, int n) {
    if (n <= 1) return;

    insertionSortRec(nums, n - 1);

    int j = n - 1;
    while (j > 0 && nums[j] < nums[j - 1]) {
        swap(nums[j], nums[j - 1]);
        --j;
    }
}

// Recursive Insertion Sort (Optimized)
void insertionSortRecOptimized(vector<int>& nums, int n) {
    if (n <= 1) return;

    insertionSortRecOptimized(nums, n - 1);

    int key = nums[n - 1];
    int j = n - 2;

    while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        j--;
    }
    nums[j + 1] = key;
}

//---------------------------------------------------
// MAIN FUNCTION (CUSTOM INPUT)
//---------------------------------------------------
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
     insertionSort(nums);
    // insertionSortOptimized(nums);
    // insertionSortRec(nums, n);
    //insertionSortRecOptimized(nums, n);

    cout << "Sorted array:\n";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}

/*
=====================================================
⏱️ TIME & SPACE COMPLEXITY
=====================================================

| Version                 | Best Case | Average Case | Worst Case | Space |
|-------------------------|-----------|--------------|------------|-------|
| Iterative (Brute)       | O(n)✅    | O(n²)        | O(n²)      | O(1)  |
| Iterative (Optimized)   | O(n)✅    | O(n²)        | O(n²)      | O(1)  |
| Recursive (Brute)       | O(n)✅    | O(n²)        | O(n²)      | O(n) |
| Recursive (Optimized)   | O(n)✅    | O(n²)        | O(n²)      | O(n) |

*O(n) due to recursion stack
=====================================================

📌 KEY POINTS:
✔ Insertion sort is STABLE
✔ Works very well for nearly sorted arrays
✔ Used internally in TimSort for small subarrays
✔ Better than bubble & selection sort in practice
=====================================================
*/
