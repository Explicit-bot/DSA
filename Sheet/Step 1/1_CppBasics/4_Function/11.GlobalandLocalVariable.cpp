/*
🧠 Global and Local Variables in C++ — The Complete Guide
✅ What is a Local Variable?
A local variable is:
•Declared inside a function or block ({ }).
•Accessible only within that function or block.
•Created when the function is called, and destroyed when the function ends.
•Stored in the stack memory.

🧪 Syntax
    void myFunction() {
        int localVar = 10;  // local variable
        cout << localVar;
    }

    int main() {
        // cout << localVar; ❌ Error: not in scope here
    }

✅ What is a Global Variable?
A global variable is:
•Declared outside of all functions, usually at the top of the program.
•Accessible from any function in the same file (or external files if declared with extern).
•Created at program start, destroyed at program end.
•Stored in the data segment (not stack/heap).

🧪 Syntax
    int globalVar = 100;  // Global variable

    void func() {
        cout << globalVar;  // ✅ Accessible here
    }

    int main() {
        globalVar += 10;
        cout << globalVar;  // ✅ Accessible here too
    }

🧠 📦 Memory and Lifetime Comparison
Feature	            Local Variable	                                Global Variable
Scope	            Inside block/function only	                    Entire program

Lifetime	        Created on function call, destroyed on return	Created at program
                                                                    start, ends at termination  
                                            
Memory Location	    Stack	                                        Data segment 
                                                                    (static memory)

Accessibility	    Limited	                                        Everywhere in file 
                                                                    (or more)

Initialization	    Not auto-initialized                            Auto-initialized 
                    (contains garbage if not se                     to 0

🧪 Example: Local and Global Coexist
    int x = 50;  // global

    void show() {
        int x = 10;  // local shadows global
        cout << "Inside function: " << x << endl;
    }

    int main() {
        show();             // Output: 10
        cout << x << endl;  // Output: 50 (global)
    }
        
*****************************    
🔎 Shadowing:
When a local variable has the same name as a global, the local one hides the global inside its scope.

✅ To access global explicitly: use :: scope resolution operator.

    void test() {
        int x = 5;
        cout << ::x; // Access global x
    }
***********************
🧼 Global Const Example                     
    const double PI = 3.14159;

    double area(double r) {
        return PI * r * r;
    }
✅ PI is global and shared, but const makes it safe and immutable.

⚠️ Edge Cases and Mistakes
❌ 1. Uninitialized Local Variables
void f() {
        int x;
        cout << x; // ❌ Garbage value (undefined behavior)
    }

✅ Global is auto-initialized
    int y;
    void f() {
        cout << y; // ✅ Will print 0
    }

❌ 2. Global Variable Modification From Anywhere
    int count = 0;

    void increment() { count++; }
    void decrement() { count--; }

    int main() {
        increment();
        decrement();
        cout << count; // ❌ Hard to track and debug
    }
✅ Better: Pass count as a reference, or encapsulate in a class.

❌ 3. Name Conflict in Large Projects
If many global variables exist:
    // file1.cpp
    int data;

    // file2.cpp
    int data; // ❌ Redefinition error or accidental overwrite
✅ Use namespaces or classes to prevent this.

📦 Visual Diagram
    int globalVar = 100;  // Global → [Data Segment]

    int main() {
        int localVar = 5;  // Local  → [Stack]
    }
*/
