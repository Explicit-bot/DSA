/*
🔹 copy() – Copies characters to a C-style char array
✅ Syntax:
size_t copy(char* dest, size_t len, size_t pos = 0) const;
dest: Pointer to the destination char array.
len: Number of characters to copy.
pos: Starting index in the string (default is 0).
Returns: Actual number of characters copied.
⚠️ It does not null-terminate the destination. You must do it manually if needed.

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "RealMadrid";
    char dest[20];  // enough space

    size_t copied = s.copy(dest, 4, 0);  // Copy "Real"
    dest[copied] = '\0';  // Manual null-termination

    cout << "Copied: " << dest << endl;
}
/*
🟢 Output:
Copied: Real
🔸 MEMORY DIAGRAM:
For string s = "RealMadrid" and copy(dest, 4, 0);

less
Copy
Edit
s (std::string):   R  e  a  l  M  a  d  r  i  d
Index:             0  1  2  3  4  5  6  7  8  9

dest (char[]):     R  e  a  l  \0 ...
copy() copied first 4 characters into dest. We added \0 manually.

⚠️ Edge Cases:
✅ 1. pos beyond the string
    string s = "abc";
    char buf[5];
    s.copy(buf, 2, 10);  // undefined behavior or throws std::out_of_range

✅ 2. Requesting more than available
    string s = "hi";
    char buf[10];
    size_t n = s.copy(buf, 5, 0);  // Only 2 chars will be copied
    buf[n] = '\0';
    cout << buf << endl; // Output: hi

🧠 Use Cases:
Scenario	                                        Why Use copy()
Interfacing with legacy C libraries	                They expect char* 
                                                    instead of std::string

Partial extraction without creating a new string	More efficient in some cases

Buffer manipulations	                            You control where characters 
                                                    are copied

🚫 Common Pitfall:
    char arr[5];
    str.copy(arr, 5);    // ❌ No space for '\0'
    cout << arr;         // ❌ May print garbage or crash
✅ Always null-terminate manually!
*/
