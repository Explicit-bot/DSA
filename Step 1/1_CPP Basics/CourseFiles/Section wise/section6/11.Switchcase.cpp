/*
🔷 What is a switch statement?
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
*/
#include <iostream>

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
    std::cout << "Enter the day number (1-7): ";
    std::cin >> input;

    switch (input) {          // directly use int
        using enum Day;       // ✅ works with plain enum
        case Monday:
            std::cout << "Monday\n";
            break;
        case Tuesday:
            std::cout << "Tuesday\n";
            break;
        case Wednesday:
            std::cout << "Wednesday\n";
            break;
        case Thursday:
            std::cout << "Thursday\n";
            break;
        case Friday:
            std::cout << "Friday\n";
            break;
        case Saturday:
            std::cout << "Saturday\n";
            break;
        case Sunday:
            std::cout << "Sunday\n";
            break;
        default:
            std::cout << "Invalid day number\n";
    }

    return 0;
}

/*
🔎 Key Points:
	•	✅ switch evaluates the expression once and jumps to the matching case.
	•	🔁 Use break; to exit the switch block after a match.
	•	🚨 Omitting break causes fall-through, meaning the next case will also execute (can be intentional).
	•	✅ default is optional — it’s executed if no case matches.

⚠️ Limitations:
	•	The expression must evaluate to an integral type:
	•	int, char, enum, bool, etc.
	•	❌ You cannot use float, double, or string directly in switch.
	•	case labels must be constant (known at compile-time).
	•	e.g., case 5: or case 'A':

🎯 When to Use:
	•	Multiple fixed options
	•	Cleaner alternative to if-else for menu systems, day/week cases, options, etc.

📌 Summary:
	•	switch is a control structure used to test a variable against multiple 
        constants.
	•	Avoids long if-else chains.
	•	Make sure to use break unless you want fall-through. 
        fall-through(means executing next case also).
	•	Works only with integral types — not strings or floating-point numbers.
*/
