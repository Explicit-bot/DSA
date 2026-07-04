//Find the smallest element and place it at its correct position
// • Is it STABLE??
// • Is it in-place??
// • Is it adaptive??


#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& nums){
    int n=nums.size();
    for(int i{};i<n-1;++i){
        int min=i;
        for(int j{i+1};j<n;++j){
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        swap(nums[i],nums[min]);
    }
}

void selectionSortRecursive(vector<int>& nums,int i=0){
    int n=nums.size();
    if(i=n-1){
        return;
    }
    int min=i;
    for(int j{i+1};j<n;++j){
        if(nums[j]<nums[min]){
            min=j;
        }
    }
    swap(nums[i],nums[min]);
    selectionSortRecursive(nums,i+1);
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Original array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    // selectionSortIterative(nums);        // Iterative
    selectionSortRecursive(nums,0);        // Recursive

    cout << "Sorted array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;

}

/*
Time   → O(n²)
Space  → O(1) iterative | O(n) recursive (stack)
*/
