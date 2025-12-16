/*
🔹 find() – Finds first occurrence of a substring or character
✅ Syntax:
// Find substring
size_t find(const string& str, size_t pos = 0) const;

// Find character
size_t find(char ch, size_t pos = 0) const;

str or ch: What you're searching for.
pos: (Optional) Start position of the search.
Returns: Index of first occurrence or string::npos if not found.

✅ Basic Examples:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "real madrid";

    size_t index1 = s.find("mad");
    size_t index2 = s.find('a');
    size_t index3 = s.find('z');

    cout << "Index of 'mad': " << index1 << endl;
    cout << "Index of 'a'  : " << index2 << endl;
    cout << "Index of 'z'  : ";
    if (index3 == string::npos)
        cout << "Not found\n";
}
/*
🟢 Output:
Index of 'mad': 5
Index of 'a'  : 1
Index of 'z'  : Not found

🔸 MEMORY DIAGRAM
For string s = "real madrid"
Index:     0 1 2 3 4 5 6 7 8 9 10
String:    r e a l   m a d r  i  d
                       ↑
                  find("mad") → index 5

🔹 Using pos Parameter
    string s = "banana";
    size_t i1 = s.find('a');        // Finds first 'a' → 1
    size_t i2 = s.find('a', 2);     // Skips to pos 2 → finds at index 3

    cout << i1 << " " << i2;  // 1 3

🔹 Finding Not Found Case
    string s = "hello";
    if (s.find("xyz") == string::npos)
        cout << "Not found!";

🟢 string::npos is a special constant representing "not found", usually -1 as an unsigned value (18446744073709551615 on 64-bit).

🔸 Edge Cases
Case	                    Behavior
find("")	                Always returns 0
find("xyz", 10) 	        If pos >= size(), returns npos
find("llo", 2)	            Returns 2
find("o", 5) on "hello"	    Returns npos

🧠 Use Cases
Substring search
Word matching
Efficient string scanning
Searching within specific ranges

✅ Summary
Property	        Explanation
find("abc")	        Finds "abc" and returns index
find('a')	        Finds first occurrence of char
find("xyz")	        Returns string::npos if not found
find("", pos)	    Returns pos
*/
