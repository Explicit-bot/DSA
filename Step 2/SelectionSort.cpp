#include<iostream>
#include<vector>
using namespace std;

//Iterative Selection sort
void selectionSort(vector<int>& nums) {
    for (int i{};i<nums.size()-1;++i){  //last element is already sorted in the end so n-1
        int min=i;
        for(int j{i+1};j<nums.size();++j){
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        swap(nums[i],nums[min]);
    }
}

//Recursive Selection Sort
void SelectionSort(vector<int>& nums,int i){
    if(i==nums.size()-1){
        return;
    }
    int min=i;
    for(int j=i+1;j<nums.size();++j){
        if(nums[j]<nums[min]){
            min=j;
        }
    }
    swap(nums[i],nums[min]);

    SelectionSort(nums,i+1);
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

    // Uncomment ONE at a time to test

    // selectionSort(nums);        // Iterative
    SelectionSort(nums, 0);        // Recursive

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
Stable → ❌ No
*/
