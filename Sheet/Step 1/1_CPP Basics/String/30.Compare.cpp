/*
🔹 compare() – Lexicographically compares two strings
✅ Syntax:
    int compare(const string& str) const;
    int compare(size_t pos, size_t len, const string& str) const;
    int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;

✅ Return Value:
0 → Both strings are equal.
< 0 → Calling string is less than the argument string.
> 0 → Calling string is greater than the argument string.

Comparison is lexicographical (dictionary order).


🧠 Memory Insight:
compare() does not modify memory.
Internally, it may iterate character-by-character.

🔹 Using substrings in compare
    string a = "Football";
    string b = "Foot";
    cout << a.compare(0, 4, b) << endl;  // Output: 0 (first 4 of a == b)

⚠️ Edge Cases:
Empty String Comparison:
    string s1 = "", s2 = "Hello";
    cout << s1.compare(s2) << endl;  // Output: -1

Out of Range Position:
    string s = "Hi";
    cout << s.compare(10, 2, "Hey");  // ❌ std::out_of_range

✅ Use Cases:
Use Case	                Example
Sorting	                    Custom sort based on compare result
Equality/Ordering	        Instead of ==, <, etc.
Efficient search	        Substring comparison without extracting

✅ Basic Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "Apple";
    string b = "Banana";

    cout << a.compare(b) << endl;   // Output: -1 (Apple < Banana)
    cout << b.compare(a) << endl;   // Output: 1  (Banana > Apple)
    cout << a.compare("Apple") << endl;  // Output: 0
}
