/*
🔹 1. What is an Array?
An array is a collection of elements of the same data type, stored contiguously in memory.
Each element is accessed by its index, starting from 0.

🔹 2. Array Declaration & Initialization
        I. Array Declaration Without Initialization
        int A[5];  // Declared but not initialized — contains garbage values

        II. Array Declaration With Partial Initialization
        int A[5] = {2, 4};  // First 2 values set, rest are 0
        🧠 Output: 2 4 0 0 0 — because unspecified values get 0.

        III. Array Declaration With Complete Initialization
        int A[5] = {2, 4, 6, 8, 10};

        IV. Compiler-Sized Array Declaration
        int A[] = {10, 20, 30, 40};  // Compiler sets size to 4
        🧠 This is useful when you're just initializing and don't want to count manually.
        
        * Only int A[]; is incorrect because in C and C++, when declaring an array without specifying its size, you must initialize it with values. Without a size or initialization, the declaration is considered invalid.

🔹 3. Accessing Array Elements via Index
    int A[5] = {1, 2, 3, 4, 5};

    First element: A[0]
    Third element: A[2]
    last element: A[4]

🔹 4. Modify Array Elements
    int A[5] = {1, 2, 3, 4, 5};
    A[2] = 10;  // Modify 3rd element
🧠 Output: 1 2 10 4 5 

🔹 3. Input/Output
        int n, arr[100];
        std::cin >> n;     //n<100 
        
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

Note:-
•Global & static arrays live in global memory — C++ automatically sets them to 0 for you.
•Local arrays live in stack memory, and the compiler doesn’t clean them up → so you get random garbage.

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
🟢 Initialized only once meaning that it is created once and it persists for whole program

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

E.g:
void fun() {
    static int arr[3] = {1,2,3};
    int arr2[3]={1,2,3};
    arr[0]++;
    arr2[0]++;

    cout <<"Static array:"<<arr[0] << endl;
    cout <<"Local array:"<<arr2[0] << endl;
}

int main() {
    fun();
    fun();
    fun();
}

output:
Static array:2
Local array:2

Static array:3
Local array:2

Static array:4
Local array:2

❓ What does cout << array do in C++:
        int A[5] = {10, 20, 30, 40, 50};
        std::cout << A;
•Here,A is actually a pointer to the first element: A == &A[0]

🧠 Output:
This will not print the array elements.
🔸 Instead, it prints the memory address of the first element of the array A.
        For example, you might see something like:
                0x7ffeefbff5a0
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
    
    std::cout<<localArr<<"\n";  //Its a pointer so it prints address.
    
    return 0;
}

/*
| Array Type  | Local (Stack) | Global / Static |
| ----------- | ------------- | --------------- |
| int         | ≤ 10⁶         | ≤ 10⁷           |
| long long   | ≤ 5×10⁵       | ≤ 5×10⁶         |
| bool        | ≤ 10⁷         | ≤ 10⁸           |
| char        | ≤ 10⁷         | ≤ 10⁸           |

*/
