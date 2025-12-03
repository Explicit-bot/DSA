/*
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
    int arr[10]; // declared outside any function
✅ Result: All elements are initialized to 0 by default
	•	Global/static variables are zero-initialized automatically by the compiler.    
🔍 Why This Happens:
	•	Global variables and static variables live in the data segment, not on the stack.
	•	The C++ runtime automatically initializes them to 0 before main() begins.
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
/*
🧠 Why It Happens:
	•	Global & static arrays live in global memory — C++ automatically sets them to 0 for you.
	•	Local arrays live in stack memory, and the compiler doesn’t clean them up → so you get random garbage.
*/
