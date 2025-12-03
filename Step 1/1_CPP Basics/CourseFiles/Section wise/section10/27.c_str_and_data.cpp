/*
🔹 std::string::c_str()
✅ Purpose
Returns a read-only, null-terminated const char* version of the string.
Used when interacting with C-style functions that require a const char*.

✅ Syntax
    const char* c_str() const noexcept;

✅ Example: Basic Usage
#include <iostream>
#include <string>
#include <cstring>

int main() {
    std::string s = "RealMadrid";
    const char* cstr = s.c_str();

    std::cout << "String: " << s << "\n";
    std::cout << "Using c_str(): " << cstr << "\n";

    std::cout << "Length using strlen: " << strlen(cstr) << "\n";
    return 0;
}

✅ Output
String: RealMadrid
Using c_str(): RealMadrid
Length using strlen: 10

✅ Edge Case: Empty String
    std::string s = "";
    std::cout << "c_str(): [" << s.c_str() << "]\n";

✅ Output:
    c_str(): []
Still valid! It points to '\0'.

✅ Memory Diagram
If s = "Hi":

Index	Char	Notes
0	    'H'	    actual char
1	    'i'	    actual char
2	    '\0'	null terminator added by c_str()

🔹 std::string::data() (C++17 and above)
✅ Purpose
Returns a pointer to the underlying character buffer.
Like c_str() — but in C++20 and later, it's also null-terminated, and writable (if non-const).

✅ Syntax
// Const version (like c_str):
    const char* data() const noexcept;

// Writable version:
    char* data() noexcept;  // ⚠️ only available if string is non-const


✅ Edge Case: Read-Only Strings(const string can't be modified)
    const std::string s = "Madrid";
    std::cout << "First char (const): " << s.data()[0] << "\n";  // ✅ allowed
    // s.data()[0] = 'B'; ❌ Won’t compile (const)

Output:
First char (const): M
✅ Safe access but can't modify.




********************
The modifiable version of data() was introduced in C++20
// Writable version:
    char* data() noexcept;  // ⚠️ only available if string is non-const

✅ Example: Modifying with data()
    #include <iostream>
    #include <string>

    int main() {
        std::string s = "World";
        char* buffer = s.data();  // writable pointer

        buffer[0] = 'M';
        std::cout << "Modified string: " << s << "\n";

        return 0;
    }

✅ Output
Modified string: Morld
This shows data() allows direct modification of string characters!

✅ Memory Layout (after s = "World")
Index	Char
0	'W'
1	'o'
2	'r'
3	'l'
4	'd'
5	'\0'
*******************

*/
