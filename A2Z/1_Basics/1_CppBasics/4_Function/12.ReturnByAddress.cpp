/*
🔁 1. What is Return by Address?
Returning by address means a function returns a pointer (T*) to a variable (usually dynamically or statically allocated memory), instead of returning the value directly.
    int* getAddress() {
        int* p = new int(10);  // dynamically allocate int
        return p;              // return pointer (address)
    }

🧠 2. Why and When to Use Return by Address?                                   
Dynamic memory allocation	        
    -You want the result to persist after function ends

Modify returned data later	
    -You want to change the value via pointer

Performance (large objects)	
    -You avoid copying large data by returning an address

Return multiple outputs (with arrays or structs)	    
    -One way is to return address of allocated memory

🔧 3. Syntax
    DataType* functionName(parameters) {
        // allocate memory or reference to a variable
        return pointer;
    }

🔬 4. Example 1: Return address of dynamically allocated int
*/
#include <iostream>
using namespace std;

int* createNumber() {
    int* ptr = new int(42); // allocated on heap
    return ptr;
}

int main() {
    int* result = createNumber();
    cout << "Value: " << *result << endl;  // 42

    delete result; // free the memory
    result = nullptr;
}

/*
🔍 Memory Diagram
Heap:
+-----+
|  42 | <- allocated by new int(42)
+-----+
   ^
   |
  result (pointer in main)

🧪 Example 2: Return address of a local variable (⚠️ WRONG)
    int* badFunction() {
        int x = 5;       // local variable on stack
        return &x;       // ❌ BAD! x will be destroyed after function ends
    }

❌ Problem:
•x is stored on stack and gets destroyed when function returns.
•Dereferencing this pointer later is undefined behavior (UB).

🛠️ 5. Safer Alternative: Use static variable
    int* getStatic() {
        static int x = 100;  // stored in static storage
        return &x;           // ✅ safe
    }

    int main() {
        int* p = getStatic();
        cout << *p << endl;  // prints 100
    }

✅ Why safe?
Static variables live throughout program lifetime, not destroyed after function ends.

⚠️ 6. Edge Cases & Dangers
Issue	                            Description
Memory leak	                        If new is used but delete is never called
Dangling pointer	                Returning address of local variable
Ownership confusion	                Not knowing who should delete the pointer
Returning pointer to temporary	    Like: return &a + b; or &some_func()

✅ 7. Best Practices
Tip	                                    Why
Use new only when you must	            Prefer smart pointers (std::unique_ptr)
Avoid returning address of local vars	Causes undefined behavior
Free memory using delete	            Prevent memory leaks
Consider static if value persists	    For controlled persistent values
Document who owns returned pointer	    To manage deletion properly

🧪 Example 3: Return address of an array
    int* createArray(int size) {
        int* arr = new int[size];  // dynamic array
        for (int i = 0; i < size; ++i)
            arr[i] = i;
        return arr;
    }

    int main() {
        int* p = createArray(5);
        for (int i = 0; i < 5; ++i)
            cout << p[i] << " ";  // 0 1 2 3 4
        delete[] p;
    }

*/
