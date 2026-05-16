/*
🧠 Pass by Value in C++ – The Complete Guide
✅ What is Pass by Value?
When you pass an argument by value, a copy of the actual parameter is made and passed to the function.
The original variable remains unchanged.
Modifications made inside the function affect only the copy.

🧪 Syntax
    void func(int x) {
        x = x + 5; // Modify the copy
    }

    int main() {
        int a = 10;
        func(a);
        cout << a; // Output: 10 (unchanged)
    }

🧠 Memory Behavior
Call Stack:

Before call:
main:
 └── a = 10

During call:
main:
 └── a = 10
func:
 └── x = 10  ← copy of a

After call:
main:
 └── a = 10  ← unaffected

⚙️ Working Example
*/
#include <iostream>
using namespace std;

void increment(int num) {
    num = num + 1;
    cout << "Inside function: num = " << num << endl;
}

int main() {
    int x = 5;
    increment(x);
    cout << "In main: x = " << x << endl;
    return 0;
}
/*
🔸 Output:
Inside function: num = 6
In main: x = 5

🔍 Use Case: When to Use Pass by Value
•When the function does not need to modify the original variable.
•When the data being passed is small in size (e.g., int, char, float).
•When safety is needed (no risk of modifying caller’s data).

📦 Data Types in Pass by Value
Type	                    Behavior
int, char, float, etc.	    Copied (safe)
std::string	                Copy constructor is called
Custom class	            Copy constructor is invoked
Pointer	                    Pointer value is copied (but points to same location!)

⚠️ Edge Cases
🔸 1. Modifying the copy has no effect
    void change(int n) {
        n = 100;
    }

    int main() {
        int a = 10;
        change(a);
        cout << a; // 10 (unchanged)
    }

🔸 2. Passing a pointer by value (dangerous!)
    void modify(int* p) {
        p = nullptr; // p is a copy, this has no effect outside
    }

    int main() {
        int x = 10;
        int* ptr = &x;
        modify(ptr);
        cout << *ptr; // Output: 10 (not null)
    }
✅ The pointer itself is passed by value, so nullifying it doesn't affect original.

🔸 3. Expensive copy for large objects
    class Big {
        int arr[100000]; // large data
    };

void process(Big obj); // creates full copy — inefficient
✅ Use const Big& instead to avoid unnecessary copy.

🔸 4. Passing const by value
    void show(const int val) {
        // val is a copy anyway, but `const` protects accidental modification
    }

🚫 Common Mistake
Expecting that a function modifies the original when using value:
    void addTen(int n) {
        n += 10;
    }

    int main() {
        int x = 10;
        addTen(x);
        cout << x; // Output: 10 ❌ Not 20
    }

🧮 Swapping using pass-by-value (doesn’t work):
    void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int main() {
        int x = 10, y = 20;
        swap(x, y);
        cout << x << " " << y; // Output: 10 20 ❌
    }

✅ Swapping using reference (just for clarity):
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
*/
