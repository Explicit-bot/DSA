/*
📘 Function Overloading in C++
🔷 1. 🔍 What is Function Overloading?
Function overloading allows you to define multiple functions with the same name in the same scope, as long as their parameter list is different.

📌 Example:
    int add(int a, int b);        // adds two ints
    float add(float a, float b);  // adds two floats
Both functions have the same name add, but different parameter types.

🔷 2. ⚙️ Why Use Function Overloading?
Benefit	                        Explanation
Improves Readability	        Same concept, same function name
Avoids Naming Clutter	        No need for addInt, addFloat, etc.
Supports Polymorphism	        Part of Compile-Time Polymorphism
Cleaner API Design	            Makes libraries easier to use

🔷 3. ✅ Rules for Function Overloading
To overload a function, you must change one of the following in its signature:

Rule #	What must change?
1.Number of parameters
2.Type of parameters
3.Order of parameters (if types are different)
❌ Changing only return type is not allowed!

🧪 Valid Overloads:
void display();               // no parameter
void display(int a);          // different number
void display(double d);       // different type
void display(int a, double b); // different order/type

❌ Invalid Overload:
    int display();        // return type only changed
    float display();      // ❌ Error: same signature, only return type differs

🔷 4. 🔍 How Overloading Works (Internally)
C++ uses name mangling to differentiate between overloaded functions at compile time.
For example:
    int add(int, int);       // becomes something like _Z3addii
    float add(float, float); // becomes _Z3addff

Compiler generates unique "mangled" names internally based on parameters.
This is why you can't overload only by return type — it would produce the same mangled name.

🔷 5. ⚡ Examples of Function Overloading
🧩 Example 1: Varying Number of Parameters
    void greet() {
    cout << "Hello!" << endl;
    }

    void greet(string name) {
        cout << "Hello, " << name << "!" << endl;
    }

🧩 Example 2: Different Types
    int max(int a, int b) {
        return (a > b) ? a : b;   //ternary operator
    }

    double max(double a, double b) {
        return (a > b) ? a : b;
    }

🧩 Example 3: Different Order
    void show(int a, char b);
    void show(char b, int a);

Function overloading in C++ allows different orders only if the data types differ.

🔍 Why?
Because the order of parameters only matters when the types are different. If you simply reorder parameters of the same type, the compiler treats them as the same function signature, and you'll get a redefinition error.

✅ Valid Example (Different Order & Different Types):
    void display(int a, char b);  // valid
    void display(char b, int a);  // also valid — different order AND types

➡️ The compiler sees these as:
    display(int, char);
    display(char, int);
✅ Different parameter types and order = different signatures = ✅ valid overloading

❌ Invalid Example (Same Types, Different Order):
    void show(int a, int b);
    void show(int b, int a);  // ❌ Error: same signature

➡️ Both reduce to show(int, int)
⛔ Names don’t matter — only types and order of types.

🔷 6. 🧠 Function Overloading with Default Arguments
⚠️ Be careful! Default arguments may confuse the compiler if overloads are ambiguous.
🚫 Ambiguous:
    void show(int a, int b = 5);
    void show(int a); // Ambiguous call: show(10);

The call show(10) could match both.

🔷 7. 🔬 Function Overloading vs Function Overriding
Feature	        Overloading	            Overriding
Scope	        Same class or file	    Base → Derived class
Time	        Compile Time	        Run Time
Keyword	        None	                Uses virtual
Polymorphism	Compile-Time	        Run-Time

🔷 8. 📚 Real-World Use Cases
•std::abs() in <cmath> is overloaded for int, float, long, etc.
•std::cout << is overloaded for many types (int, string, float...).
•Libraries use overloading to create intuitive APIs.

🔷 9. 🧪 Full Code Example
    #include <iostream>
    using namespace std;

    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    string add(string a, string b) {
        return a + b;
    }

    int main() {
        cout << add(2, 3) << endl;          // int
        cout << add(2.5f, 3.1f) << endl;    // float
        cout << add("Hello, ", "World!") << endl; // string
    }

🔷 10. ✅ Best Practices
Tip	                                              Why
Avoid too many overloads	                      Can make debugging hard
Use meaningful parameters	                      Avoid confusion during call resolution
Don’t rely on return type for differentiation	  It’s not valid
Be cautious with default parameters	              May cause ambiguities

✅ Summary:
Parameter Type & Order	            Overloading Allowed?	     Why
Different types	                    ✅ Yes	                    Signature changes
Same types, different order	        ❌ No	                    Same signature
Different number of parameters	    ✅ Yes	                    Signature changes
Same signature,different            ❌ No	                    Return type alone 
return type                                                      doesn't count

Program for function overloading sum of two integers
*/
# include<iostream>
using namespace std;
    

int sum(int a,int b){
	return a+b;
}

float sum(float a,float b){
	return a+b;
}

int sum(int a,int b,int c){
	return a,b,c;
}

int main(){
	cout<<sum(10,5)<<endl;
	cout<<(12.5f,3.4f)<<endl;
	cout<<sum(10,20,3)<<endl;
	return 0;
}

