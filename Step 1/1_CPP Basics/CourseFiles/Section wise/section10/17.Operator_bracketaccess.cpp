/*
🔹 operator[] — Bracket Access (str[index])

✅ Description:
Accesses the character at the specified index, just like an array.

🔧 Syntax:
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

✅ Key Characteristics:
Direct access to the character at a given index.
No bounds checking — accessing out-of-range indexes causes undefined behavior.
Faster than .at() because it skips safety checks.

✅ Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    cout << "Character at index 1: " << s[1] << endl;

    s[0] = 'Y';
    cout << "Modified string: " << s << endl;

    return 0;
}
/*
⚠️ Edge Case (No Exception Thrown):
    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        string s = "Hi";
        cout << s[100];  // ⚠️ No error, but undefined behavior!
        return 0;
    }

This may print garbage, crash, or do nothing depending on memory layout — completely unpredictable.

🧠 Internal Behavior:
Let’s say:
    string s = "World";

Internally:
s[0] gives reference to 'W'
s[4] gives reference to 'd'
s[5] → ❌ undefined behavior (could read garbage or crash)

✅ Modifying Characters:
    string s = "apple";
    s[0] = 'A';
    cout << s; // "Apple"

✅ Comparison: [] vs .at()
Feature	                    operator[]	     at()
Bounds checked	            ❌ No	        ✅ Yes
Throws exception	        ❌ No	        ✅ std::out_of_range
Performance	                ✅ Faster	    🔸 Slightly slower
Use for user input	        ❌ Risky	        ✅ Safer
Use for fixed-index logic	✅ Good choice	✅ Good choice with safety

🧪 Edge Cases:
1. Empty string
    string s = "";
    char ch = s[0]; // ❌ undefined behavior

2. Index at end of string
    string s = "abc";
    s[3]; // ❌ UB, valid indices are 0, 1, 2

🧠 Memory Diagram:
    string s = "Cat";

Heap or internal buffer:
+-------+-------+-------+--------+
|  'C'  |  'a'  |  't'  | '\0'   |
+-------+-------+-------+--------+
    ^      ^      ^
  s[0]   s[1]   s[2]

[] directly accesses these memory locations without checking whether they're valid.
*/
