/*
What is the Ternary Operator?
The ternary operator is a shorthand way of writing an if-else statement in a single line. It's called "ternary" because it takes three operands.

✅ General Syntax:
    condition ? expression_if_true : expression_if_false;

🔁 Equivalent to:
if (condition)
    result = expression_if_true;
else
    result = expression_if_false;
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
⚠️ Example of What Not to Do:
    cout << ((x > y) ? ((x > z) ? "x" : "z") : ((y > z) ? "y" : "z"));  

Too complex to read. Prefer this:
    if (x > y && x > z)
        cout << "x";
    else if (y > z)
        cout << "y";
    else
        cout << "z";

*/
