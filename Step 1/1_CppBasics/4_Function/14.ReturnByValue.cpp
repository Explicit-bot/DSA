/*
🔁 What is Return by Value?
Return by value means the function returns a copy of a value, not the original.
    int getNumber() {
        int x = 42;
        return x;  // returns a copy of x
    }

•The value stored in x is copied to the caller.
•The original x is destroyed after the function ends.

🧱 Syntax
    ReturnType functionName() {
        ReturnType variable;
        return variable;  // returns a copy
    }

The function returns an object of type ReturnType by value, meaning a new object is created in the caller.

✅ Example: Basic Return by Value
    int getSquare(int n) {
        int square = n * n;
        return square;  // returns copy of result
    }

    int main() {
        int result = getSquare(5);
        cout << result << endl;  // prints 25
    }

🧠 Key Characteristics
Property	              Description
Returns a copy	          The original variable in function is not returned
Safe	                  No danger of dangling pointers or references
Cannot modify original	  Caller only sees a copy, not the source
May be inefficient	      For large objects (unless compiler optimizes)

🔬 Memory Behavior
Imagine:
    int getVal() {
        int x = 10;
        return x;
    }

Memory Diagram:
Function Stack:
+----+           After return, x is destroyed
| x=10|
+----+

Main Stack:
+------+
| 10   |  <- copy of x returned
+------+

⚠️ Edge Case: What if value is a large object?
    std::string getString() {
        std::string s = "This is a very large string...";
        return s;  // returns a COPY (but compiler may optimize)
    }

Returning by value creates a copy, which may be slow for large objects. But:
•✅ Modern C++ compilers apply RVO (Return Value Optimization).
•✅ Copy Elision and Move Semantics often eliminate performance concerns.

✅ Use Cases
When to Use Return by Value	                    Why?
Simple data types (int, float, etc.)	        Safe, fast
Returning computed values	                    You don’t need to modify them
You want immutability	                        Caller can’t change the original
Temporary or throwaway results	                No need to manage memory

❌ Not Suitable When:
•You want the caller to modify the actual data (use reference or pointer).
•You need to avoid copies for performance reasons (consider move semantics or references).

🧪 Example: Return by Value vs Reference
    int getVal() {
        int x = 5;
        return x;  // copy returned
    }

    int& getRef() {
        static int x = 5;
        return x;  // reference returned
    }

    int main() {
        int a = getVal();   // a = 5, but original x is gone
        getRef() = 100;     // modifies static x to 100
        cout << getRef();   // prints 100
    }

✨ Summary Table: Return Types
Feature	            By Value (int)	        By Address (int*)	    By Reference (int&)
Returns	            Copy of data	        Pointer to data	        Alias to data
Ownership	        New copy	            Shared (must manage)	Shared
Modifiable?	        ❌ No	               ✅ Yes	               ✅ Yes
Lifetime safety	    ✅ Safe	               ⚠️ Must manage	        ⚠️ Must manage
Use for simple? 	✅ Yes	               ❌ Not needed	           ❌ Risky
Example	            return x;	            return new int(x);	    return x; (if x&)
*/
