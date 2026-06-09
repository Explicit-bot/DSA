/*
🔹 front() and back()

✅ Description:
front() returns a reference to the first character in the string.
back() returns a reference to the last character in the string.
Both allow modification of the character if the string is non-const.

🔧 Syntax:
    char& back();

    char& front();

✅ Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    cout << "First character: " << s.front() << endl;
    cout << "Last character: " << s.back() << endl;

    // Modifying
    s.front() = 'Y';
    s.back() = '!';
    cout << "Modified string: " << s << endl;

    return 0;
}
/*
⚠️ Edge Case: Empty String
    string empty = "";
    char ch = empty.front(); // ❌ undefined behavior
    
🧠 Unlike .at(), neither front() nor back() throws an exception for empty strings — using them on empty strings results in undefined behavior.

✅ Use Cases:
Function	Use
front()	    Access/modify first character (e.g., capitalize)
back()	    Access/modify last character 
            (e.g., punctuation, suffix check)

🧠 Internal Behavior:
Let’s say:
    string s = "World";

Memory layout (heap or internal buffer):
+---+---+---+---+---+---+
| W | o | r | l | d | \0|
+---+---+---+---+---+---+
^                       ^
|                       |
front()             back()

front() returns reference to 'W'
back() returns reference to 'd'

🧪 More Edge Cases:
1. Modifying first/last characters
    string s = "openai";
    s.front() = toupper(s.front()); // O
    s.back() = '?';                 // i → ?
    cout << s; // Opena?

2. Single-character string
    string s = "Z";
    cout << s.front() << s.back(); // ZZ
    s.front() = 'A';
    s.back() = 'B';  // Same char
    cout << s; // B

🔹 front() and back() — Const Version Summary
const char& front() const;
const char& back() const;

🔸 What They Do:
front() returns a read-only reference to the first character.
back() returns a read-only reference to the last character.
They are used when the string is const or passed as const string&.

✅ How to Use
✅ Syntax:
    const string s = "Hello";

    char first = s.front();  // Gets 'H'
    char last  = s.back();   // Gets 'o'

    cout << first << " " << last;

✅ Inside a Function:
    void printEnds(const string& str) {
        cout << "First: " << str.front() << ", Last: " << str.back() << endl;
    }
✅ Behavior:
Works only for non-empty strings.
You cannot modify the returned character (read-only).
No exceptions are thrown on empty strings — you must check:
    if (!str.empty()) {
        cout << str.front() << " " << str.back();
    }

⚠️ Key Points:
Aspect	            Explanation
Return Type	        const char& — cannot be modified
When to Use	        With const string or inside const functions
On Empty String	    ❌ Causes undefined behavior (no error thrown)
Common Use	        Reading first/last char in display or validation

🧠 Explanation:
These functions let you safely read the first and last characters of a string without copying them and without allowing changes. They ensure const-correctness when working with read-only strings.
*/
