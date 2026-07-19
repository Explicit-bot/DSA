/*
🔹 What is a static Variable?
A static variable is a special type of variable in C++ whose lifetime extends across the entire program. It retains its value between function calls and exists only once, regardless of how many times the function or block is executed.

🔹 Types of static Usage
1. Static Local Variables (Inside a Function)
•Retains value between multiple function calls.
•Initialized only once.
•Scope is local to the function, but lifetime is the entire program.

    #include <iostream>
    using namespace std;

    void counter() {
        static int count = 0; // Initialized only once
        count++;
        cout << "Count: " << count << endl;
    }

    int main() {
        counter(); // Count: 1
        counter(); // Count: 2
        counter(); // Count: 3
        return 0;
    }
📌 Without static, the variable would reset to 0 every time the function is called.

2. Static Global Variables
•Declared outside all functions, but with static keyword.
•Scope is limited to the file, not accessible from other files (translation units).
•Used for internal linkage (opposite of extern).
    static int globalValue = 100; // Only accessible within this file

3. Static Member Variables (Inside a Class)
•Shared across all instances of the class (i.e., class-level variable, not object-level).
•Need to be defined outside the class as well.
•Can be accessed using class name (ClassName::variable).

    #include <iostream>
    using namespace std;

    class Student {
    public:
        static int count;  // Declaration
        Student() {
            count++;
        }
    };

    int Student::count = 0;  // Definition outside class

    int main() {
        Student s1, s2, s3;
        cout << "Total students: " << Student::count << endl; // Output: 3
        return 0;
    }

🔹 Memory Behavior
Type	        Scope	    Lifetime	            Storage location
Static Local	Function	Entire program	        Static memory
Static Global	File	    Entire program	        Static memory
Static Class	Class	    Entire program	        Static memory

🔹 Initialization Rules
•Static variables must be initialized only once.
•If not explicitly initialized, they are automatically initialized to zero.
•Initialization is done only once during program startup or first function call (for function-level static).

🔹 Static Inside Loop (⚠️ Still Only One Copy)
    for (int i = 0; i < 5; ++i) {
        static int x = 10;
        x++;
        cout << x << " ";
    }

⏳ Output: 11 12 13 14 15
Even though the loop runs 5 times, only one copy of x exists.

🧠 Why Is This Not Like a Normal Variable?
If You Wrote:
    for (int i = 0; i < 5; ++i) {
        int x = 10;
        x++;
        cout << x << " ";
    }
Then x is a non-static local variable that:
•Is re-created and re-initialized to 10 on every iteration.
•Output would be:
11 11 11 11 11

🔹 Static & Recursion
    void recur(int x) {
        static int depth = 0;
        depth++;
        cout << "x: " << x << ", depth: " << depth << endl;
        if (x > 0) recur(x - 1);
    }
📌 The static variable depth accumulates across recursive calls (not reset each time).

🔹 Static vs Global vs Local
Feature	        Local Var	    Global Var	            Static Var (Local)
Scope	        Function only	Entire program	        Function only
Lifetime	    Per call	    Entire program	        Entire program
Initialization	Each call	    Once	                Once
Accessibility	Function only	Anywhere (or file)	    Function only

🔹 Use Cases of Static Variables
•Counting function calls.
•Caching data between calls.
•Limiting scope of global variables (file-level static).
•Creating shared state among class objects (static members).
•Singleton design pattern.
•Lazy initialization (initialized on first use).

🔹 Important Edge Cases
⚠️ 1. Static Variable in Recursive Function
•Not reset between recursive calls.
•Can lead to logical bugs if not handled properly.

⚠️ 2. Thread Safety
•Static local variables in multithreaded programs can cause race conditions unless you use proper synchronization.

⚠️ 3. Initialization Order
•Static initialization order across multiple translation units is undefined — known as the Static Initialization Order Fiasco.

🔹 Static Inside a Class with Private Access
    class Config {
    private:
        static int secret;
    public:
        static int getSecret() {
            return secret;
        }
    };
    int Config::secret = 42;
📌 Even if the variable is private, it can still be used internally in static functions.

🔹 What is int Config::secret = 42;?
This is the definition and initialization of the static member variable secret outside the class.

Why outside?
•Static members are shared by all objects of the class.
•They exist independently of any object.
•Unlike normal members, they must be defined once outside the class.

So:
    int Config::secret = 42;

means:
•Allocate space for secret
•Set its initial value to 42
•Scope it under Config using the scope resolution operator ::

🔹 Why Can a Private Static Variable Be Accessed by a Static Function?
Let's break it down:
Feature	                                 Behavior
secret is private	                    Only accessible inside the class
getSecret() is static	                Doesn't need an object to call it
But getSecret() is part of the class    So it can access private members
So getSecret() can use secret	        ✅ Yes, even though it’s private

✅ This is legal and safe:
    cout << Config::getSecret();  // prints 42

🔹 Static Functions (Bonus)
Though not variables, static functions also exist:
✅ Inside Class:
Cannot access non-static members.
Belong to the class, not any object.
✅ Outside Class:
Restricts scope to file (like static global variable).

🔹 Static Member Functions Can Only Access Static Members
Static functions:
•Can’t access non-static (regular) members, because:
•They don’t have this pointer
•They don’t run on any specific object

But:
•They CAN access static members, because:
•Static members belong to the class, not any object
•Static functions also belong to the class, not to any object

✅ So this works:
    static int getSecret() {
        return secret; // ✅ allowed
    }

⛔ But this would cause error:
    int id; // non-static
    static int getId() {
        return id; // ❌ Error: cannot access non-static member
    }

Full Context: for line 186
    class Config {
    private:
        static int secret;            // 🔹 ← Declaration of `secret`
    public:
        static int getSecret() {     // 🔸 static member function
            return secret;           // ✅ accessing the static variable
        }
    };

✅ Answer:
🔹 secret is declared in the line:
    static int secret;  // inside the class, in private section

This declares a static data member of the class Config.
But C++ requires static members to be defined separately outside the class (only for non-const and non-inline statics). So you must also define and initialize it like this outside:
    int Config::secret = 42;  // 🔧 Definition & Initialization (not declaration)

Breakdown:
Code Line	                Role
static int secret;	        ✅ Declaration (inside class)
int Config::secret = 42;	✅ Definition (outside class)
return secret;	            ✅ Usage (inside static function)

Why static function can access it?
Because:
•secret is declared inside the class, even though it's private
•getSecret() is also inside the class, so it has full access to private members — even static ones

⚠️ If you OMIT the declaration:
    class Config {
    public:
        static int getSecret() {
            return secret;  // ❌ ERROR: ‘secret’ was not declared
        }
    };

This gives a compile-time error, because secret is not declared anywhere.

*/
