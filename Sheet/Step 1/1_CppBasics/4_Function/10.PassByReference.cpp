/*
✅ What is Pass by Reference?
When a variable is passed by reference, the function receives an alias (another name) for the original variable.
•No copy is made.
•Changes affect the original.
•Internally, the reference is implemented like a pointer, but with clean syntax (no * or & inside the function body).

🧪 Syntax
    void func(int& ref) {
        ref += 10; // Modifies the original variable
    }

    int main() {
        int a = 5;
        func(a);   // Passed by reference
        cout << a; // Output: 15 ✅
    }

🧠 Memory Behavior
main:
 └── a = 5        → Memory: 0x100 → value 5

func(ref):
 └── ref → alias for a (same memory address 0x100)

ref += 10 ⇒ a = 15 ✅
🧠 No new memory is allocated for ref. It's another name for a.

⚙️ Working Example
*/
#include <iostream>
using namespace std;

void multiplyByTwo(int& num) {
    num *= 2;
    cout << "Inside function: num = " << num << endl;
}

int main() {
    int x = 10;
    multiplyByTwo(x);
    cout << "In main: x = " << x << endl;
    return 0;
}
/*
🔸 Output:
Inside function: num = 20
In main: x = 20

📌 Use Cases: When to Use Pass by Reference
•When you want the function to modify the caller's data.
•To avoid the overhead of copying large objects.
•When you want to return multiple values from a function.
•When you want cleaner syntax than pointers.

🔍 Modifying Multiple Variables
    void updateBoth(int& a, int& b) {
        a += 5;
        b += 10;
    }

    int main() {
        int x = 1, y = 2;
        updateBoth(x, y);
        cout << x << " " << y; // Output: 6 12 ✅
    }

⚠️ Edge Cases and Gotchas
🔸 1. Cannot Bind Reference to Literal or Temporary (non-const)
    void f(int& x) { x = 10; }

    f(5); // ❌ Error: cannot bind non-const reference to rvalue

✅ Fix using const int&:
    void f(const int& x); // ✅ OK with rvalues

🔸 2. Returning References — Be Careful
    int& getRef(int& x) {
        return x;
    }

    int main() {
        int a = 20;
        getRef(a) = 50;  // ✅ Modifies a
        cout << a;       // Output: 50
    }

But don’t return references to local variables:

int& badFunc() {
    int x = 10;
    return x; // ❌ Dangling reference — undefined behavior!
}


🧮 Swapping Two Numbers using Reference
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int main() {
        int x = 5, y = 10;
        swap(x, y);
        cout << x << " " << y; // Output: 10 5 ✅
    }

🧼 Best Practices
✅ Use const T& to pass large objects read-only without copying.
✅ Use non-const reference to modify caller variable.
❌ Don’t return references to local variables.
❌ Don’t bind references to temporary objects unless const.
*/
