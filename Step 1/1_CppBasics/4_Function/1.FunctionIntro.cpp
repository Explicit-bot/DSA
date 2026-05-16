/*
🔶 1. 🔍 What is a Function? 
📖 Definition:
A function in C++ is a named group of statements that performs a specific task and optionally returns a result. It is invoked (called) when that task needs to be performed.

✅ Deep Explanation:
1. Encapsulation of Logic:
A function wraps a piece of logic (computation, printing, calculation, etc.) so it can be reused.
Example:
    int square(int x) {
        return x * x;
    }
The above encapsulates "squaring" logic. You don’t have to write x * x every time.

2. Abstraction Layer:
Functions hide implementation. The user only needs to know what the function does, not how.
Example:
    int area = calculateCircleArea(5);

You don’t need to know π or r² formula — the function hides it.
The user doesn't need to understand the internal mechanism — just use it. That’s abstraction.

3. Modular Design:
Functions divide complex programs into smaller, testable, and maintainable units.
    void takeInput();
    void calculateSalary();
    void displayReport();

🔶 2. 📜 Syntax + Declaration + Definition + Calling
📌 Basic Syntax:
    return_type function_name(parameter_list);

🔍 Breakdown:
Part	                Meaning
return_type	            Type of value returned (int, float, void, char, etc.)
function_name	        Name used to invoke the function
parameter_list	        Input values passed when calling the function (optional)

📘 Full Example:
    int sum(int a, int b);         // declaration

    int main() {
        int x = 10, y = 20;
        int result = sum(x, y);    // calling
        cout << result;
    }
    
    int sum(int a, int b) {        // definition
        return a + b;
    }

🔶 3. 🧠 Function Working in Memory 
When a function is called, memory is used in a specific and layered structure: Code Segment, Stack, and Heap.

🧭 Memory Segments:
Segment	Role
Code Segment	Stores actual compiled code (e.g., main, add)
Stack Segment	Temporarily holds variables, function calls (auto-cleared)
Heap Segment	Dynamically allocated memory (you manage it manually)

🔄 Execution Flow Example:
    int add(int x, int y) {
        int z = x + y;
        return z;
    }

    int main() {
        int a = 10, b = 15, c;
        c = add(a, b);
    }
🧩 Step-by-Step Internal Behavior:
1.Program begins in main().
    - Stack allocates memory for a, b, c.
2.Function add() is called:
    -A new stack frame is pushed.
    -x gets 10, y gets 15.
    -z = x + y = 25.
3.Return value is passed:
    -z is returned to c in main().
4.Function Ends:
    -Stack frame for add() is popped (deleted) automatically.

📌 Key Point:
Variables inside functions live in the stack and are deleted after function exits.
This is why local variables don’t persist between function calls.

🔶 4. ⚠️ Heap vs Stack in Functions
📂 Stack Characteristics:
•Temporary
•Fast allocation/deallocation
•Stores:
    -Local variables
    -Function parameters
    -Return addresses
•Auto-managed

📦 Heap Characteristics:
•Manually controlled
•Slower
•Used when you need memory to persist after function exits
•Needs new and delete

🚨 Example of Heap Use (with danger):
Return by address:
    int* allocate() {
        int* p = new int(42);  // memory from heap 
        //new int(42) is Direct Initialization
        return p;              // persists after function
    }

    int main() {
        int* ptr = allocate(); // now ptr holds 42
        delete ptr;            // manual cleanup required
    }
❌ If you forget delete, you create a memory leak.

🔶 5. 📈 Return Types and void 
🧾 Return Types:
•int: returns integer
•float, char, etc.
•void: returns nothing

🧪 Example:
    int getAge() {
        return 21;
    }

    void sayHello() {
        cout << "Hello!";
    }

🔍 Internal View:
When a return statement is hit, the value is sent to the caller.
The stack frame is cleared afterward.

📌 Return Type Importance:
•In older C++, if you don’t specify a return type, compiler assumes int (bad practice).

•Modern C++ (C++11 and beyond): Always specify return type for:
    •Type safety
    •Clarity
    •Avoiding warnings

🔁 Common Mistake:
• getAge(); // No return used
This will compile but wastes the return value. Always use returned value unless the function is void.

• Implicit Conversion in Function Arguments in C++
🚩 What’s the confusion?
You may have read:
“Function arguments are strict in C++”
“No implicit conversion occurs in function calls”
But in reality:
C++ allows standard implicit conversions for function arguments — within well-defined rules.
Let's break this down thoroughly. 👇

🔹 1. What is Implicit Conversion?
Implicit conversion is when the compiler automatically converts one data type into another without asking you.
For example:
    char ch = 'a';
    int x = ch;  // ✅ implicit: char → int
The character 'a' becomes ASCII 97.

🔹 2. Do implicit conversions happen in function calls?
✅ Yes. When you call a function, C++ will convert arguments to match the parameter types — *if a valid standard conversion exists.

✅ Example:
    void show(int x);

show('a'); // 'a' is char → promoted to int ✅
No error. 'a' is implicitly converted to int (97).

🔹 3. What kind of conversions are allowed?
These are called Standard Conversions, and they include:
From	        To	            Notes
char	        int	            ✅ promotes to int
short	        int	            ✅ promotes to int
float	        double	        ✅ widening conversion
int	            float	        ✅ allowed (may lose precision)
const char*	    void*	        ✅ safe pointer conversion
🧠 These do happen automatically.

🔹 4. When implicit conversion fails?
Conversion will NOT happen automatically if:
❌ It's not a standard conversion
e.g., int to std::string:
    void greet(std::string name);
    greet(10);  // ❌ Error: int → string not allowed implicitly

❌ There is ambiguity due to overloads
    void fun(int);
    void fun(float);

fun(97); // ✅ Calls `fun(int)`
fun('a'); // ✅ 'a' → int → `fun(int)` (best match)
fun(3.14); // ✅ Calls `fun(float)`, but if both were equal, compiler error

    ✅ Function Overloading Resolution in C++
    C++ chooses the best match among overloaded functions using these 
    rules (simplified):
    First choice: exact match
    Then: promotions (e.g., char → int)
    Then: user-defined conversions
    Then: compiler error if ambiguous

    🔷 Case  fun(3.14);
    3.14 is a double literal by default in C++.
    But you only have overloads for int and float.

    ❓ What will C++ do?
    It has two options:
    Convert 3.14 (double) → float
    Convert 3.14 (double) → int
    ❗ Both are standard conversions, but neither is better than the other.
    🎯 Result: ❌ Ambiguity — compiler error

    ❗ Final Answer:
        fun(3.14);  // ❌ Ambiguous — compiler error!

    Because:
    •float fun(float) requires narrowing conversion (double → float)
    •int fun(int) also requires narrowing (double → int)
    •No better match exists → ❌ ambiguity

    ✅ Fix:
    You must help the compiler by casting:
        fun((float)3.14);  // ✅ float called
        fun((int)3.14);    // ✅ int called

🔹 5. Example — Your case
    void getage(int x, int y);
    getage(34, 'a');  // 'a' is char

🔍 Internally:
'a' → ASCII 97
Becomes: getage(34, 97);
✅ This works perfectly because 'a' → int is a standard promotion.

🔹 6. ✅ Implicit Conversion in Overloading
Let’s make it more interesting:
    void print(int);
    void print(char);

print('a');

❓ What happens?
C++ chooses best match.
'a' is exactly a char → chooses print(char) ✅
If print(char) is missing → uses print(int) via implicit conversion

So:
First choice: exact match
Then: promotions (e.g., char → int)
Then: user-defined conversions
Then: compiler error if ambiguous

🔹 7. ❗ Common Misunderstanding: “Functions are strict”
People often say:
"Function arguments are strict. They don’t allow conversions."
But this is half-true.

❌ Wrong: No conversions ever
✅ Right: Only standard conversions are automatic
You won’t get:
int → std::string
string → char*
These need explicit conversion or overloads.


Basic examples of functions:
1.ADD TWO FLOATS
#include<iostream>
using namespace std;

float add(float x, float y){
    float z;
    z=x+y;
    return z;
}

int main(){
    float x{};
    float y{};

    cout<<"Enter two Floats:"<<flush;
    cin>>x>>y;

    cout<<"Sum of "<<x<<" and "<<y<<" is "<<add(x,y)<<"\n";
    return 0;
}

2.MAX OF 3 NUMBERS
*/
#include <iostream>
using namespace std;

float Max(float a, float b, float c) {
    if (a == b && b == c) {
        cout << "All values are equal.\n";
        return a;
    }
    else if (a == b && a > c) {
        cout << "Two are equal and largest.\n";
        return a;
    }
    else if (a == c && a > b) {
        cout << "Two are equal and largest.\n";
        return a;
    }
    else if (b == c && b > a) {
        cout << "Two are equal and largest.\n";
        return b;
    }
    else if (a > b && a > c) {
        cout <<a<<" is the largest.\n";
        return a;
    }
    else if (b > a && b > c) {
        cout <<b<< " is the largest.\n";
        return b;
    }
    else {
        cout <<c<<" is the largest.\n";
        return c;
    }
}

int main() {
    float x{}, y{}, z{}, maxVal{};

    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    maxVal = Max(x, y, z);
    cout << "Maximum value is: " << maxVal << endl;

    return 0;
}

