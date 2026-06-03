/*
🔹 empty()
✅ Description:
Checks whether the string is empty (i.e., has length 0).
Returns a bool:
true → string has no characters.
false → string contains at least one character.

🔧 Syntax:
    str.empty()

✅ Use Case:
Quickly check if a string is blank before performing operations like access, printing, or parsing.

✅ Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "";
    string s2 = "Hello";

    if (s1.empty()){
        cout << "s1 is empty\n";
    }
    else{ 
    cout << "s1 is not empty\n";
    }

    if (s2.empty()){
    cout << "s2 is empty\n";
    }
    else {
    cout << "s2 is not empty\n";
    }
    
    return 0;
}
/*
⚠️ Edge Cases:
1. Whitespace is NOT empty
    string s = "   ";
    cout << s.empty(); // false, even though it looks blank!

2. Cleared string
    string s = "Hi";
    s.clear();
    cout << s.empty(); // true

3. String after assignment
    string s = "abc";
    s = "";
    cout << s.empty(); // true

✅ If I assign string s = "", how is it stored in memory?
When you write:
    std::string s = "";

Internally:
s.size() returns 0
s.empty() returns true
But a null terminator ('\0') is still stored in memory for C-string compatibility.
Internally, most implementations allocate a small static buffer even for empty strings, but size == 0 (Size not capacity)

🧠 Memory Layout (Simplified):
Stack:
+---------+
|   s     |  ---> Heap or internal SSO buffer
+---------+

Heap/Buffer:
+--------+
| '\0'   |
+--------+
So even an empty string uses at least 1 byte of memory for the null terminator.

✅ Why store the null terminator if it's not counted?
C++ strings are not required to be null-terminated for internal use, but they must be null-terminated when passed to C-style functions via .c_str().
Even though size() and length() do not count '\0', the null character is stored to ensure that:
    const char* cstr = s.c_str();

returns a valid C-style string.

This is for compatibility with C libraries and legacy APIs.

✅ So is '\0' stored in memory?
Yes, it is.
The null terminator ('\0') occupies 1 byte of memory, just like any other character.
It is automatically placed by the std::string implementation and is not visible to you via .size() or .length(), but it’s there for safe use with C-style functions.

✅ Then why does size() return 0 for an empty string?
Because std::string::size() is designed to return the number of actual visible characters in the string.
The null terminator ('\0') is treated as an implementation detail and excluded from the size count. So:
    std::string s = "";
    std::cout << s.size();  // Outputs 0

Even though '\0' is present behind the scenes.

✅ Does an empty string still take memory?
Yes, it does.
Even std::string s = "" uses memory to store at least the '\0' character:
Either in the heap, or
In an SSO (short string optimization) internal buffer on the stack.
In most implementations, this means an empty string still consumes 1 or more bytes.

✅ How does empty() work internally?
The empty() function is extremely simple. It just checks:
    return this->size() == 0;

It doesn't look at memory or check characters. Instead, it relies on a stored length variable, making it a fast and constant-time operation.


*/
