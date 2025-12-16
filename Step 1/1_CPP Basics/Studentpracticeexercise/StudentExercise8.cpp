#include <iostream>
using namespace std;

// Linear search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Not found
}

int main() {
    int A[9];
    int size = 5;  // We are taking input of only 5 elements

    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < size; ++i)
        cin >> A[i];

    cout << "You entered:\n";
    for (int i = 0; i < size; ++i)
        cout << A[i] << ' ';
    cout << endl;

    int key;
    cout << "Enter the number to search: ";
    cin >> key;

    int index = linearSearch(A, size, key);  // use A, not arr

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
