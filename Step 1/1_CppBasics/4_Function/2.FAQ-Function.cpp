/*
FAQ-Functions
🔶 1. Do functions occupy memory in C++?
✅ Yes.
When a C++ program is compiled, each function’s code is converted into machine code. That machine code is stored in a specific part of memory known as the Code Segment (or Text Segment).

🧠 Deep Explanation:
•The Code Segment is read-only and stores instructions (i.e., compiled function bodies).
•Even if the function is never called during runtime, the compiler includes it in the binary if it's defined or linked.
•Functions do not live in the stack or heap, only their logic (machine code) is in the code section.

📌 Note:
•Function definitions take up memory.
•Function declarations (int func(int);) don’t — they just tell the compiler what to expect.

🔶 2. Will a function occupy space even if it is not called?
✅ Yes.
As long as the function is defined in the program (or included via linking), it is compiled and stored in the code section.

🧠 Deeper Insight:
•This is how the linker connects calls to the correct functions.
•Whether it's used or not at runtime, the compiled code must be present in memory so it can be called if needed.
•Some optimizing compilers may exclude unused functions during optimization (called dead code elimination) — but only if it's safe and enabled.

🔶 3. Where is the memory for variables of a function created?
📍 In the Stack Segment.
Every time a function is called:
•A new activation record (stack frame) is pushed to the call stack.
•This frame contains:
    •Function parameters
    •Local variables
    •Return address

🧠 Visual:
    void myFunction() {
        int a = 5;
        float b = 3.14;
    }

When myFunction() is called:
a and b are stored in the stack frame allocated for this call.

🔶 4. When is the memory for variables allocated?
🕒 At runtime, when the function is called.
✅ Runtime Behavior:
•As soon as a function starts executing, memory for all its local variables and parameters is allocated on the stack.
•When the function ends (i.e., return), the stack frame is popped, and the memory is released automatically.

🧠 Why It Matters:
•Local variables are not persistent.
•Each call to the function gets fresh memory.

🔶 5. Is memory for function variables allocated freshly for each call?
✅ Yes, every function call creates a new stack frame.
 📌 What this means:
 •You can call a function multiple times, and each call will have its own independent  set of variables.
 •This allows recursion, nested function calls, etc.

🧪 Example:
    void test() {
        int a = 0;
        ++a;
        cout << a << endl;
    }

Calling test() multiple times prints:
1
1
1
Because a is created fresh every time.

🔶 6. What is the return type of a function?
🧾 Return Type = The data type of the value that a function returns.
✅ Deeper View:
•When a function finishes, it may return a result to the caller.
•The return type tells the compiler what kind of value to expect.

📌 Examples:
    int add(int a, int b) { return a + b; }      // returns an int
    float getPi() { return 3.14; }              // returns a float
    string getName() { return "Naman"; }        // returns a string

🔶 7. What is void?
✅ void is a special return type that indicates no value is returned from a function.
🔍 When to use:
When the function performs an action (like printing, processing) but does not compute a result.

📌 Example:
    void printMessage() {
        cout << "Hello!" << endl;
    }

🧠 Remember:
•You cannot write return value; in a void function.
•But you can still use return; to exit early.

🔶 8. Difference between int main() and void main()
Feature	        int main()	                        void main()
Return type	    int (standard)	                    void (non-standard in C++)
Meaning	        Returns 0 to OS on success	        Returns nothing
Portability 	✅ Standard C++	                    ❌ Not standard-compliant
Required by	    Most compilers, the C++ standard	Often compiles but not recommended

✅ Explanation:
•In C++, main() is the entry point.
•int main() should return 0 to indicate successful execution to the Operating System.
•void main() is not valid in standard C++ (though some compilers allow it).

📌 Standard Form:
    int main() {
        // your code
        return 0;  // return success code to OS
    }

✔️ Always use int main() in C++ programs.
*/
