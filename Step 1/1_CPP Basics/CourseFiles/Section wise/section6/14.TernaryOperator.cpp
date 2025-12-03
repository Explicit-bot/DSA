/*
📘 Ternary Operator in C++
🔷 1. 🔍 What is the Ternary Operator?
The ternary operator is a shorthand way of writing an if-else statement in a single line. It's called "ternary" because it takes three operands.

✅ General Syntax:
    condition ? expression_if_true : expression_if_false;

🔁 Equivalent to:
if (condition)
    result = expression_if_true;
else
    result = expression_if_false;

🔷 2. ✅ Simple Example
    int a = 10, b = 20;
    int max = (a > b) ? a : b;

    cout << "Max = " << max;

🟢 Output:
Max = 20

🔷 3. 💡 Where is it Useful?
Use Case	                                Example
Assigning a value based on a condition	    int res = (x > y) ? x : y;
Returning a value in a function	            return (age >= 18) ? "Adult" : "Minor";
Short conditional output	                cout << (flag ? "On" : "Off");

🔷 4. 🧠 How It Works
The ternary operator evaluates:
1.The condition.
2.If it's true, evaluates and returns the first expression.
3.If it's false, evaluates and returns the second expression.
❗ Only one of the two expressions is evaluated.

🔷 5. 🧪 Examples
🧩 With Integers
    int x = 15;
    int result = (x % 2 == 0) ? 0 : 1;
    Returns 1 since x is odd.

🧩 With Strings
    string mood = (temp > 30) ? "Hot" : "Cool";

🧩 With Functions
    (flag) ? doSomething() : doSomethingElse();

🔷 6. ⚠️ Nested Ternary Operators
✅ Allowed but can be confusing:
    int x = 10, y = 20, z = 15;
    int max = (x > y) ? (x > z ? x : z) : (y > z ? y : z);

🟢 Output:
max = 20

🚫 Bad Practice Example (Unclear):
cout << (a > b ? (a > c ? "A" : "C") : (b > c ? "B" : "C"));
❗ Use nested ternary only when necessary. Prefer if-else for clarity.

🔷 7. ⚠️ Pitfalls & Edge Cases
Mistake	                                    Fix
Missing condition before ?	                Always provide a valid boolean condition
Using statements instead of expressions	    Ternary returns values, not statements
Complex logic without parentheses	        Use brackets () to avoid precedence bugs

❌ Invalid:
    int x = ? a : b;  // ❌ No condition provided

🔷 8. 🧠 Performance & Use Cases
•Faster to write and read for simple decisions
•Used in initializations, return values, inline display
•Not suitable for multi-line or side-effect-heavy logic

🔷 Example
*/
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    string status = (age >= 18) ? "Adult" : "Minor";

    cout << "You are: " << status << endl;
    return 0;
}
/*
🔥 So, Which is Better?
✅ Use Ternary when:
•You're assigning a value based on a condition.
•Logic is simple (e.g., max of two).
•You want concise code.

✅ Use if-else when:
•You need to execute multiple statements.
•Logic is complex or nested.
•You're dealing with side effects (like cout, function calls, etc.).
•You care more about readability and maintainability.

⚠️ Example of What Not to Do:
    cout << ((x > y) ? ((x > z) ? "x" : "z") : ((y > z) ? "y" : "z"));  // 😵

Too complex to read. Prefer this:
    if (x > y && x > z)
        cout << "x";
    else if (y > z)
        cout << "y";
    else
        cout << "z";

*/
