/*
FAQ-Function overloading
🔷 1. 🔍 What is a Function Signature?
✅ Definition:
The function signature (or function prototype) is the part of a function declaration that tells the compiler:
 •The name of the function
 •The number, types, and order of its parameters

⚠️ The return type is NOT part of the signature in C++.

🧩 Example:
    int sum(int a, float b);  // function prototype (also a signature)

This tells the compiler:
•Function name = sum
•Parameters = 2
    •First = int
    •Second = float

Even if parameter names (a, b) are changed:
    int sum(int x, float y);  // same signature

➡️ Still considered exactly the same signature

🔷 2. 📌 What is a Function Prototype?
A function prototype is a declaration of a function that tells the compiler its signature before the actual definition.

🧩 Example:
    // Prototype
    int max(int a, int b);

    // Later definition
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

This is helpful when:
•Defining functions after main()
•Splitting code into header files and implementation

“Defining functions after main(),”
We mean: You can write the actual body (definition) of a function after the main() function, as long as you declare (or prototype) it before main().

✅ Example Without Prototype (❌ Will cause error):
    #include <iostream>
    using namespace std;

    int main() {
        greet();  // ❌ Error: ‘greet’ was not declared in this scope
    }

    void greet() {
        cout << "Hello, world!";
    }

The compiler processes code top to bottom, and it doesn’t know about greet() when it reaches main().

✅ Correct Way: Use a Function Prototype
    #include <iostream>
    using namespace std;

    // Function prototype (tells compiler the signature)
    void greet();

    int main() {
        greet();  // ✅ Now this works
    }

    // Function definition (actual logic)
    void greet() {
        cout << "Hello, world!";
    }

🧠 Why This Works:
•The prototype (also called function declaration) tells the compiler:
    •"A function named greet() exists with this signature — you’ll find it later."
•Then the compiler allows main() to use it.

🔁 Real-Life Analogy:
Imagine you're writing a book:
   •In Chapter 1, you mention "we'll explain how to fly drones in Chapter 5."
    •Readers won't get confused because you gave them a forward reference.
That’s exactly what a function prototype does — a promise to the compiler that the function will be defined later.



🔷 3. ⚡ Function Overloading — What is It?
✅ Definition:
Function overloading allows multiple functions to have the same name as long as their parameter list differs.
This is a form of compile-time polymorphism.

🚫 What doesn’t count in overloads?
•Return type
•Parameter names
•Default arguments alone

🔶 4. ❌ Is the Return Type Considered in Overloading?
🔥 No. Return type is NOT considered in overloading.
The compiler must be able to distinguish between functions based only on arguments.

❌ Invalid Overload:
    int sum(int a, int b);
    float sum(int x, int y);  // ❌ Error: same parameter types

Even though return types are different, the compiler sees:
    sum(int, int);
    sum(int, int);  // Redefinition error
➡️ Not overloadable

🔶 5. ✅ Valid Overloading Cases
Function 1	         Function 2	            Overloaded?	     Reason
void fun()	         void fun(int)	        ✅ Yes	        Different number
void fun(int)	     void fun(float)	    ✅ Yes	        Different type
void fun(int,float)	 void fun(float, int)	✅ Yes	        Different order and type
int fun(int)	     float fun(int)	        ❌ No	        Same signature, different
                                                            return type

🔶 6. 🧪 Deep Dive Example:
    #include <iostream>
    using namespace std;

    void show(int x) {
        cout << "Integer: " << x << endl;
    }

    void show(float y) {
        cout << "Float: " << y << endl;
    }

    void show(char ch, int times) {
        for (int i = 0; i < times; i++)
            cout << ch << ' ';
        cout << endl;
    }

Output:
show(5)       → Integer: 5
show(3.14f)   → Float: 3.14
show('*', 3)  → * * *
The compiler determines which function to call based on the arguments' types and number.

🔷 7. 🧠 Internal Compiler Behavior
C++ uses name mangling internally to implement function overloading.

👇 Example:
    int add(int, int);       // becomes _Z3addii
    float add(float, float); // becomes _Z3addff
➡️ These are completely different symbols in the compiled object file.
That’s why overloading based on parameters works, but return type alone won’t create different symbols — so it fails.

🔷 What is Name Mangling?
Name mangling is a process where the C++ compiler changes (mangles) the function names internally to encode additional information like:
•Function name
•Number of parameters
•Types of parameters
•Parameter order
•Namespace or class (if any)

✅ Why is it Needed?
In C, function names are unique — no overloading.
In C++, you can have multiple functions with the same name (function overloading).
👉 To tell them apart, the compiler "mangles" their names into unique internal identifiers.

🧪 Example:
    int add(int a, int b);
    float add(float x, float y);
These two functions have the same name add but different types.

But the compiler internally turns them into:
_Z3addii    // for int add(int, int)
_Z3addff    // for float add(float, float)

Each mangled name includes:
•_Z (indicates it's mangled)
•3add (length + name)
•i i (parameter types: i for int, f for float, etc.)

🔍 How is this useful?
•Allows function overloading
•Allows namespaces and classes to have functions with the same names
•Helps linkers identify the correct functions during compilation

❌ What if Return Type Was Considered?
Let’s say you write:
    int fun(int);
    float fun(int);  // ❌ Compiler Error!
Without name mangling, both functions would be:
    fun(int)
    fun(int)  // Conflict — compiler can't tell them apart!
Even with name mangling, return type isn't encoded (by design), so this still causes a conflict.

✅ Summary Table
Concept 	            Explanation
Name Mangling	        Process of encoding function signatures into unique names
Why Needed	            To support function overloading, namespaces, and classes
Return Type	            ❌ Not included in mangling (to avoid ambiguity)
Overloading Allowed	    ✅ Based on number, type, order of parameters
Mangled Example	        add(int, int) → _Z3addii

🛠 Tools to See Name Mangling:
If you use g++, try:
    g++ -S -o output.s file.cpp
or
    nm a.out
To view mangled names in your compiled binary.

🔷 8. ⚠️ Overloading & Default Parameters
Ambiguous Case:
    void fun(int x, int y = 10);
    void fun(int x); // ❌ Ambiguity on fun(5);
The call fun(5); could match either function — compiler throws an error.

🔁 Use default arguments cautiously when overloading.

🔷 9. ✨ Real-World Use Cases
Use Case	Example
abs()	Defined for int, float, double, etc.
pow()	Overloaded for int, float, double, int, etc.
std::cout <<	Overloaded for int, char, string, float, etc.
Constructors	Same class can have multiple constructors (constructor overloading)
*/
