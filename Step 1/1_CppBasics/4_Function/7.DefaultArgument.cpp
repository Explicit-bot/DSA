/*
📘 Default Arguments in C++
🔷 1. 🔍 What are Default Arguments?
In C++, default arguments allow you to assign default values to function parameters so that the caller can omit them when calling the function.

✅ Definition:
A default argument is a value assigned to a function parameter in the function declaration or definition. If the caller doesn’t pass that argument, the compiler substitutes it automatically.

🔷 2. 🧠 Why Use Default Arguments?
Reason	                        Benefit
Simplify function calls	        Reduce number of arguments passed
Avoid overloading	            One function handles multiple cases
Increase flexibility	        Makes APIs optional and cleaner
Improve readability	            Clear intention without extra overloads

🔷 3. 🛠 Syntax
    return_type function_name(type param1 = default1, type param2 = default2, ...);
    Default values must be compile-time constants or known at compile time.

🧩 Example:
    void greet(string name = "Guest", string emoji = "🙂") {
        cout << "Hello, " << name << " " << emoji << endl;
    }

🔷 4. 🔄 Function Call Behavior
Call Scenarios:
    greet();                      // "Hello, Guest 🙂"
    greet("Naman");               // "Hello, Naman 🙂"
    greet("Naman", "🔥");         // "Hello, Naman 🔥"
➡️ The compiler fills in the missing arguments from right to left.

🔷 5. ✅ Rule 1: Defaults Must Be Right to Left
Once you provide a default value, all parameters to the right must also have default values.
    void fun(int a, int b = 10, int c = 20);  // ✅ Valid
    void fun(int a = 10, int b, int c);       // ❌ Invalid — 'b' has no default

Why?
The compiler wouldn’t know what value to assign to which parameter if middle arguments were skipped.

🔷 6. ✅ Rule 2: Default Value Can Be Defined Once
You can specify default arguments in either:
The function declaration
The function definition

❌ Not Both!
✅ Valid:
// In header or before main()
    void show(string msg = "Hello");

// In implementation file
    void show(string msg) {
        cout << msg;
    }

❌ Invalid:
    void show(string msg = "Hi");
    void show(string msg = "Bye");  // ❌ Error: redefinition of default value

🔷 7. 🧠 Compiler Behavior (Behind the Scenes)
When you write:
    void test(int a = 5);
and later call:
    test();  // becomes test(5);

The compiler automatically substitutes the default value during compilation.
The actual function must be defined to take that parameter — default is not stored at runtime.

🔷 8. ⚠️ Default Arguments vs Overloading
Both can be used to simulate optional behavior.
// With default argument
    void show(string msg = "Hello");

// With overloading
    void show() { show("Hello"); }
    void show(string msg) { cout << msg; }

🔥 Problem: Ambiguity
    void show(int a, int b = 10);
    void show(int a);  // ❌ Error: show(5); is ambiguous

Why?
show(5) can match both functions
show(5) → show(int) ✅
show(5) → show(int, int) with default b = 10 ✅
Result: Compiler error (ambiguous call)

🔷 9. 🚀 Default Arguments in Classes
Default arguments work in:
Constructors
Member functions
    class Player {
    public:
        void display(string name = "Unknown", int level = 1) {
            cout << name << " is at level " << level;
        }
    };

Player p;
p.display();             // Unknown is at level 1
p.display("Naman");      // Naman is at level 1

🔷 10. 🧪 Detailed Walkthrough Example
void report(string name = "User", string status = "Active", int age = 0);

report();                            // name=User, status=Active, age=0
report("Naman");                     // name=Naman, status=Active, age=0
report("Naman", "Pending");          // name=Naman, status=Pending, age=0
report("Naman", "Pending", 21);      // name=Naman, status=Pending, age=21
🧠 The compiler fills missing values from right to left.

🔷 11. 🎯 Advanced Use Cases
✅ Default in Templates
    template <typename T = int>
    void show(T val = 0) {
        cout << val;
    }

✅ Default in Constructors
    class Box {
    public:
        Box(int h = 1, int w = 1) {
            // ...
        }
    };

🔷 12. ❗ Pitfalls to Avoid
Pitfall	                                                Explanation
Providing defaults in both declaration & definition	    ❌ Not allowed
Placing default in middle	                            ❌ Compiler confusion
Using overloading + default	                            Can cause ambiguity
Default values as runtime variables	                    ❌ Must be known at compile time

Program for function overloading sum of two integers:
*/
# include<iostream>
using namespace std;
    
int max(int a=0,int b=0, int c=0){
	return a>b && a>c ? a:b>c? b:c;
}
int main()
{
	cout<<max()<<endl;
	cout<<max(10)<<endl;
	cout<<max(10,13)<<endl;
	cout<<max(10,13,15)<<endl;
	return 0;
}
