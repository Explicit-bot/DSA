/*
🔹 1. What is an Array?
An array is a collection of elements of the same data type, stored contiguously in memory.
Each element is accessed by its index, starting from 0.

🔹 2. Array Declaration & Initialization
        int arr[5];       // Declares an array of 5 ints (default values are garbage)
        int arr2[5] = {1, 2, 3};    // Partial init → {1, 2, 3, 0, 0}
        int arr3[] = {1, 2, 3, 4};  // Compiler decides size → size = 4

🔹 3. Input/Output
        int n, arr[100];
        std::cin >> n;     //n<=100
        
        //Input
        for(int i = 0; i < n; ++i)
            std::cin >> arr[i];

        //Output
        for(int i = 0; i < n; ++i)
            std::cout << arr[i] << " ";

🔹 4. Array Bounds
❌ No bounds checking in C++:
        int arr[100];
        arr[1000] = 10;  // ❌ Undefined Behavior 

🔹 5. Memory in Arrays
•int arr[5] stores 5 integers contiguously
•Access time: O(1)
•Works great with loops and pointer arithmetic

🧠 Where are arrays stored in C++?
🔹 It depends on how the array is declared:
                
✅ 1. Stack Memory — for local arrays
        int A[5] = {1, 2, 3, 4, 5};  // Local array
•Stored in the stack.
•Fast allocation and deallocation.
•But size is limited (usually up to ~1MB total).
•Lifespan: ends when the function ends.

✅ 2. Heap Memory — for dynamically allocated arrays
        int* A = new int[n];  // Dynamic array
        A  ----->  Heap memory [ ?, ?, ?, ?, ? ]      (each ? is an int, currently uninitialized contains garbage value)
        ✅ Use () or {} to zero initialize
•new int[5] returns the starting address of that block.
•A is a pointer
•Size is decided at runtime
•Use new for large or dynamic size.
•Must use delete[] to free memory.
•Lifespan: until explicitly deallocated.
•Use vectors instead.

✅ 3. Global / Static Memory — for global or static arrays
        int A[1000000];       // Global array → stored in global/ static segment

        void f() {
                static int B[100];  // Static array → also global/static segment
        }

•Stored in the global/static segment of memory.
•Initialized to zero by default.
•Lifespan: entire program runtime.

🧠 What is a static array?
A static array is an array whose:
memory is allocated in the static / global memory segment
lifetime = entire program execution
values persist (not destroyed when a function ends)

✅ Two ways an array becomes “static”
1️⃣ Global array (automatically static)
int arr[5];   // global

📍 Stored in global/static memory
⏳ Exists from program start → program end
🟢 Auto-initialized to 0

2️⃣ Static array inside a function
void f() {
    static int arr[5];
}

Even though it’s inside a function 👆
👉 it is NOT on stack
📍 Stored in static memory
⏳ Lifetime = whole program
🟢 Initialized only once

❌ What a static array is NOT
Stack array vs Static array
void f() {
    int a[3];        // stack array
    static int b[3]; // static array
}

Feature	                a (stack)	        b (static)
Memory	                Stack	                Static segment
Lifetime	        Function only	        Whole program
Init	                Garbage	                Zero
Persists value	        ❌	                ✅


❓ What does this do in C++:
        int A[5] = {10, 20, 30, 40, 50};
        std::cout << A;
•Here,A is actually a pointer to the first element: A == &A[0]

🧠 Output:
This will not print the array elements.
🔸 Instead, it prints the memory address of the first element of the array A.
        For example, you might see something like:
                0x7ffeefbff5a0

✅ Correct Way to Print the Array:(mentioned below)
*/
#include <iostream>

int main(){
        int n, arr[10];
        std::cout << "Enter number of elements (max 10): ";
        std::cin >> n;
        /*
        If n = 7, the program only takes input for the first 7 elements.
        The remaining elements (arr[7], arr[8], arr[9]) are uninitialized,
        so accessing them may give garbage values.
        */
        for(int i = 0; i < n; ++i){
                std::cout<<"Enter element no. "<<i<<":";
                std::cin >> arr[i];
        }
        
        for(int i = 0; i < 10; ++i){
                std::cout << arr[i] << " ";

        }
        std::cout<<"\n";

        std::cout<<arr+1;
}

/*
| Array Type  | Local (Stack) | Global / Static |
| ----------- | ------------- | --------------- |
| int         | ≤ 10⁶         | ≤ 10⁷           |
| long long   | ≤ 5×10⁵       | ≤ 5×10⁶         |
| bool        | ≤ 10⁷         | ≤ 10⁸           |
| char        | ≤ 10⁷         | ≤ 10⁸           |

*/
