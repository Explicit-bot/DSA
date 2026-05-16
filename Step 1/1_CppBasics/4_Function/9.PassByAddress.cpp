/* 
✅ What is Pass by Address?
When a variable is passed by address, its memory location (pointer) is passed to the function.
•Changes made to the parameter using the pointer affect the original variable.
•This allows direct modification of the caller's data.
•Pointer dereferencing is used (*ptr) to access and modify values.

🧪 Syntax
    void func(int* ptr) {
        *ptr = *ptr + 5; // Dereference and modify original
    }

    int main() {
        int a = 10;
        func(&a);       // pass address of a
        cout << a;      // Output: 15
    }

🧠 Memory Behavior
main:
 └── a = 10          → Memory: 0x100 → value 10

func(ptr):
 └── ptr = 0x100     → *ptr = 10 (original)
 └── *ptr += 5       → *ptr = 15

main:
 └── a = 15 ✅
📌 The pointer ptr is passed by value, but the data it points to is the original.
🧠 What does "pointer is passed by value" mean?
When you call a function like this:
    int x = 10;
    func(&x);  // Passing address of x
    
Your function receives a copy of the pointer &x:
    void func(int* ptr) {
        // ptr is a copy of &x
    }

So inside the function:
•ptr holds the same address as &x (i.e., the memory location of x).
•But ptr itself is a separate variable — just like how passing an int makes a copy of the value.

🧠 So what's the difference?
Even though the pointer ptr is passed by value (i.e., copied), it still points to the original data in memory. This means:
•✅ You can use *ptr to modify the original data.
•❌ If you change ptr to point elsewhere, it won’t affect the original pointer in main.

⚙️ Working Example
*/
#include <iostream>
using namespace std;

void update(int* p) {
    *p = *p + 10;
    cout << "Inside function: *p = " << *p << endl;
}

int main() {
    int x = 20;
    update(&x);
    cout << "In main: x = " << x << endl;
    return 0;
}
/*
🔸 Output:
Inside function: *p = 30
In main: x = 30

📌 Use Cases: When to Use Pass by Address
•When you want to modify the original variable.
•When passing large data, and you want to avoid copying.
•When you want to return multiple values from a function.
•Dynamic memory manipulation, like arrays and linked lists.

🧪 Modifying Multiple Variables
void updateBoth(int* a, int* b) {
    *a += 1;
    *b += 2;
}

int main() {
    int x = 5, y = 10;
    updateBoth(&x, &y);
    cout << x << " " << y; // Output: 6 12
}

⚠️ Edge Cases and Gotchas
🔸 1. Null Pointer
    void func(int* p) {
        if (p == nullptr) return;
        *p = 10;
    }
✅ Always check for null before dereferencing.

🔸 2. Uninitialized Pointer
    void func(int* p) {
        *p = 5; // ❌ Undefined behavior if p is uninitialized
    }
✅ Ensure pointer is valid before calling the function.

🔸 3. Pointer Arithmetic
    void setAll(int* arr, int size) {
        for (int i = 0; i < size; ++i)
            *(arr + i) = i;
    }
Used heavily in arrays and memory blocks.

🔸 4. Changing the Pointer (no effect on caller)
    void makeNull(int* p) {
        p = nullptr; // only the copy of pointer is set to null
    }

    int main() {
        int x = 10;
        int* ptr = &x;
        makeNull(ptr);
        cout << *ptr; // Still prints 10 ✅
    }
📌 Pointer itself is passed by value, but points to same object.



🧮 Example: Swap Two Numbers
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main() {
        int x = 5, y = 10;
        swap(&x, &y);
        cout << x << " " << y; // Output: 10 5
    }
*/
