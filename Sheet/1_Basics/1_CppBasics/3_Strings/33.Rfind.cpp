/*
🔹 rfind() — Find the last occurrence of a substring or character
✅ Syntax:
// Find last occurrence of a substring
size_t rfind(const string& str, size_t pos = npos) const;

// Find last occurrence of a character
size_t rfind(char ch, size_t pos = npos) const;

str or ch: What you're searching for.
pos: Start searching backward from this position (defaults to end).
Returns: Index of the last match ≤ pos, or string::npos if not found.

🔸 Basic Example
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "banana";

    size_t idx1 = s.rfind('a');        // Last 'a'
    size_t idx2 = s.rfind("na");       // Last "na"
    size_t idx3 = s.rfind("apple");    // Not found

    cout << "Last 'a': " << idx1 << endl;
    cout << "Last \"na\": " << idx2 << endl;

    if (idx3 == string::npos)
        cout << "\"apple\" not found\n";
}

/*
🟢 Output:
Last 'a': 5
Last "na": 4
"apple" not found

🔸 MEMORY DIAGRAM
For: string s = "banana"
Index:    0 1 2 3 4 5
String:   b a n a n a
                    ↑
              rfind('a') → 5 (rightmost 'a')

🔹 Using pos Parameter
    string s = "banana";
    size_t i1 = s.rfind('a');       // returns 5 (last 'a')
    size_t i2 = s.rfind('a', 3);    // start searching back from index 3 → returns 3

🟢 Output:
5 3

📝 So rfind('a', 3) finds the rightmost 'a' ≤ index 3.

🔸 Special Edge Cases
Case	Behavior
rfind("")	Returns size()
rfind("z")	Returns npos
rfind("ana")	Returns 3 (last "ana")
rfind("a", 0)	Only checks index 0
rfind("na", 1)	Will return npos (no "na" ≤ index 1)

🔹 Use Cases
-Find last delimiter
-File extension detection
    string file = "report.final.doc";
    size_t pos = file.rfind('.');
    cout << "Extension: " << file.substr(pos);  // ".doc"    
-Reversing substring behavior

✅ Summary
Feature             Description
rfind("sub")	    Finds last occurrence of "sub"
rfind('a')	        Finds last 'a'
rfind('a', 3)	    Finds last 'a' ≤ index 3
Not found	        Returns string::npos
rfind("")	        Returns size()
*/
