/*
🔷 Stack vs Heap Allocation in C++
✅ Stack Allocation:
        int arr[5]; // fixed size, compile-time
 - The size must be known at compile-time (except in compilers that support VLAs, which are non-standard in C++).
 - Memory is managed automatically.
 - You cannot resize it later.
 - Fast access, but limited in size.

✅ Heap Allocation:
        int* arr = new int[n]; // size can be decided at run-time
 - The size is decided at run-time.
 - You can deallocate and reallocate to simulate resizing:
        delete[] arr;
        arr = new int[new_size];
 - This gives the flexibility to "change size", though it's technically creating a new array and copying values.

🧠 Why Can't Stack Arrays Change Size?
Because stack memory is static and contiguous, and:
 - The compiler reserves a fixed amount of memory at compile-time.
 - You can't shift or extend that reserved memory block during runtime.
 - It ensures fast access but no flexibility.

🧠 Why Can Heap Arrays Be Resized?
Because:
 - The heap is a large pool of memory managed at runtime.
 - You can allocate, deallocate, and reallocate memory dynamically using new and delete.
 - But resizing still means creating a new block and copying data if needed.

*/
//program for dynamic allocation in heap

#include <iostream>

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamic allocation of array in heap
    int* arr = new int[size];  // allocate memory

    // Taking input
    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": ";
        std::cin >> arr[i];
    }

    // Displaying the array
    std::cout << "You entered:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Freeing the allocated memory
    delete[] arr;

    return 0;
}
