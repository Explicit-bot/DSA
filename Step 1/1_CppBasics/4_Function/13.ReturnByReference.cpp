/*
🧠 What is Return by Reference?
Returning by reference means the function returns an alias (i.e., a reference) to an existing variable rather than a copy.
    int& func() {
        static int x = 10;
        return x;  // returns a reference to x
    }

This allows the caller to access and even modify the original variable.

🔁 Comparison: Return Types
Return Type	            What is Returned	            Can Modify?	   Lifetime Matters?
By Value (int)	        Copy of the value	            ❌ No	        ❌ No
By Address (int*)	    Pointer to the value	        ✅ Yes	        ✅ Yes
By Reference (int&)	    Alias to original variable	    ✅ Yes	        ✅ Yes

🔧 Syntax of Return by Reference
    int& functionName() {
        // return reference to existing variable
    }

Note the & before function name's return type.

✅ Valid Example: Returning Reference to Static Variable
*/
#include <iostream>
using namespace std;

int& getCounter() {
    static int counter = 0;
    return counter;
}

int main() {
    getCounter() += 5;  // modifies static variable
    cout << getCounter() << endl;  // prints 5
}
/*
✅ Why is this safe?
The variable counter is static → it lives throughout the program's life.
So it's safe to return its reference.

🔥 Use Case: Chained Assignment / Modification
    int& get() {
        static int x = 100;
        return x;
    }

    int main() {
        get() = 50; // modifies x directly
        cout << get() << endl; // prints 50
    }

❌ Invalid Example: Returning Reference to Local Variable
    int& badFunction() {
        int x = 10;    // local variable on stack
        return x;      // ❌ Dangerous — x is destroyed after return
    }

⚠️ Problem:
x is destroyed when the function ends.
Using the reference causes undefined behavior (UB).

🛠️ How Reference Return Works Internally
    int& getRef(int& x) {
        return x;  // returns alias of x
    }

    int main() {
        int a = 20;
        int& r = getRef(a);
        r = 99;  // modifies a directly!
        cout << a << endl;  // prints 99
    }

Here, getRef() returns a reference to a. Modifying the reference r changes the original variable.

🔁 Real Use Case: Operator Overloading (for chaining)
    class Box {
        int val;
    public:
        Box(int v) : val(v) {}
        int& value() { return val; }  // return by reference
    };

    int main() {
        Box b(10);
        b.value() = 99;  // modifies internal member directly
        cout << b.value();  // prints 99
    }

✅ When to Use Return by Reference
Use Case	                    Why It's Useful
Avoid copy of large objects	    Improves performance
Allow direct modification	    Reference allows change at source
Chaining or direct access	    Used in operators, setters, etc.

⚠️ Best Practices & Pitfalls
Do...	                                                Avoid...
Return reference to variables with safe lifetimes       Returning reference to 
(e.g., static, globals, parameters)	                                local variables

Clearly document behavior	                            Confusing users about ownership

Consider const if readonly	                            Prevents unwanted modification

    const int& getConstRef(); // Read-only reference

*/
