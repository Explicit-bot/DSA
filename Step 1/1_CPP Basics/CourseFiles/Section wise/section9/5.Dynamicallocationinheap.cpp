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

✅ Summary:
Feature	            Stack Array	        Heap Array
Size Known At	    Compile-time	    Run-time
Resizable	        ❌ No	            ✅ Yes (via reallocation)
Memory Lifetime	    Automatic	        Manual (needs delete[])
Performance	        Fast	            Slower than stack

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

/*
What is Dynamic memory in Heap?
Dynamic memory is created in Heap using pointers.
We can use Dynamic memory for creating Array, Linked List, Trees, Map etc. (These are called as Data Structures)
Heap memory can be accessed from anywhere in the program, if its
address is available.
Heap Memory can be used for storing data of entire application.

Application of Dynamic memory?
We take a example of Chrome browser and discuss from Chrome side..
When we open chrome browser, it doesn’t know how many tabs user will open.
It will keep the first tab ready with Google page open. 
Pages are downloaded from internet and kept in the memory of Chrome
program.Downloaded page is kept in heap memory.
When we open new tab then memory is created in heap for that page.
When we close a tab the memory should be deleted, as it is not in use.
Conclusion: we may be opening and closing many tabs.
Chrome doesn’t know how many we will open.
Chrome should allocate memory for the pages at runtime.
It will allocate pages Dynamically in Heap memory and delete them when
not required.

Dangling Pointer
If a pointer is having an address of a memory location which is
already deallocated.
example:
    int *p=new int[5];
    delete []p;
Now p is a Dangling pointer.

✅ How to prevent dangling pointers?
 - Set pointer to nullptr after delete:
    delete p;
    p = nullptr;
 - Avoid returning addresses of local variables.
 - Use smart pointers (std::unique_ptr, std::shared_ptr) in modern C++ — they handle memory safely and automatically.
 - Avoid raw pointers when possible. Prefer references or smart pointers.


NULL vs nullptr
NULL:
•it is a constant whose value is 0.
•NULL means, pointer is not pointing on any valid location.
•In place of NULL, 0 can be used.
•Using 0 I place of NULL may create confusion for programmer.
nullptr 
•It is a keyword in C++.
•nullptr means, pointer is not pointing on any valid location.(same
as NULL)
•Nullptr doesn’t mean 0.
•0 cannot be used in its place. 
*/
