/*
int A[]; is correct because in C and C++, when declaring an array without specifying its size, you must initialize it with values. Without a size or initialization, the declaration is considered invalid.

✅ 1. Array Declaration Without Initialization
    int A[5];  // Declared but not initialized — contains garbage values

✅ 2. Array Declaration With Partial Initialization
    int A[5] = {2, 4};  // First 2 values set, rest are 0
🧠 Output: 2 4 0 0 0 — because unspecified values get 0.

✅ 3. Array Declaration With Complete Initialization
    int A[5] = {2, 4, 6, 8, 10};

✅ 4. Compiler-Sized Array Declaration
    int A[] = {10, 20, 30, 40};  // Compiler sets size to 4
🧠 This is useful when you're just initializing and don't want to count manually.


✅ 5. Accessing Array Elements via Index
    int A[5] = {1, 2, 3, 4, 5};

    std::cout << "First element: " << A[0] << '\n';
    std::cout << "Third element: " << A[2] << '\n';
    std::cout << "Last element: " << A[4] << '\n';

✅ 6. Modify Array Elements
    int A[5] = {1, 2, 3, 4, 5};

    A[2] = 10;  // Modify 3rd element
🧠 Output: 1 2 10 4 5 

🧠 Why uninitialized elements of an array don’t become 0 by default?
It depends on how and where the array is declared:
🔹 Case 1: Local Array (Inside a Function)
    int arr[10]; // inside main or any function
🔴 Result: Garbage values
	•	C++ does not initialize local variables by default.
	•	So if you input only 7 elements, the remaining 3 hold whatever was in memory (i.e., garbage).

🔹 Case 2: Local Array with Zero Initialization
    int arr[10] = {};  // or = {0};
✅ Result: All elements will be 0
	•	This forces zero initialization of all elements.
	•	If you input 7, the rest will still be 0.

🔹 Case 3: Global or Static Array
    static int arr[10];
    or
    int arr[10]; // declared outside main
✅ Result: All elements are initialized to 0 by default

🧠 Why It Happens:
	•	Global & static arrays live in global memory — C++ automatically sets them to 0 for you.
	•	Local arrays live in stack memory, and the compiler doesn’t clean them up → so you get random garbage.
    */
#include <iostream>

// This is a **global array**
int globalArr[5];  // ✅ Automatically set to 0

void testStatic() {
    // This is a **static array**
    static int staticArr[5];  // ✅ Also set to 0

    std::cout << "Static Array:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << staticArr[i] << ' ';
    std::cout << '\n';
}

int main() {
    // This is a **local array**
    int localArr[5];  // ❌ Will contain garbage values

    std::cout << "Global Array:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << globalArr[i] << ' ';
        
    std::cout << '\n';

    std::cout << "Local Array:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << localArr[i] << ' ';  // ❌ Garbage
    std::cout << '\n';

    testStatic();

    return 0;
}
