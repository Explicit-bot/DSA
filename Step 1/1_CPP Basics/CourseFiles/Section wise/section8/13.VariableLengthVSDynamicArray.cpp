/*
🔢 What is a Variable Length Array (VLA)?
A Variable Length Array (VLA) is an array whose size is determined at runtime, but it's created on the stack.

✅ Example:
        int n;
        std::cin >> n;      // user enters 5
        int A[n];           // VLA: size 5, created at runtime on stack
 -Size is not fixed at compile-time
 -Available only in some compilers (like GCC)
 -NOT part of standard C++ (but it works as a compiler extension)

🧠 Key Properties of VLAs
 -Created on stack
 -Lifetime is limited to the block/function
 -Size can't be changed after declaration
 -Fast (stack is faster than heap), but limited in size (~1MB)

❌ VLAs Are Not Fully Portable
 -GCC (Linux/Mac): ✅ supports VLAs
 -MSVC (Windows Visual Studio): ❌ doesn't support VLAs
 -C++ Standard:❌ doesn't recognize VLAs officially (VLAs are standard in C99, not C++)

🧱 How to Declare & Initialize VLA
        int n;
        std::cin >> n;
        int A[n];            // declare
        for (int i = 0; i < n; ++i)
            std::cin >> A[i]; // initialize

🔁 Can VLAs be Resized?
❌ No — once you define int A[n];, the size is fixed
If you need to resize, you need a dynamic array (on heap)

📦 What is a Dynamic Array?
A dynamic array is allocated in heap memory using new.

✅ Example:
        int n;
        std::cin >> n;
        int* A = new int[n];     // dynamically allocate array on heap
 -Created using pointer
 -Lives until you manually delete it (delete[] A;)
 -Can be resized by creating a new one
 -Safer for large arrays (heap can handle more memory)

🔁 Resizing a Dynamic Array

        int* A = new int[n];
            // use A
        delete[] A;             // free old memory
        A = new int[2*n];       // resize by creating a new one


🧪 VLA vs Dynamic Array (Summary)
Feature	            Variable Length Array(VLA)	            Dynamic Array (new)
Where created	    Stack	                            Heap
Syntax	            int A[n];	                            int* A = new int[n];
Runtime sizing	    ✅ Yes	                            ✅ Yes
Resizable	    ❌ No	                            ✅ Yes (with new)
Lifetime	    Auto (ends with block)	             Manual (needs delete[])
Portability	    ❌ Not standard C++	            ✅ Fully standard
Use case	    Small, local arrays	             Large or persistent arrays

✅ Best Practices

Use VLA:
 - For temporary data in small arrays
 - In short functions (if GCC or Clang compiler is used)

Use Dynamic Arrays:
 - For larger data
 - When the size must change
 - When you need the array outside the current block

🚀 C++ Alternative (Recommended): std::vector
If you want dynamic behavior with safety, prefer:

        std::vector<int> A(n);

 - Auto memory management
 - Resizable with .push_back(), .resize(), etc.
 - Fully standard C++
*/
