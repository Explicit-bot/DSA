#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int l, int h) {
    int piv = nums[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (nums[i] <= piv && i <= h - 1) {
            i++;
        }
        while (nums[j] > piv && j >= l + 1) {
            j--;
        }
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[l], nums[j]);
    return j;
}

void quicksort(vector<int>& nums, int l, int h) {
    if (l < h) {
        int pi = partition(nums, l, h);
        quicksort(nums, l, pi - 1);
        quicksort(nums, pi + 1, h);
    }
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
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    quicksort(nums, 0, n - 1);  // 🔥 FIXED

    cout << "Sorted array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
