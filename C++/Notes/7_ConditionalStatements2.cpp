/*
                ====================================================
                                    SHORT-CIRCUIT
                ====================================================
Short-circuit evaluation refers to the way logical operators (&& and ||) evaluate expressions. It allows the program to stop evaluating further conditions as soon as the result is already determined.

How Short-Circuiting Works:
• && (Logical AND) Operator:
	-Short-circuits (stops evaluating) when the left-hand operand is false.
	-Since false && anything is always false, the second operand doesn’t need to be checked.
Example:
    if (false && (5 / 0 == 0)) 
    The expression false && (5 / 0 == 0) is already false, so the program won’t attempt to evaluate (5 / 0 == 0), avoiding a division by zero error.

• || (Logical OR) Operator:
	•	Short-circuits (stops evaluating) when the left-hand operand is true.
	•	Since true || anything is always true, the second operand doesn’t need to be checked.
Example:
    if (true || (5 / 0 == 0)) {
   The expression true || (5 / 0 == 0) is already true, so the program doesn’t evaluate (5 / 0 == 0) and avoids the error.

                ====================================================
                                Ternary Operator
                ====================================================
The ternary operator is a shorthand way of writing an if-else statement in a single line.
It's called "ternary" because it takes three operands.
✅ General Syntax:
    condition ? expression_if_true : expression_if_false;
e.g
string status = (age >= 18) ? "Adult" : "Minor";

🔁 Equivalent to:
if (age>=18)
    status="Adult";
else
    status="Minor";

                ====================================================
                                switch statement
                ====================================================
The switch statement selects one of many code blocks to execute, based on the value of a single expression (usually an int, char, or enum).

✅ Syntax:
switch (expression) {
    case constant1:
        // Code block 1
        break;

    case constant2:
        // Code block 2
        break;

    // ...

    default:
        // Code block if no cases match
}

🔎 Key Points:
	• switch evaluates the expression once and jumps to the matching case.
	•Use break; to exit the switch block after a match.
	•Omitting break causes fall-through, meaning the next case will also execute (can be intentional).
	•default is optional — it’s executed if no case matches.

⚠️ Limitations:
	•The expression must evaluate to an integral type:
    int, char, enum, bool, etc.
	•You cannot use float, double, or string directly in switch.
	•case labels must be constant (known at compile-time).
    e.g., case 5: or case 'A':
*/
#include <iostream>
using namespace std;

enum Day {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    int input;
    cout << "Enter the day number (1-7): ";
    cin >> input;

    switch (input) {   // switching on int is fine
        case Day::Monday:
            cout << "Monday\n";
            break;
        case Day::Tuesday:
            cout << "Tuesday\n";
            break;
        case Day::Wednesday:
            cout << "Wednesday\n";
            break;
        case Day::Thursday:
            cout << "Thursday\n";
            break;
        case Day::Friday:
            cout << "Friday\n";
            break;
        case Day::Saturday:
            cout << "Saturday\n";
            break;
        case Day::Sunday:
            cout << "Sunday\n";
            break;
        default:
            cout << "Invalid day number\n";
    }

    return 0;
}

